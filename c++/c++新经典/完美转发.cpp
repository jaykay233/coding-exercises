#include <iostream>
#include <cstdio>
using namespace std;

void printInfo(int& t)
{
    cout<<"PrintT()参数类型为左值引用"<<endl;
}

void printInfo(int&& t)
{
    cout<<"PrintT()参数类型为右值引用"<<endl;
}

template<typename T>
void TestF(T&& t)
{
    cout<<"-------------begin--------------" << endl;
    
    printInfo(t);
    printInfo(std::forward<T>(t));
    printInfo(std::move(t));
}

int main(){



    return 0;
}