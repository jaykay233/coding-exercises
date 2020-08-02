#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a;
int n,opt,x;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--)
    {
        cin>>opt>>x;
        if (opt==1)
            a.insert(upper_bound(a.begin(),a.end(),x),x);
        if (opt==2)
            a.erase(lower_bound(a.begin(),a.end(),x));
        if (opt==3)
            cout<<lower_bound(a.begin(),a.end(),x)-a.begin()+1<<endl;
        if (opt==4)
            cout<<a[x-1]<<endl;
        if (opt==5)
            cout<<*--lower_bound(a.begin(),a.end(),x)<<endl;
        if (opt==6)
            cout<<*upper_bound(a.begin(),a.end(),x)<<endl;
    }
}
