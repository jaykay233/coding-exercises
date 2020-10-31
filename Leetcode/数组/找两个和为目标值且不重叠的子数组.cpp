class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        multimap<int,int> rec;
        int left =0 ;
        int right= 0 ;
        int sum = 0;
        while(right<arr.size()){
            sum += arr[right];
            right ++ ;
            if(sum<target) continue;
            while(sum>target){
                sum -= arr[left];
                left++;
            }
            if(sum==target){
                rec.insert({right-left,left});
            }
        }

        int ans = INT_MAX;
        for(auto r1=rec.begin();r1!=rec.end();r1++){
            if(r1->first * 2>=ans) break;
            auto r2 =r1;
            while((++r2)!=rec.end()){
                if(r1->second < r2->second && r1->second + r1->first > r2->second) continue;
                if(r2->second < r1->second && r2->second + r2->first > r1->second) continue;
                ans = min(ans, r1->first + r2->first);
                break;
            }
        }

        return ans == INT_MAX?-1:ans;
    }
};