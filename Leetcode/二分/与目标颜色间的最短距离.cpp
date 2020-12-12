class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> result;
        vector<vector<int>> index(4, vector<int>());
        for (int i = 0; i < colors.size(); ++i) {
            index[colors[i]].push_back(i);
        }
        for (auto& item : queries) {
            result.push_back(findNearest(index[item[1]], item[0]));
        }
        return result;
    }

    int findNearest(vector<int>& nums, int pos) {
        if (!nums.size()) return -1;
        int left = 0, right = nums.size()-1;
        int result = INT_MAX;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            result = min(result, abs(nums[mid]-pos));
            if (nums[mid] > pos) {
                right = mid - 1;
            } else if (nums[mid] < pos) {
                left = mid + 1;
            } else {
                return 0;
            }
        }
        return result;
    }
};
