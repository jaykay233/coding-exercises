#include "threadpool.h"

#include <functional>
#include <thread>
#include <iostream>

const int TASK_MAX_THRESHHOLD = INT32_MAX;
const int THREAD_MAX_THRESHHOLD = 1024;
const int THREAD_MAX_IDLE_TIME = 60; // µ¥Î»£ºÃë

// Ïß³Ì³Ø¹¹Ôì
ThreadPool::ThreadPool()
	: initThreadSize_(0)
	, taskSize_(0)
	, idleThreadSize_(0)
	, curThreadSize_(0)
	, taskQueMaxThreshHold_(TASK_MAX_THRESHHOLD)
	, threadSizeThreshHold_(THREAD_MAX_THRESHHOLD)
	, poolMode_(PoolMode::MODE_FIXED)
	, isPoolRunning_(false)
{}

// Ïß³Ì³ØÎö¹¹
ThreadPool::~ThreadPool()
{
	isPoolRunning_ = false;
	
	// µÈ´ýÏß³Ì³ØÀïÃæËùÓÐµÄÏß³Ì·µ»Ø  ÓÐÁ½ÖÖ×´Ì¬£º×èÈû & ÕýÔÚÖ´ÐÐÈÎÎñÖÐ
	std::unique_lock<std::mutex> lock(taskQueMtx_);
	notEmpty_.notify_all();
	exitCond_.wait(lock, [&]()->bool {return threads_.size() == 0; });
}

// ÉèÖÃÏß³Ì³ØµÄ¹¤×÷Ä£Ê½
void ThreadPool::setMode(PoolMode mode)
{
	if (checkRunningState())
		return;
	poolMode_ = mode;
}

// ÉèÖÃtaskÈÎÎñ¶ÓÁÐÉÏÏßãÐÖµ
void ThreadPool::setTaskQueMaxThreshHold(int threshhold)
{
	if (checkRunningState())
		return;
	taskQueMaxThreshHold_ = threshhold;
}

// ÉèÖÃÏß³Ì³ØcachedÄ£Ê½ÏÂÏß³ÌãÐÖµ
void ThreadPool::setThreadSizeThreshHold(int threshhold)
{
	if (checkRunningState())
		return;
	if (poolMode_ == PoolMode::MODE_CACHED)
	{
		threadSizeThreshHold_ = threshhold;
	}
}

