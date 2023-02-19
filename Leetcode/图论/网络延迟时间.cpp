class Solution {
public:
    typedef pair<int, int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<P>> g(n);
        k--;
        for(vector<int>& t:times){
            int a = t[0] - 1;
            int b = t[1] - 1;
            int cost = t[2];
            g[a].push_back(make_pair(cost,b));
        }
        priority_queue<P,vector<P>, greater<P>> q;
        vector<int> dist(n);
        fill(dist.begin(), dist.begin() + n, INT_MAX/2);
        dist[k] = 0;
        q.push(P(0,k));
        while(!q.empty())
        {
            P p= q.top(); q.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            for(int i =0 ;i < g[v].size();i++)
            {
                P e = g[v][i];
                int to = e.second;
                int cost = e.first;
                if(dist[to] > dist[v] + cost)
                {
                    dist[to] = dist[v] + cost;
                    q.push(P(dist[to], to));
                }
            }
        }

        int max_delay=0;
        for(int i = 0;i<dist.size();i++){
            max_delay = max(max_delay, dist[i]);
        }
        return max_delay >= INT_MAX/2 ? -1 : max_delay;
    }
};