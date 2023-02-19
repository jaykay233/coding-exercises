#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <vector>
#include <queue>
#include <memory>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <unordered_map>

// AnyÀàÐÍ£º¿ÉÒÔ½ÓÊÕÈÎÒâÊý¾ÝµÄÀàÐÍ
class Any
{
public:
	Any() = default;
	~Any() = default;
	Any(const Any&) = delete;
	Any& operator=(const Any&) = delete;
	Any(Any&&) = default;
	Any& operator=(Any&&) = default;

	// Õâ¸ö¹¹Ôìº¯Êý¿ÉÒÔÈÃAnyÀàÐÍ½ÓÊÕÈÎÒâÆäËüµÄÊý¾Ý
	template<typename T>  // T:int    Derive<int>
	Any(T data) : base_(std::make_unique<Derive<T>>(data))
	{}

	// Õâ¸ö·½·¨ÄÜ°ÑAny¶ÔÏóÀïÃæ´æ´¢µÄdataÊý¾ÝÌáÈ¡³öÀ´
	template<typename T>
	T cast_()
	{
		// ÎÒÃÇÔõÃ´´Óbase_ÕÒµ½ËüËùÖ¸ÏòµÄDerive¶ÔÏó£¬´ÓËüÀïÃæÈ¡³ödata³ÉÔ±±äÁ¿
		// »ùÀàÖ¸Õë =¡· ÅÉÉúÀàÖ¸Õë   RTTI
		Derive<T>* pd = dynamic_cast<Derive<T>*>(base_.get());
		if (pd == nullptr)
		{
			throw "type is unmatch!";
		}
		return pd->data_;
	}
private:
	// »ùÀàÀàÐÍ
	class Base
	{
	public:
		virtual ~Base() = default;
	};

	// ÅÉÉúÀàÀàÐÍ
	template<typename T>
	class Derive : public Base
	{
	public:
		Derive(T data) : data_(data) 
		{}
		T data_;  // ±£´æÁËÈÎÒâµÄÆäËüÀàÐÍ
	};

private:
	// ¶¨ÒåÒ»¸ö»ùÀàµÄÖ¸Õë
	std::unique_ptr<Base> base_;
};

// ÊµÏÖÒ»¸öÐÅºÅÁ¿Àà
class Semaphore
{
public:
	Semaphore(int limit = 0) 
		:resLimit_(limit)
	{}
	~Semaphore() = default;

	// »ñÈ¡Ò»¸öÐÅºÅÁ¿×ÊÔ´
	void wait()
	{
		std::unique_lock<std::mutex> lock(mtx_);
		// µÈ´ýÐÅºÅÁ¿ÓÐ×ÊÔ´£¬Ã»ÓÐ×ÊÔ´µÄ»°£¬»á×èÈûµ±Ç°Ïß³Ì
		cond_.wait(lock, [&]()->bool {return resLimit_ > 0; });
		resLimit_--;
	}

	// Ôö¼ÓÒ»¸öÐÅºÅÁ¿×ÊÔ´
	void post()
	{
		std::unique_lock<std::mutex> lock(mtx_);
		resLimit_++;
		// linuxÏÂcondition_variableµÄÎö¹¹º¯ÊýÊ²Ã´Ò²Ã»×ö
		// µ¼ÖÂÕâÀï×´Ì¬ÒÑ¾­Ê§Ð§£¬ÎÞ¹Ê×èÈû
		cond_.notify_all();  // µÈ´ý×´Ì¬£¬ÊÍ·ÅmutexËø Í¨ÖªÌõ¼þ±äÁ¿waitµÄµØ·½£¬¿ÉÒÔÆðÀ´¸É»îÁË
	}
private:
	int resLimit_;
	std::mutex mtx_;
	std::condition_variable cond_;
};

// TaskÀàÐÍµÄÇ°ÖÃÉùÃ÷
class Task;

// ÊµÏÖ½ÓÊÕÌá½»µ½Ïß³Ì³ØµÄtaskÈÎÎñÖ´ÐÐÍê³ÉºóµÄ·µ»ØÖµÀàÐÍResult
class Result
{
public:
	Result(std::shared_ptr<Task> task, bool isValid = true);
	~Result() = default;

	// ÎÊÌâÒ»£ºsetVal·½·¨£¬»ñÈ¡ÈÎÎñÖ´ÐÐÍêµÄ·µ»ØÖµµÄ
	void setVal(Any any);

	// ÎÊÌâ¶þ£ºget·½·¨£¬ÓÃ»§µ÷ÓÃÕâ¸ö·½·¨»ñÈ¡taskµÄ·µ»ØÖµ
	Any get();
private:
	Any any_; // ´æ´¢ÈÎÎñµÄ·µ»ØÖµ
	Semaphore sem_; // Ïß³ÌÍ¨ÐÅÐÅºÅÁ¿
	std::shared_ptr<Task> task_; //Ö¸Ïò¶ÔÓ¦»ñÈ¡·µ»ØÖµµÄÈÎÎñ¶ÔÏó 
	std::atomic_bool isValid_; // ·µ»ØÖµÊÇ·ñÓÐÐ§
};

