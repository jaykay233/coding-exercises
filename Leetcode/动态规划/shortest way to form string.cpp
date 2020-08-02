class Solution{
public:
    int shortestWay(string source,string target){
        if(source.empty()) return -1;
        if(target.empty()) return 0;
        int res=0 ;
        int m = source.size();
        int n = target.size();
        int cur =0 ;
        while(cur<n){
            int temp = cur;
            for(int i =0;i<m && cur<n ;i++){
                if(source[i] == target[cur])
                    cur++;
            }
            if(temp == cur) return -1;

            res ++;
        }
        return res;
    }
}