// ¸øÏß³Ì³ØÌá½»ÈÎÎñ    ÓÃ»§µ÷ÓÃ¸Ã½Ó¿Ú£¬´«ÈëÈÎÎñ¶ÔÏó£¬Éú²úÈÎÎñ
Result ThreadPool::submitTask(std::shared_ptr<Task> sp)
{
	// »ñÈ¡Ëø
	std::unique_lock<std::mutex> lock(taskQueMtx_);

	// Ïß³ÌµÄÍ¨ÐÅ  µÈ´ýÈÎÎñ¶ÓÁÐÓÐ¿ÕÓà   wait   wait_for   wait_until
	// ÓÃ»§Ìá½»ÈÎÎñ£¬×î³¤²»ÄÜ×èÈû³¬¹ý1s£¬·ñÔòÅÐ¶ÏÌá½»ÈÎÎñÊ§°Ü£¬·µ»Ø
	if (!notFull_.wait_for(lock, std::chrono::seconds(1),
		[&]()->bool { return taskQue_.size() < (size_t)taskQueMaxThreshHold_; }))
	{
		// ±íÊ¾notFull_µÈ´ý1sÖÖ£¬Ìõ¼þÒÀÈ»Ã»ÓÐÂú×ã
		std::cerr << "task queue is full, submit task fail." << std::endl;
		// return task->getResult();  // Task  Result   Ïß³ÌÖ´ÐÐÍêtask£¬task¶ÔÏó¾Í±»Îö¹¹µôÁË
		return Result(sp, false);
	}

	// Èç¹ûÓÐ¿ÕÓà£¬°ÑÈÎÎñ·ÅÈëÈÎÎñ¶ÓÁÐÖÐ
	taskQue_.emplace(sp);
	taskSize_++;

	// ÒòÎªÐÂ·ÅÁËÈÎÎñ£¬ÈÎÎñ¶ÓÁÐ¿Ï¶¨²»¿ÕÁË£¬ÔÚnotEmpty_ÉÏ½øÐÐÍ¨Öª£¬¸Ï¿ì·ÖÅäÏß³ÌÖ´ÐÐÈÎÎñ
	notEmpty_.notify_all();

	// cachedÄ£Ê½ ÈÎÎñ´¦Àí±È½Ï½ô¼± ³¡¾°£ºÐ¡¶ø¿ìµÄÈÎÎñ ÐèÒª¸ù¾ÝÈÎÎñÊýÁ¿ºÍ¿ÕÏÐÏß³ÌµÄÊýÁ¿£¬ÅÐ¶ÏÊÇ·ñÐèÒª´´½¨ÐÂµÄÏß³Ì³öÀ´
	if (poolMode_ == PoolMode::MODE_CACHED
		&& taskSize_ > idleThreadSize_
		&& curThreadSize_ < threadSizeThreshHold_)
	{
		std::cout << ">>> create new thread..." << std::endl;

		// ´´½¨ÐÂµÄÏß³Ì¶ÔÏó
		auto ptr = std::make_unique<Thread>(std::bind(&ThreadPool::threadFunc, this, std::placeholders::_1));
		int threadId = ptr->getId();
		threads_.emplace(threadId, std::move(ptr));
		// Æô¶¯Ïß³Ì
		threads_[threadId]->start(); 
		// ÐÞ¸ÄÏß³Ì¸öÊýÏà¹ØµÄ±äÁ¿
		curThreadSize_++;
		idleThreadSize_++;
	}

	// ·µ»ØÈÎÎñµÄResult¶ÔÏó
	return Result(sp);
	// return task->getResult();
}

// ¿ªÆôÏß³Ì³Ø
void ThreadPool::start(int initThreadSize)
{
	// ÉèÖÃÏß³Ì³ØµÄÔËÐÐ×´Ì¬
	isPoolRunning_ = true;

	// ¼ÇÂ¼³õÊ¼Ïß³Ì¸öÊý
	initThreadSize_ = initThreadSize;
	curThreadSize_ = initThreadSize;

	// ´´½¨Ïß³Ì¶ÔÏó
	for (int i = 0; i < initThreadSize_; i++)
	{
		// ´´½¨threadÏß³Ì¶ÔÏóµÄÊ±ºò£¬°ÑÏß³Ìº¯Êý¸øµ½threadÏß³Ì¶ÔÏó
		auto ptr = std::make_unique<Thread>(std::bind(&ThreadPool::threadFunc, this, std::placeholders::_1));
		int threadId = ptr->getId();
		threads_.emplace(threadId, std::move(ptr));
		// threads_.emplace_back(std::move(ptr));
	}

	// Æô¶¯ËùÓÐÏß³Ì  std::vector<Thread*> threads_;
	for (int i = 0; i < initThreadSize_; i++)
	{
		threads_[i]->start(); // ÐèÒªÈ¥Ö´ÐÐÒ»¸öÏß³Ìº¯Êý
		idleThreadSize_++;    // ¼ÇÂ¼³õÊ¼¿ÕÏÐÏß³ÌµÄÊýÁ¿
	}
}