// ÈÎÎñ³éÏó»ùÀà
class Task
{
public:
	Task();
	~Task() = default;
	void exec();
	void setResult(Result* res);

	// ÓÃ»§¿ÉÒÔ×Ô¶¨ÒåÈÎÒâÈÎÎñÀàÐÍ£¬´ÓTask¼Ì³Ð£¬ÖØÐ´run·½·¨£¬ÊµÏÖ×Ô¶¨ÒåÈÎÎñ´¦Àí
	virtual Any run() = 0;

private:
	Result* result_; // Result¶ÔÏóµÄÉùÃ÷ÖÜÆÚ ¡· TaskµÄ
};

// Ïß³Ì³ØÖ§³ÖµÄÄ£Ê½
enum class PoolMode
{
	MODE_FIXED,  // ¹Ì¶¨ÊýÁ¿µÄÏß³Ì
	MODE_CACHED, // Ïß³ÌÊýÁ¿¿É¶¯Ì¬Ôö³¤
};

// Ïß³ÌÀàÐÍ
class Thread
{
public:
	// Ïß³Ìº¯Êý¶ÔÏóÀàÐÍ
	using ThreadFunc = std::function<void(int)>;

	// Ïß³Ì¹¹Ôì
	Thread(ThreadFunc func);
	// Ïß³ÌÎö¹¹
	~Thread();
	// Æô¶¯Ïß³Ì
	void start();

	// »ñÈ¡Ïß³Ìid
	int getId()const;
private:
	ThreadFunc func_;
	static int generateId_;
	int threadId_;  // ±£´æÏß³Ìid
};

/*
example:
ThreadPool pool;
pool.start(4);

class MyTask : public Task
{
	public:
		void run() { // Ïß³Ì´úÂë... }
};

pool.submitTask(std::make_shared<MyTask>());
*/
// Ïß³Ì³ØÀàÐÍ
class ThreadPool
{
public:
	// Ïß³Ì³Ø¹¹Ôì
	ThreadPool();

	// Ïß³Ì³ØÎö¹¹
	~ThreadPool();

	// ÉèÖÃÏß³Ì³ØµÄ¹¤×÷Ä£Ê½
	void setMode(PoolMode mode);

	// ÉèÖÃtaskÈÎÎñ¶ÓÁÐÉÏÏßãÐÖµ
	void setTaskQueMaxThreshHold(int threshhold);

	// ÉèÖÃÏß³Ì³ØcachedÄ£Ê½ÏÂÏß³ÌãÐÖµ
	void setThreadSizeThreshHold(int threshhold);

	// ¸øÏß³Ì³ØÌá½»ÈÎÎñ
	Result submitTask(std::shared_ptr<Task> sp);

	// ¿ªÆôÏß³Ì³Ø
	void start(int initThreadSize = 4);

	ThreadPool(const ThreadPool&) = delete;
	ThreadPool& operator=(const ThreadPool&) = delete;

private:
	// ¶¨ÒåÏß³Ìº¯Êý
	void threadFunc(int threadid);

	// ¼ì²époolµÄÔËÐÐ×´Ì¬
	bool checkRunningState() const;

private:
	// std::vector<std::unique_ptr<Thread>> threads_; // Ïß³ÌÁÐ±í
	std::unordered_map<int, std::unique_ptr<Thread>> threads_; // Ïß³ÌÁÐ±í

	int initThreadSize_;  // ³õÊ¼µÄÏß³ÌÊýÁ¿
	int threadSizeThreshHold_; // Ïß³ÌÊýÁ¿ÉÏÏÞãÐÖµ
	std::atomic_int curThreadSize_;	// ¼ÇÂ¼µ±Ç°Ïß³Ì³ØÀïÃæÏß³ÌµÄ×ÜÊýÁ¿
	std::atomic_int idleThreadSize_; // ¼ÇÂ¼¿ÕÏÐÏß³ÌµÄÊýÁ¿

	std::queue<std::shared_ptr<Task>> taskQue_; // ÈÎÎñ¶ÓÁÐ
	std::atomic_int taskSize_; // ÈÎÎñµÄÊýÁ¿
	int taskQueMaxThreshHold_;  // ÈÎÎñ¶ÓÁÐÊýÁ¿ÉÏÏÞãÐÖµ

	std::mutex taskQueMtx_; // ±£Ö¤ÈÎÎñ¶ÓÁÐµÄÏß³Ì°²È«
	std::condition_variable notFull_; // ±íÊ¾ÈÎÎñ¶ÓÁÐ²»Âú
	std::condition_variable notEmpty_; // ±íÊ¾ÈÎÎñ¶ÓÁÐ²»¿Õ
	std::condition_variable exitCond_; // µÈµ½Ïß³Ì×ÊÔ´È«²¿»ØÊÕ

	PoolMode poolMode_; // µ±Ç°Ïß³Ì³ØµÄ¹¤×÷Ä£Ê½
	std::atomic_bool isPoolRunning_; // ±íÊ¾µ±Ç°Ïß³Ì³ØµÄÆô¶¯×´Ì¬
};

#endif
