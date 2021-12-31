#include <iostream>
using namespace std;
class A2: public Grand
{
    public:  
        A2(int i): Grand(i), m_value2(i)
        {
            cout<<"A2 constructor" << endl;
        }

        virtual ~A2(){
            cout<<"A2 deconstrunctor"<<endl;
        }

        void myinfo(){
            cout<<m_value2<<endl;
        }
    public:  
        int m_value2;
};