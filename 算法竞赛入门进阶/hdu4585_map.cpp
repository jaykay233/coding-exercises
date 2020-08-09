#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main(){
    int n;
    while(~scanf("%d",&n) && n){
        mp.clear();
        mp[1000000000] = 1;
        while(n--){
            int id,g;
            scanf("%d%d",&id,&g);
            mp[g] = id;
            int ans;
            map<int,int>::iterator it = mp.find(g);
            if(it==mp.begin()) ans = (++it)->second;
            else{
                map<int,int>::iterator it2 = it;
                it2--;it++;
                if(g-it2->first <= it->first-g)
                    ans = it2->second;
                else 
                    ans = it->second;
            }
            printf("%d %d\n",id,ans);
        }
    }
}