#include <iostream>
#include <cstdio>
using namespace std;

class Test
{
public: 
    Test(int a) {cout << "Test(int)" << endl;}
    Test(int a,int b) { cout << "Test(int,int)" << endl;}
    ~Test() {cout << "~Test()" << endl;}
    Test(const Test&) { cout << "Test(const Test&)" << endl;}
    Test(Test&& ) {cout << "Test(Test&&)" << endl;}
};



template<typename T>
struct MyAllocator
{
    // allocate deallocate
    // construct destroy
    T* allocate(size_t size)
    {
        return (T*)malloc(size * sizeof(T));
    }

    template<typename... Types>
    void construct(T* ptr, Types&&... args)
    {
        new (ptr) T(std::forward<Types>(args)...);
    }
};

template<typename T, typename Alloc = MyAllocator<T>>
class Vector
{
public:
    Vector(): vec_(nullptr), size_(0), idx_(0) {}
    void reserve(size_t size)
    {
        vec_ = alloactor_.allocate(size);
        size_ = size;
    }
    // // push_back
    // void push_back(const T& val)
    // {
    //     alloactor_.construct(vec_ + idx_, val);
    //     idx_ ++;
    // }

    // // push_back
    // void push_back(T&& val)
    // {
    //     // 
    //     alloactor_.construct(vec_+idx_, std::move(val));
    //     idx_++;
    // }

    template<typename Type>
    void push_back(Type&& val)
    {
        alloactor_.construct(vec_ + idx_, std::forward<Type>(val));
        idx_ ++ ;
    }

    // 1.引用折叠 实参：左值
    template<typename... Types>
    void emplace_back(Types&&... args)
    {
        //不管是左值应用，右值引用变量，它本身是个左值函数
        alloactor_.construct(vec_ + idx_, std::forward<Types>(args)...);
        idx_ ++;
    }
private:
    T* vec_;
    int size_;
    int idx_;
    Alloc alloactor_;
};

int main()
{
    Test t1(10);
    Vector<Test> v;
    v.reserve(100);

    cout << "===========" << endl;
    v.push_back(t1);
    v.emplace_back(t1);
    cout << "===========" << endl;
    v.push_back(Test(20));
    v.emplace_back(Test(20));
    cout << "===========" << endl;
    v.emplace_back(20);
    v.emplace_back(30,40);
    cout << "===========" << endl;

    return 0;
}