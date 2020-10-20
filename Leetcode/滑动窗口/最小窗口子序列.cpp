//逆向收缩
class Solution {
public:
    string minWindow(string S, string T) {
        if(S==T) return S;
        int start =0;
        int end = S.size()-1;
        int t = 0;
        for(int s=0;s<S.size();s++){
            if(S[s] == T[t]) 
                t++;
            if(t==T.size()){
                int right = s;
                t --;
                while(t>=0){
                    if(S[s]==T[t]){
                        t--;
                    }
                    s--;
                }
                s++;
                if(right-s+1 < end-start+1){
                    start = s;
                    end = right;
                }
                t = 0;
            }
        }
        return end - start + 1 == S.size()?"":S.substr(start,end-start+1);
    }
};