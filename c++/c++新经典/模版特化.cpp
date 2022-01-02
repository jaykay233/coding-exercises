#include <iostream>
using namespace std;

template<typename T,typename U>
struct TC{
    TC()
    {
        cout<<"TC泛化版本构造"<<endl;
    }
    void functest()
    {
        cout<<"TC泛化版本"<<endl;
    }
};

template<>
struct TC<int,int> 
{
    TC()
    {
        cout<<"TC<int,int>特话版本构造函数"<<endl;
    }
    void functest(){
        cout<<"TC<int,int>特化版本"<<endl;
    }
};

template<typename ...T>
void myfunct1(T... args){
    cout<<sizeof...(args)<<endl;
    cout<<sizeof...(T)<<endl;
}