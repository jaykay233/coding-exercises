#include <iostream>
#include <new>

void* operator new(size_t size)
{
    void *p = malloc(size);
    if (p == nullptr)
        throw bad_alloc();
    return p;
}

void operator delete(void *ptr)
{
    free(ptr);
}

class Test
{
public: 
    Test(int data=10):ptr(new int(data)) { cout << "Test()" << endl;}
    ~Test() { cout << "~Test()" << endl;}
private: 
    int *ptr;
}


int main(){


#if 0
    try
    {
         int *p = new int ;
         delete p;
    }
    catch (const bad_alloc &err) 
    {
        cerr << err.what() << endl;
    }
    return 0;
#endif 
}