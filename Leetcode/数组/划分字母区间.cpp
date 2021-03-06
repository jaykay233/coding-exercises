#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last(26);
        int length = S.size();
        for(int i =0;i<length;i++){
            last[S[i]-'a'] = i;
        }
        vector<int> partition;
        int start =0 ;
        int end =0 ;
        for(int i =0;i<length;i++){
            end = max(end, last[S[i]-'a']);
            if( i == end){
                partition.push_back(end-start+1);
                start = end + 1;
            }
        }
        return partition;   
    }
};