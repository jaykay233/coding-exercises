class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        if (s.empty()) {
            return "";
        }

        int N = s.size();
        int end = 0;
        vector<bool> bold(N, false);
        for (int i = 0; i < N; i++) {
            for (const auto& word : dict) {
                int len = word.size();
                if (i + len <= N && s.substr(i, len) == word) {
                    end = max(end, i + len);
                }
            }
            bold[i] = end > i; // Note: end > i not >= i
        }

        string res;
        for (int i = 0; i < N; i++) {
            int j = i;
            if (!bold[i]) {
                res += s[i];
                continue;
            }

            while (j < N && bold[j] == true) {
                j++;
            }
            res += "<b>" + s.substr(i, j - i) + "</b>";
            i = j - 1;
        }

        return res;
    } 
};
