class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string strN = to_string(N);
        int i = 1;
        while(i<strN.size() && strN[i-1]<=strN[i])
            i++;
        if(i<strN.size()){
            while(i>0 && strN[i-1]>strN[i]){
                strN[i-1]--;
                i--;
            }
            for(int j =i+1;j<strN.size();j++)
                strN[j]='9';
        }
        return stoi(strN);
    }
};