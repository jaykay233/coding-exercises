#include <iostream>
using namespace std;

//终止递归写在前面
template <typename T>
void myfunct2(const T& firstarg)
{
    cout<<"参数包展开时执行了递归终止函数myfunct2()"<<endl;
    return;
}

template <typename T,typename ...U>
void myfunct2(const T& firstarg, const U& ...otherargs){
    cout<<"参数值为: "<<firstarg << endl;
    myfunct2(otherargs...);
}


int main(){
    myfunct2(10,"abc",12.7);
    return 0;
}