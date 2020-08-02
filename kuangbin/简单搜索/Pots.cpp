// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int A,B,C;
const int M = 110*110 + 110;
queue<pair<int,int>> q;
unordered_map<int,int> m;
int pre[M];


void bfs(){
    q.push({0,0});
    m[0] = 0;
    bool ok = false;
    memset(pre,0,sizeof pre);
    while(!q.empty()){
        pair<int,int> t = q.front();q.pop();
        int a = t.first, b = t.second;
        int state = a * 100 + b;
        int d = m[state];
        if(a==C || b==C){
            ok = true;
            printf("%d\n",d);
            
            int pre_state;
            int pre_a, pre_b;
            vector<string> states;
            while(state){
                int a = state/100, b =state%100;
                pre_state = pre[state];
                pre_a = pre_state/100;
                pre_b = pre_state%100;
                // printf("state: %d, %d \n", pre_a,pre_b);

                if(pre_a + pre_b == a + b){
                    if(a>pre_a){
                        states.push_back("POUR(2,1)");
                    }else if(b>pre_b){
                        states.push_back("POUR(1,2)");
                    }
                }else{
                    if(a==0 && b == pre_b){
                        states.push_back("DROP(1)");
                    }else if(b==0 && a == pre_a){
                        states.push_back("DROP(2)");
                    }else if(pre_b == b && a==A){
                        states.push_back("FILL(1)");
                    }else if(pre_a == a && b==B){
                        states.push_back("FILL(2)");
                    }
                }
                state = pre_state;   
            }
            reverse(states.begin(),states.end());
            for(int i =0;i<states.size();i++){
                cout<<states[i]<<endl;
            }
            

            break;
        }

        if(a<A){
            int new_state = A*100 + b;
            if(!m.count(new_state)){
                m[new_state] = d + 1;
                q.push({A,b});
                pre[new_state] = state;
            }  
        }
        if(b<B){
            int new_state = a*100 + B;
            if(!m.count(new_state)){
                m[new_state] = d + 1;
                q.push({a,B});
                pre[new_state] = state;
            }
        }
        if(a>0){
            int new_state = b;
            if(!m.count(new_state)){
                m[new_state] = d+1;
                q.push({0,b});
                pre[new_state] = state;
            }
        }
        if(b>0){
            int new_state = a*100;
            if(!m.count(new_state)){
                m[new_state] = d+1;
                q.push({a,0});
                pre[new_state] = state;
            }
        }

        if(a>0 && b<B){
            int val = min(B-b,a);
            b+=val;a-=val;
            int new_state = a*100 + b;
            if(!m.count(new_state)){
                m[new_state] = d+1;
                q.push({a,b});
                pre[new_state] = state;
            }
        }

        if(a<A && b>0){
            int val = min(A-a,b);
            b-=val;a+=val;
            int new_state = a*100+b;
            if(!m.count(new_state)){
                m[new_state] = d+1;
                q.push({a,b});
                pre[new_state] = state;
            }
        }


    }
    if(!ok){
        printf("Impossible\n");
    }
}

int main(){
    scanf("%d%d%d",&A,&B,&C);
    bfs();
    return 0;
}