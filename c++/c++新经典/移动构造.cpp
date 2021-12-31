#include <iostream>
class B{
public: 
    B(): m_bm(100)
    {
        // std::cout << "类B的构造函数执行了" << std::endl;
    }
    B(const B& tmp)
    {
        m_bm = tmp.m_bm;
        // std::cout << "类B的拷贝构造函数执行了" << std::endl;
    }

    virtual ~B()
    {
        // std::cout << "类B的析构函数执行了" << std::endl;
    }
    int m_bm;
};

class A{
    public: 
        A():m_pb(new B())
        {
            std::cout<<"类A的构造函数执行了"<<std::endl;
        }

        A(const A& tmpa): m_pb(new B(*(tmpa.m_pb)))
        {
            std::cout << "类A的拷贝构造函数执行了" << std::endl;
        }

        A(A&& tmpa) noexcept: m_pb(tmpa.m_pb)
        {
            tmpa.m_pb = nullptr;
            std::cout << "类A的移动构造函数执行了" << std::endl;
        }

        A& operator = (const A& src)
        {
            if (this == &src)
                return *this;
            
            delete m_pb;
            m_pb = new B(*(src.m_pb));
            std::cout << "类A的拷贝赋值运算符执行了" << std::endl;
            return *this;
        }

        A& operator = (A&& src) noexcept
        {
            if (this == &src)
                return *this;
            delete m_pb;
            m_pb = src.m_pb;
            src.m_pb = nullptr;
            std::cout << "类A的移动赋值运算符执行了" << std::endl;
            return *this;
        }

        ~A()
        {
            delete m_pb;
            std::cout << "类A的析构函数执行了" <<std::endl;
        }
    private: 
        B* m_pb;
};

static A getA()
{
    A a;
    return a;
}


int main(){
    A a = std::move(getA());
    A a1(std::move(a));
    return 0;
}