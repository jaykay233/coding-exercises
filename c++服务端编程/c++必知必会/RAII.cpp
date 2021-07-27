//资源获取即初始化
class SomeLockGuard{
public:  
    SomeLockGuard(){
        m_lock.lock();
    }
    ~SomeLockGuard(){
        m_lock.unlock();
    }
private:
    SomeLock m_lock;
};

void SomeFunction(){
    SomeLockGuard lockWrapper;
    if(condition1){
        if(condition2){
            operation1();
            return;
        }
        else if(condition3){
            operation2();
            return;
        }
    }
    if(condition3){
        operation3();
        return;
    }
}