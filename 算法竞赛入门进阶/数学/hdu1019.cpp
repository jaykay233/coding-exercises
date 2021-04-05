#include <iostream>
using namespace std;
int arr[11];
int t,n;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}


int main(){
    while(cin>>t){
        while(t--){
            cin>>n;
            for(int i=1;i<=n;i++){
                cin>>arr[i];
                if(i!=1){
                    arr[i] = arr[i-1]/gcd(arr[i-1],arr[i])*arr[i];
                }
            }
            cout<<arr[n]<<endl;
        }
    }
    return 0;
}