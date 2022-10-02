#include <iostream>

//定义容器的空间配置器，和C++标准库的allocator实现一样
template<typename T>
class Allocator
{
    T* allocator(size_t size, const Alloc &alloc=Allocator<T>()) //负责内存开辟
    {
        return (T*)malloc(sizeof(T) * size);
    }

    void deallocate(void* p) //负责内存释放
    {
        free(p);
    }

    void construct(T* p, const T& val)
    {
        //定位new 指定内存上
        new (p) T(val); //定位new
    }

    void destroy(T *p) //负责对象析构
    {
        p->~T(); // ~T()代表了T类型的析构函数
    }
};

//容器底层内存开辟，内存释放，对象构造和析构，都通过allocator空间配置器来实现
template<typename T,  typename Alloc = Allocator<T>>
class vector
{
public:
    vector(int size=10)
    {
        _first = _allocator.allocate(size);
        _last = _first;
        _end = _first + size;
    }
    ~vector()
    {
        // delete []_first;
        for(T *p = _first; p!=_last;++p)
        {
            _allocator.destroy(p);
        }
        _allocator.deallocate(_first);
        _first = _last = _end = nullptr;
    }

    vector(const vector<T> &rhs)
    {
        int size = rhs._end - rhs._first;
        _first = _allocator.allocate(size);
        int len = rhs._last - rhs._fisrt;
        for (int i =0 ;i<len;i++)
        {
            // _first[i] = rhs._first[i];
            _allocator.construct(_first + i, rhs._first[i]);
        }
        _last = _first + len;
        _end = _first + size;
    }

    vector<T>& operator=(const vector<T>& rhs)
    {
        if(this == &rhs)
            return *this;
        
        // delete[]_first;
        for(T *p = _first; p!=_last;++p)
        {
            _allocator.destroy(p);
        }
        _allocator.deallocate(_first);

        int size = rhs._end - rhs._first;
        _first = _allocator.allocate(size);
        int len = rhs._last - rhs._fisrt;
        for (int i =0 ;i<len;i++)
        {
            // _first[i] = rhs._first[i];
            _allocator.construct(_first + i, rhs._first[i]);
        }
        _last = _first + len;
        _end = _first + size;
        return *this;
    } 

    void push_back(const T& val)
    {
        if(full())
            expand();
        // *_last++ = val;
        _allocator.construct(_last, val);
        _last++;
    }

    void pop_back() //从容器末尾删除元素
    {
        if(empty())
            return ;
        --_last;
        _allocator.destroy(_last);
        return;
    }

    T back() const
    {
        return *(_last - 1);
    }

    bool full() const{return _last == _end;}
    bool empty() const{return _first == _last;}
    int size() const {return _last - _first;}
    T& operator[](int index) //vec[2]
    {
        if(index < 0 || index>=size())
        {
            throw "OutOfRangeException";
        }
        return _first[index];
    }

    // 迭代器一般实现成容器的嵌套类型
    class iterator
    {
        public:
            iterator(T *ptr=nullptr): _ptr(ptr) {}
            bool operator!=(const iterator &it) const 
            {
                return _ptr != it._ptr;
            }

            void operator++()
            {
                _ptr++;
            }

            T& operator*() {return *_ptr;} // int data = *it; *it=20;
            const T& operator*() const {return *_ptr;}
        private:
            T *_ptr;
    };
    // 需要给容器提供begin和end方法
    iterator begin() { return iterator(_first);}
    iterator end() { return iterator(_last);}

    iterator insert(iterator it, const T& val)
    {
        //强制迭代器失效
        verify(it._ptr - 1, _last);
        T *p = _last;
        while(p > it._ptr)
        {
            _allocator.construct(p, *(p-1));
            _allocator.destroy(p - 1);
            p --;
        }
        _allocator.construct(p, val);
        _last ++;
        return iterator(this, p);
    }

    iterator erase(iterator it)
    {
        verify(it._ptr - 1, _last);
        T *p = it._ptr;
        while(p < last - 1)
        {
            _allocator.destroy(p);
            _allocator.construct(p, *(p + 1));
            p ++;
        }
        _allocator.detroy(p);
        _last --;
        return iterator(this, it._ptr);
    }


private:
    T *_first;
    T *_last;
    T *_end;
    Alloc _allocator;

    void expand()
    {
        int size = _end - _first;
        // T* ptmp = new T[2*size];
        T *ptmp = _allocator.allocate(2*size);
        for(int i =0;i<size;i++)
        {
            // ptmp[i] = _first[i];
            _allocator.construct(ptmp+i,_first[i]);
        }
        // delete []_first;
        for (T *p = _first; p!=_last; ++p)
        {
            _allocator.destroy(p);
        }
        _allocator.deallocate(_first); 
        _first = ptmp;
        _last = _first + size;
        _end = _first + 2 * size;
    }
};



class Test
{
public:
    Test() {cout<<"Test()" << endl;}
    ~Test() {cout << "~Test()" << endl;}
};

int main()
{
    // vector<int> vec;
    // for(int i =0;i<20;i++)
    // {
    //     vec.push_back(rand()%100);
    // }
    // while(!vec.empty())
    // {
    //     cout << vec.back() << " ";
    //     vec.pop_back();
    // }
    // cout << endl;

    // vector<int> vec;
    // for(int i =0 ;i<20;i++){
    //     vec.push_back(rand()%100 + 1);
    // }
    // vector<int>::iterator it = vec.begin();
    // for(;it!=vec.end();it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;

    // vector<int>::iterator it = vec.begin();
    // for(;it!=vec.end();++it)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;

    // for(int val: vec) //其底层原理，就是通过容器的迭代器来实现容器遍历的
    // {
    //     cout << val << " ";
    // }
    // cout << endl;


    //迭代器失效问题
    vector<int> vec;
    for(int i =0;i<20;i++)
    {
        vec.push_back(rand()%100+1);
    }

    auto it = vec.begin();
    for(;it!=vec.end();it++)
    {
        if(*it%2==0){
            vec.erase(it);
        }
    }

    return 0;
}