// ¶¨ÒåÏß³Ìº¯Êý   Ïß³Ì³ØµÄËùÓÐÏß³Ì´ÓÈÎÎñ¶ÓÁÐÀïÃæÏû·ÑÈÎÎñ
void ThreadPool::threadFunc(int threadid)  // Ïß³Ìº¯Êý·µ»Ø£¬ÏàÓ¦µÄÏß³ÌÒ²¾Í½áÊøÁË
{
	auto lastTime = std::chrono::high_resolution_clock().now();

	// ËùÓÐÈÎÎñ±ØÐëÖ´ÐÐÍê³É£¬Ïß³Ì³Ø²Å¿ÉÒÔ»ØÊÕËùÓÐÏß³Ì×ÊÔ´
	for (;;)
	{
		std::shared_ptr<Task> task;
		{
			// ÏÈ»ñÈ¡Ëø
			std::unique_lock<std::mutex> lock(taskQueMtx_);

			std::cout << "tid:" << std::this_thread::get_id()
				<< "³¢ÊÔ»ñÈ¡ÈÎÎñ..." << std::endl;

			// cachedÄ£Ê½ÏÂ£¬ÓÐ¿ÉÄÜÒÑ¾­´´½¨ÁËºÜ¶àµÄÏß³Ì£¬µ«ÊÇ¿ÕÏÐÊ±¼ä³¬¹ý60s£¬Ó¦¸Ã°Ñ¶àÓàµÄÏß³Ì
			// ½áÊø»ØÊÕµô£¨³¬¹ýinitThreadSize_ÊýÁ¿µÄÏß³ÌÒª½øÐÐ»ØÊÕ£©
			// µ±Ç°Ê±¼ä - ÉÏÒ»´ÎÏß³ÌÖ´ÐÐµÄÊ±¼ä > 60s
			
			// Ã¿Ò»ÃëÖÐ·µ»ØÒ»´Î   ÔõÃ´Çø·Ö£º³¬Ê±·µ»Ø£¿»¹ÊÇÓÐÈÎÎñ´ýÖ´ÐÐ·µ»Ø
			// Ëø + Ë«ÖØÅÐ¶Ï
			while (taskQue_.size() == 0)
			{
				// Ïß³Ì³ØÒª½áÊø£¬»ØÊÕÏß³Ì×ÊÔ´
				if (!isPoolRunning_)
				{
					threads_.erase(threadid); // std::this_thread::getid()
					std::cout << "threadid:" << std::this_thread::get_id() << " exit!"
						<< std::endl;
					exitCond_.notify_all();
					return; // Ïß³Ìº¯Êý½áÊø£¬Ïß³Ì½áÊø
				}

				if (poolMode_ == PoolMode::MODE_CACHED)
				{
					// Ìõ¼þ±äÁ¿£¬³¬Ê±·µ»ØÁË
					if (std::cv_status::timeout ==
						notEmpty_.wait_for(lock, std::chrono::seconds(1)))
					{
						auto now = std::chrono::high_resolution_clock().now();
						auto dur = std::chrono::duration_cast<std::chrono::seconds>(now - lastTime);
						if (dur.count() >= THREAD_MAX_IDLE_TIME
							&& curThreadSize_ > initThreadSize_)
						{
							// ¿ªÊ¼»ØÊÕµ±Ç°Ïß³Ì
							// ¼ÇÂ¼Ïß³ÌÊýÁ¿µÄÏà¹Ø±äÁ¿µÄÖµÐÞ¸Ä
							// °ÑÏß³Ì¶ÔÏó´ÓÏß³ÌÁÐ±íÈÝÆ÷ÖÐÉ¾³ý   Ã»ÓÐ°ì·¨ threadFunc¡¶=¡·thread¶ÔÏó
							// threadid => thread¶ÔÏó => É¾³ý
							threads_.erase(threadid); // std::this_thread::getid()
							curThreadSize_--;
							idleThreadSize_--;

							std::cout << "threadid:" << std::this_thread::get_id() << " exit!"
								<< std::endl;
							return;
						}
					}
				}
				else
				{
					// µÈ´ýnotEmptyÌõ¼þ
					notEmpty_.wait(lock);
				}

				//if (!isPoolRunning_)
				//{
				//	threads_.erase(threadid); // std::this_thread::getid()
				//	std::cout << "threadid:" << std::this_thread::get_id() << " exit!"
				//		<< std::endl;
				//	exitCond_.notify_all();
				//	return; // ½áÊøÏß³Ìº¯Êý£¬¾ÍÊÇ½áÊøµ±Ç°Ïß³ÌÁË!
				//}
			}

			idleThreadSize_--;

			std::cout << "tid:" << std::this_thread::get_id()
				<< "»ñÈ¡ÈÎÎñ³É¹¦..." << std::endl;

			// ´ÓÈÎÎñ¶ÓÁÐÖÖÈ¡Ò»¸öÈÎÎñ³öÀ´
			task = taskQue_.front();
			taskQue_.pop();
			taskSize_--;

			// Èç¹ûÒÀÈ»ÓÐÊ£ÓàÈÎÎñ£¬¼ÌÐøÍ¨ÖªÆäËüµÃÏß³ÌÖ´ÐÐÈÎÎñ
			if (taskQue_.size() > 0)
			{
				notEmpty_.notify_all();
			}

			// È¡³öÒ»¸öÈÎÎñ£¬½øÐÐÍ¨Öª£¬Í¨Öª¿ÉÒÔ¼ÌÐøÌá½»Éú²úÈÎÎñ
			notFull_.notify_all();
		} // ¾ÍÓ¦¸Ã°ÑËøÊÍ·Åµô
		
		// µ±Ç°Ïß³Ì¸ºÔðÖ´ÐÐÕâ¸öÈÎÎñ
		if (task != nullptr)
		{
			// task->run(); // Ö´ÐÐÈÎÎñ£»°ÑÈÎÎñµÄ·µ»ØÖµsetVal·½·¨¸øµ½Result
			task->exec();
		}
		
		idleThreadSize_++;
		lastTime = std::chrono::high_resolution_clock().now(); // ¸üÐÂÏß³ÌÖ´ÐÐÍêÈÎÎñµÄÊ±¼ä
	}
}

