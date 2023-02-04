class Solution
{
public: 
    vector<int> nl, ns;
    int maxDepthBST(vector<int>& order)
    {
        int n = order.size(), res = 0;
        map<int,int> m;
        m[0] =0 ;
        for(int i: order)
        {
            auto it = --m.upper_bound(i);
            m[i] = ++it->second;
            res = max(res, it->second);
        }
        return res;
    }
};