#include <iostream>
using namespace std;

class Test
{
public:
    Test(int a = 10) : ma(a) { cout << "Test()" << endl; }
    ~Test() { cout << "~Test()" << endl; }
    Test(const Test &t) : ma(t.ma) { cout << "Test(const Test&)" << endl; }
    Test &operator=(const Test &t)
    {
        cout << "operator=" << endl;
        ma = t.ma;
        return *this;
    }

private:
    int ma;
};

int main()
{
    Test t1;
    Test t2(t1); // 拷贝构造
    Test t3 = t1; // 拷贝构造，t3正在定义，所以拷贝构造
    //显式生成临时对象
    // c++编译器对于对象构造的优化，临时对象生成新对象的时候，临时对象就不产生了，直接构造新对象
    Test t4 = Test(20);

    t4 = t2; //赋值运算符重载
    // t4.operator=(const Test& t)

    //这三个一样，都生成临时对象，然后调用赋值函数
    t4 = Test(30); //生成临时对象，然后赋值
    t4 = (Test)30; //整数强转成30，int->Test(int), char* -> Test(char*) 
    
    //隐式生成临时对象
    t4 = 30; 

    cout << "--------------" << endl;
    //指针指向临时对象不安全，临时对象出了语句就析构
    Test* p = &Test(40);
    //引用临时对象之后生命周期就变成了引用的生命周期
    Test &ref = Test(50);
    cout << "--------------" << endl;


    return 0;
}