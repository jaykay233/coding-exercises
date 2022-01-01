#ifndef __MYVECTOR__
#define __MYVECTOR__

template<typename T>
class myvector
{
    public:
        typedef T * myiterator;
    public:
        myvector();
        myvector& operator = (const myvector&);
    public: 
        myiterator mybegin();
        myiterator myend();
    public:
        void myfunc();
};

#endif