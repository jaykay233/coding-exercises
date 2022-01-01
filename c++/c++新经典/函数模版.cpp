#include <iostream>
using namespace std;

template <typename T>
T funcadd(T a, T b)
{
    T addhe = a + b;
    return addhe;
}

template<unsigned L1, unsigned L2>
int charscomp(char const (&p1)[L1], char const (&p2)[L2])
{
    return strcmp(p1,p2);
}

int main(){
    float he = funcadd((float)2,1.3f);
    cout<<he<<endl;
    int result = charscomp("test2","test");
    cout<<result<<endl;
    return 0;
}