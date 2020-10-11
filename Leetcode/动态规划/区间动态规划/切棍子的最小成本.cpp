class Solution {
public:
    vector<vector<int>> visited;
    vector<int> dp;
    int n;
    vector<int> cuts;
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        this->cuts = cuts;
        int num = cuts.size();
        dp = vector<int>(num);
        
        visited = vector<vector<int>>(num,vector<int>(num,INT_MAX/2));
        // cout<<"ok"<<endl;
        return dfs(0,num-1);
    }

    int dfs(int i,int j){
        if(i+1>=j) return 0;
        // cout<<cuts[i]<<" "<<cuts[j]<<endl;
        if(visited[i][j]!=INT_MAX/2) return visited[i][j]; 
        int min_value = INT_MAX/3;
        for(int k=i+1;k<j;k++){
            min_value = min(min_value,cuts[j]-cuts[i] + dfs(i,k) + dfs(k,j));
        }
        return visited[i][j] = min_value;
    }

};