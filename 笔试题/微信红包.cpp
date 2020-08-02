#include <vector>
using namespace std;
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        if(n==0) return 0;
        int cnt = 0;
        int val;
        for(int i =1;i<n;i++){
            if(cnt==0){
                cnt = 1;
                val = gifts[i];
            }
            else if(val==gifts[i])
                cnt++;
            else{
                cnt--;
            }
        }
        int cnt = 0;
        for(int i =0;i<n;i++){
            if(val==gifts[i]) cnt++;
        }
        if(cnt>n/2) return val;
        return 0;
    }
};