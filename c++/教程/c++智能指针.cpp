#include <iostream>
#include <memory>
using namespace std;

//对资源进行引用计数的类
template <typename T>
class RefCnt
{
public:
    RefCnt(T *ptr = nullptr) : mptr(ptr)
    {
        if (mptr != nullptr)
            mcount = 1;
    }

    void addRef() { mCount++; } //添加引用计数

    int delRef() { mCount--;}

private:
    T *mptr;
    int mcount;
};

//智能指针，保证能做到资源的自动释放！
//利用栈上的对象出作用域自动析构的特征，来做到资源的自动释放
//智能指针能不能定义在堆上？
// CSmartPtr<int> *p = new CSmartPtr<int>(new int);
template <typename T>
class CSmartPtr
{
public:
    CSmartPtr(T *ptr = nullptr) : mptr(ptr)
    {
        mpRefCnt = new RefCnt<T>(mptr);
    }
    ~CSmartPtr()
    {
        if(0 == mpRefCnt->delRef())
        {
            delete mptr;
            mptr = nullptr;
        }
    }

    T &operator*() { return *mptr; }
    T *operator->() { return mptr; }

    CSmartPtr(const CSmartPtr<T> &src) : mptr(src.mptr), mpRefCnt(src.mpRefCnt)
    {
        if (mptr != nullptr)
            mpRefCnt->addRef();
    }

    CSmartPtr<T>& operator=(const CSmartPtr<T>& src)
    {
        if(this == &src)
            return *this;
        if(mpRefCnt->delRef() == 0)
        {
            delete mptr;
        }

        mptr = src.mptr;
        mpRefCnt = src.mpRefCnt;
        mpRefCnt->addRef();
        return *this;
    }

private:
    T *mptr;          //指向资源的指针
    RefCnt<T> *mpRefCnt; //指向该资源引用计数的指针
};

class A
{
    public: 
        A() {cout << "A()" << endl;}
        ~A() {cout << "~A()" << endl;}
        shared_ptr<B> _ptrb;
};

class B
{
    public: 
        B() {cout << "B()" << endl;}
        ~B() {cout << "~B()" << endl;}
        shared_ptr<A> _ptra;
};

// int main()
// {
//     /*
//         不带引用计数的智能指针
//         auto_ptr: C++库里面
//         C++11新标准:
//         scoped_ptr
//         unique_ptr
//     */

//     auto_ptr<int> ptr1(new int);
//     auto_ptr<int> ptr2(ptr1);

//     /*
//     autoptr总是交给最后一个指针，容器不推荐使用autoptr，
//     因为容器的拷贝构造会引起容器内所有元素的拷贝构造
//     转移对象的所有权

//     scoped_ptr没有拷贝构造和赋值操作，基本上来说使用的也比较少

//     推荐使用
//     unique_ptr
//     unique_ptr拷贝构造和赋值操作也被禁止,但是提供右值引用
//     unique_ptr(unique_ptr<T>&& src)
//     unique_ptr<T>& operator=(unique_ptr<T>&& src)
//     std::move(ptr) => 右值引用
//     */
//     *ptr2 = 20;
//     cout << *ptr1 << endl;

//     /*
//     带引用计数的智能指针shared_ptr和weak_ptr
//     带引用计数：多个智能指针可以管理同一资源
//     带引用计数：给每一个对象资源，匹配一个引用计数
//     智能指针 =》资源的时候 =》引用计数 + 1
//     智能指针 =》不使用引用资源 =》引用计数 - 1 =》！= 0，0资源释放了

//     */

    

//     return 0;
// }

template<typename T> 
class MyDeletor
{
public: 
    void seperator(T* ptr) const 
    {
        delete[] ptr;
    }
};



int main()
{
    shared_ptr<A> pa(new A());
    shared_ptr<B> pb(new B());

    cout << pa.use_count() << endl;
    cout << pb.use_count() << endl;

    return 0;
}