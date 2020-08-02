#include <stdio.h>
#include <string.h>
#include <queue>
 
using namespace std;
#define MAX 101
 
struct NODE {
    int x,y,z,t;
};
 
 
bool visited[MAX][MAX][MAX];
 
 
void bfs(int s,int n,int m) {
    queue<NODE>q;
    NODE now, next;
    now.x = s;
    now.y = 0;
    now.z = 0;
    now.t = 0;
    q.push(now);
    memset(visited,0,sizeof(visited));
    while(!q.empty()) {
        now = q.front();
        q.pop();
        if((now.x == s>>1 && now.y == s>>1) || (now.x == s>>1 && now.z == s>>1) || (now.z == s>>1 && now.y == s>>1)){
            printf("%d\n",now.t);
            return ;
        }
 
        if(now.x) {
            if(now.x > (n - now.y)){
                next.x = now.x - n + now.y;
                next.y = n;
                next.z = now.z;
            }
            else {
                next.x = 0;
                next.y = now.y + now.x;
                next.z = now.z;
            }
 
            if(!visited[next.x][next.y][next.z]) {
                visited[next.x][next.y][next.z] = 1;
                next.t = now.t + 1;
                q.push(next);
            }
 
            if(now.x > (m - now.z)){
                next.x = now.x - m + now.z;
                next.z = m;
                next.y = now.y;
            }
            else {
                next.x = 0;
                next.z = now.z+ now.x;
                next.y = now.y;
            }
            if(!visited[next.x][next.y][next.z]) {
                visited[next.x][next.y][next.z] = 1;
                next.t = now.t + 1;
                q.push(next);
            }
        }
 
        if(now.y) {
            if(now.y > (s - now.x)){
                next.y = now.y - s + now.x;
                next.x = s;
                next.z = now.z;
            }
            else {
                next.y = 0;
                next.x = now.y+ now.x;
                next.z = now.z;
            }
            if(!visited[next.x][next.y][next.z]) {
                visited[next.x][next.y][next.z] = 1;
                next.t = now.t + 1;
                q.push(next);
            }
 
            if(now.y > (m - now.z)){
                next.y = now.y - m + now.z;
                next.z = m;
                next.x = now.x;
            }
            else {
                next.y = 0;
                next.z = now.z+ now.y;
                next.x = now.x;
            }
            if(!visited[next.x][next.y][next.z]) {
                visited[next.x][next.y][next.z] = 1;
                next.t = now.t + 1;
                q.push(next);
            }
        }
 
        if(now.z) {
            if(now.z > (s - now.x)){
                next.z = now.z - s + now.x;
                next.x = s;
                next.y = now.y;
            }
            else {
                next.z = 0;
                next.x = now.z+ now.x;
                next.y = now.y;
            }
 
            if(!visited[next.x][next.y][next.z]) {
                visited[next.x][next.y][next.z] = 1;
                next.t = now.t + 1;
                q.push(next);
            }
            if(now.z > (n - now.y)){
                next.z = now.z - n + now.y;
                next.y = n;
                next.x = now.x;
            }
            else {
                next.z = 0;
                next.y = now.z+ now.y;
                next.x = now.x;
            }
            if(!visited[next.x][next.y][next.z]) {
                visited[next.x][next.y][next.z] = 1;
                next.t = now.t + 1;
                q.push(next);
            }
        }
    }
    puts("NO");
    return ;
}
 
int main() {
    int s, n, m;
    while(scanf("%d%d%d",&s,&n,&m),s||n||m) {
        if(s%2){
            puts("NO");
        }
        else {
            bfs(s,n,m);
        }
    }
    return 0;
}