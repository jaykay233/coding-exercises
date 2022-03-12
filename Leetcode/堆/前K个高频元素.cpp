//手写堆
class Solution {
public:
    void siftup(vector<vector<int>>& heap, int child){
        vector<int> val = heap[child];
        while(child >> 1 > 0 && val[1] < heap[child>>1][1]){
            heap[child] = heap[child >> 1];
            child >>= 1;
            heap[child] = val;
        }
    }

    void siftdown(vector<vector<int>>& heap, int root ,int k){
        vector<int> val = heap[root];
        while(root << 1 < k){
            int child = root << 1;
            if((child|1)<k && heap[child][1] > heap[child|1][1]) child|=1;
            if(heap[child][1] < val[1]){
                heap[root] = heap[child];
                root = child;
            }
            else 
                break;
        }
        heap[root] = val;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int n :nums) m[n]++;
        vector<vector<int>> stat;
        for(auto& r:m) stat.push_back({r.first, r.second});

        vector<vector<int>> heap;
        heap.push_back({0,0});
        for(int i = 0;i<k;i++){
            heap.push_back(stat[i]);
            siftup(heap,heap.size()-1);
        }
        for(int i = k;i<stat.size();i++){
            if(stat[i][1] > heap[1][1]){
                heap[1] = stat[i];
                siftdown(heap, 1, k + 1);
            }
        }
        vector<int> result;
        for(int i = 1;i<k+1;i++) result.push_back(heap[i][0]);
        return result;
    }
};