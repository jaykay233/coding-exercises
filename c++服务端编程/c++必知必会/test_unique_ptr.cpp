#include <bits/stdc++.h>
using namespace std;
template<typename T, typename Deletor>
class unique_ptr{
public:  
    unique_ptr(unique_ptr&& rhs){
        this->m_pT = rhs.mpT;
        rhs.m_pT = nullptr;
    }

    unique_ptr& operator=(unique_ptr&& rhs){
        this->m_pT = rhs.m_pT;
        rhs.m_pT = nullptr;
        return *this;
    }
private:  
    T* m_pT;
};

class Socket{
public:  
    Socket(){}
    ~Socket(){}
    
}

int main(){


    return 0;
}