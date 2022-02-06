struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
    
    bool operator < (const Point& rhs) const {
        return x == rhs.x ? y < rhs.y : x < rhs.x;
    }
    
    Point operator - (const Point& rhs) {
        Point ret(0, 0);
        ret.x = x - rhs.x;
        ret.y = y - rhs.y;
        return ret;
    }
    
    int operator ^ (const Point& rhs) {
        return x * rhs.y - y * rhs.x; 
    }
};


class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        vector<Point> arr;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            arr.push_back({points[i][0], points[i][1]});
        }
        sort(arr.begin(), arr.end());
        int tp = 0;
        vector<bool> used(n, 0);
        vector<int> st(n + 5);
        for (int i = 0; i < n; ++i) {
            while (tp >= 2 && ((arr[st[tp]] - arr[st[tp - 1]]) ^ (arr[i] - arr[st[tp]])) < 0) {
                used[st[tp--]] = false;
            }
            st[++tp] = i;
            used[i] = true;
        }
        used[0] = false;
        for (int i = n - 1; i >= 0; --i) {
            if (used[i]) continue;
            while (tp >= 2 && ((arr[st[tp]] - arr[st[tp - 1]]) ^ (arr[i] - arr[st[tp]])) < 0) {
                used[st[tp--]] = false;
            }
            st[++tp] = i;
            used[i] = true;
        }
        vector<vector<int>> ret;
        for (int i = 1; i < tp; ++i) {
           ret.push_back({arr[st[i]].x, arr[st[i]].y});
        }
        return ret;
    }
};
