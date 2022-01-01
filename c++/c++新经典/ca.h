#ifndef __CAH__
#define __CAH__
template<typename C>
class A
{
    public:  
        template<typename T2>
        A(T2 v1, T2 v2);
        template<typename T>
        void myft(T tmpt)
        {
            std::cout<<tmpt<<std::endl;
        }
        C m_ic;
};

#endif 