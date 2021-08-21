#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> vec = {45,45,40,40,40,35,12,6,3};

    auto itr3 = lower_bound(vec.begin(),vec.end(),40,greater<int>());
    auto itr4 = upper_bound(vec.begin(),vec.end(),40,greater<int>());

    if(itr3 == vec.end() && itr4 == vec.end())
        cout<<"Lower & Upper Bound not Found\n";
    else
    {
        cout << "lower Bound idx: " << itr3 - vec.begin()<<endl;
        cout << "upper Bound idx: " << itr4 - vec.begin() << endl;
        cout <<"lower Bound of 40 :"<<*itr3<<endl;
        cout <<"Upper Bound of 40 :"<<*itr4<<endl;
    }
    return 0;
}