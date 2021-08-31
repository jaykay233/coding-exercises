const int N = 100000 + 10;
int childs[N][26];
int values[N];
int nodes_cnt;
int f[N];
class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> ans(smalls.size());
        memset(childs,0,sizeof childs);
        memset(values,0xff,sizeof values);
        nodes_cnt = 0;
        memset(f,0,sizeof f);

        for(int i =0;i<smalls.size();i++){
            if(smalls[i].empty())
                continue;
            insert(smalls[i],i);
        }

        getFail();

        int j = 0;
        for(int i =0;i<big.size();i++){
            int c = big[i] - 'a';
            while(j && !childs[j][c])
                j = f[j];
            j = childs[j][c];
            int k = j;
            do{
                if(values[k]>=0) {
                    int len = smalls[values[k]].size();
                    ans[values[k]].push_back(i-len+1);
                }
                k = f[k];
            }while(k);
        }
        return ans;
    }

    void insert(const string& s, int index_of_s){
        int r = 0;
        for(int i =0;i<s.size();i++){
            int idx = s[i] - 'a';
            int& next = childs[r][idx];
            if(next == 0){
                next = ++nodes_cnt;
            }
            r = next;
        }
        values[r] = index_of_s;
    }

    void getFail(){
        queue<int> Q;
        f[0] = 0;
        for(int c = 0; c<26;c++){
            int j = childs[0][c];
            if(j){
                f[j] = 0;
                Q.push(j);
            }
        }
        while(Q.size()){
            int j = Q.front(); Q.pop();
            for(int c =0 ;c<26;c++){
                int k = childs[j][c];
                if(!k){
                    continue;
                }
                int jf = f[j];
                while(jf && !childs[jf][c])
                    jf = f[jf];
                f[k] = childs[jf][c];
                Q.push(k);
            }
        }
    }
};