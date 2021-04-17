#include <boost>
#include <pthread.h>
#include <cassert>
using namespace std;
class MutexLock: boost::noncopyable{
    public: MutexLock():holder_(0){
        pthread_mutex_init(&mutex_,nullptr);
    }

    ~MutexLock(){
        assert(holder_ == 0);
        pthread_mutex_destroy(&mutex_);
    }

    bool isLockedByThisThread(){
        return holder_ == currentThread::tid();
    }

    void assertLocked(){
        assert(isLockedByThisThread());
    }

    void lock(){
        pthread_mutex_lock(&mutex_);
        holder_ = CurrentThread::tid();
    }

    void unlock(){
        holder_ = 0;
        pthread_mutex_unlock(&mutex_);
    }

    pthread_mutex_t* getPthreadMutex(){
        return &mutex_;
    }

    private:
        pthread_mutex_t mutex_;
        pid_t holder_;
};

class MutexLockGuard: boost::noncopyable{
    public:  
    explicit MutexLockGuard(MutexLock& mutex):mutex_(mutex){
        mutex_.lock();
    }
    ~MutexLockGuard(){
        mutex_.unlock();
    }
    private:
    MutexLock& mutex_;
};

class Condition : boost::noncopyable{
public:  
    explicit Condition(MutexLock& mutex):mutex_(mutex){
        pthread_cond_init(&pcond_,nullptr);
    }
    ~Condition(){
        pthread_cond_destroy(&pcond_);
    }
    void wait(){
        pthread_cond_wait(&pcond_,mutex_.getPthreadMutex());
    }
    void notify(){
        pthread_cond_signal(&pcond_);
    }
    void notify_all(){
        pthread_cond_broadcast(&pcond_);
    }
    private:
    MutexLock& mutex_;
    pthread_cond_t pcond_;
};

class CountDownLatch{
    public: CountDownLatch(int count):mutex_{
        condition_(mutex_);
        count_(count);
    }
    private:
        mutable MutexLock mutex_;
        Condition condition_;
        int count_;
};

