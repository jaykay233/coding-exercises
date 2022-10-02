#include <iostream>
#include <string>
#include <functional>
#include <thread>
#include <vector>

using namespace std;

void hello(string str) { cout << str << endl; }

int sum(int a, int b)
{
    return a + b;
}

template <typename Fty>
class myfunction
{
};

// template <typename R, typename A1>
// class myfunction<R(A1)>
// {
// public:
//     // typedef R (*PFUNC)(A1);
//     using PFUNC = R (*)(A1);
//     myfunction(PFUNC pfunc) : _pfunc(pfunc) {}
//     R operator()(A1 arg)
//     {
//         return _pfunc(arg);
//     }

// private:
//     PFUNC _pfunc;
// };

// template<typename R, typename A1, typename A2>
// class myfunction<R(A1,A2)>
// {
// public:
//     using PFUNC = R(*)(A1,A2);
//     myfunction(PFUNC pfunc) : _pfunc(pfunc) {}
//     R operator()(A1 arg1, A2 arg2)
//     {
//         return _pfunc(arg1, arg2);
//     }
// private:
//     PFUNC _pfunc;
// };

//表示可变参数
template <typename R, typename... A>
class myfunction<R(A...)>
{
public:
    using PFUNC = R (*)(A...);
    myfunction(PFUNC pfunc) : _pfunc(pfunc) {}
    R operator()(A... arg)
    {
        return _pfunc(arg...);
    }

private:
    PFUNC _pfunc;
};

template <typename T>
bool compare(T a, T b)
{
    cout << "template compare" << endl;
    return a > b;
}

//这个就是完全特例化，因为参数都完全确定了
template <>
bool compare<const char *>(const char *a, const char *b)
{
    cout << "template<const char*> compare" << endl;
    return strcmp(a, b) > 0;
};

template <typename T>
class Vector
{
public:
    Vector() { cout << "call Vector template init" << endl; }
};

template <>
class Vector<char *>
{
public:
    Vector() { cout << "call Vector<char*> init" << endl; }
};

template <typename Ty>
class Vector<Ty *>
{
public:
    Vector() { cout << "call Vector<Ty*> init" << endl; }
};

template <typename R, typename A1, typename A2>
class Vector<R (*)(A1, A2)>
{
public:
    Vector() { cout << "call Vector<R(*)(A1,A2)> init" << endl; }
};

template <typename T>
void func(T a)
{
    cout << typeid(T).name() << endl;
}

void hello1()
{
    cout << "hello world!" << endl;
}

void hello2(string str)
{
    cout << str << endl;
}

class Thread
{
public: 
    Thread(function<void()> func) : _func(func) {}
    thread start()
    {
        thread t(_func);
        return t;
    }
private: 
    function<void()> _func;
};


class ThreadPool
{
public: 
    ThreadPool() {}
    ~ThreadPool() {
        for(int i =0;i<_pool.size();i++)
        {
            delete _pool[i];
        }
    }

    void startPool(int size)
    {
        for(int i =0;i<size; i++)
        {
            _pool.push_back(new Thread(bind(&ThreadPool::runInThread, this, i)));
        }
        for(int i =0;i<size;i++)
        {
           _handler.push_back(_pool[i]->start());
        }
        for(thread& t:_handler)
        {
            t.join();
        }
    }
private: 
    vector<Thread*> _pool;
    vector<thread> _handler;
    void runInThread(int id)
    {
        cout << "call runInThread! id:" << id << endl;
    }
};


int main()
{
    // function<void(string)> func1(hello);
    // func1("hello world!");

    // myfunction<int(int,int)> func2(sum);
    // cout <<func2(10,20) << endl;

    // compare(10,20);
    // compare("aa","bb");

    // Vector<int> vec1;
    // Vector<char *> vec2;

    // typedef int (*PFUNC1)(int, int);
    // PFUNC1 pfunc1 = sum;
    // cout << pfunc1(10, 20) << endl;

    // typedef int(PFUNC2)(int, int);
    // PFUNC2 *pfunc2 = sum;
    // cout << (*pfunc2)(10, 20) << endl;

    // func(10);
    // func("aaa");
    // func(sum);

    // function<void()> func1 = hello1;
    // func1();

    // function<void(string)> func2 = hello2;
    // func2("hello2");

    ThreadPool pool;
    pool.startPool(10);
    return 0;
}