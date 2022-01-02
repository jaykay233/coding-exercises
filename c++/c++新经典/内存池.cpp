class A{
public:  
    static void* operator new(size_t size);
    static void operator delete(void* phead);
    static int m_iCount;
    static int m_iMallocCount;
private: 
    A* next;
    static A* m_FreePosi;
    static int m_sTrunkCount;
};

void* A::operator new(size_t size){
    A* tmplink;
    if(m_FreePosi == nullptr){
        size_t realsize = m_sTrunkCount * size;
        m_FreePosi = reinterpret_cast<A*>(new char[realsize]);
        tmplink = m_FreePosi;
        for(;tmplink!=&m_FreePosi[m_sTrunkCount-1];++tmplink)
        {
            tmplink->next = tmplink + 1;
        }
        tmplink->next =nullptr;
        ++m_iMallocCount;
    }
    tmplink = m_FreePosi;
    m_FreePosi = m_FreePosi->next;
    ++m_iCount;
    return tmplink;
}


void A::operator delete(void* phead){
    (static_cast<A*>(phead))->next = m_FreePosi;
    m_FreePosi = static_cast<A*>(phead);
}

int A::m_iCount =0 ;
int A::m_iMallocCount = 0;

A* A::m_FreePosi = nullptr;
int A::m_sTrunkCount = 5;