bool ThreadPool::checkRunningState() const
{
	return isPoolRunning_;
}

////////////////  Ïß³Ì·½·¨ÊµÏÖ
int Thread::generateId_ = 0;

// Ïß³Ì¹¹Ôì
Thread::Thread(ThreadFunc func)
	: func_(func)
	, threadId_(generateId_++)
{}

// Ïß³ÌÎö¹¹
Thread::~Thread() {}

// Æô¶¯Ïß³Ì
void Thread::start()
{
	// ´´½¨Ò»¸öÏß³ÌÀ´Ö´ÐÐÒ»¸öÏß³Ìº¯Êý pthread_create
	std::thread t(func_, threadId_);  // C++11À´Ëµ Ïß³Ì¶ÔÏót  ºÍÏß³Ìº¯Êýfunc_
	t.detach(); // ÉèÖÃ·ÖÀëÏß³Ì   pthread_detach  pthread_tÉèÖÃ³É·ÖÀëÏß³Ì
}

int Thread::getId()const
{
	return threadId_;
}


/////////////////  Task·½·¨ÊµÏÖ
Task::Task()
	: result_(nullptr)
{}

void Task::exec()
{
	if (result_ != nullptr)
	{
		result_->setVal(run()); // ÕâÀï·¢Éú¶àÌ¬µ÷ÓÃ
	}
}

void Task::setResult(Result* res)
{
	result_ = res;
}

/////////////////   Result·½·¨µÄÊµÏÖ
Result::Result(std::shared_ptr<Task> task, bool isValid)
	: isValid_(isValid)
	, task_(task)
{
	task_->setResult(this);
}

Any Result::get() // ÓÃ»§µ÷ÓÃµÄ
{
	if (!isValid_)
	{
		return "";
	}
	sem_.wait(); // taskÈÎÎñÈç¹ûÃ»ÓÐÖ´ÐÐÍê£¬ÕâÀï»á×èÈûÓÃ»§µÄÏß³Ì
	return std::move(any_);
}

void Result::setVal(Any any)  // Ë­µ÷ÓÃµÄÄØ£¿£¿£¿
{
	// ´æ´¢taskµÄ·µ»ØÖµ
	this->any_ = std::move(any);
	sem_.post(); // ÒÑ¾­»ñÈ¡µÄÈÎÎñµÄ·µ»ØÖµ£¬Ôö¼ÓÐÅºÅÁ¿×ÊÔ´
}