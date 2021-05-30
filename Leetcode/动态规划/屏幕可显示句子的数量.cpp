#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
	// 从第 i 个词开始 这一行能放下几遍句子
	vector<int> dp(sentence.size(), 0);
	// 从第 i 个词开始 放下dp[i]遍句子后 变为第几个词
	vector<int> next(sentence.size(), 0);

	for (int i = 0; i < sentence.size(); ++i) {
	    int count = 0;
	    int ptr = i;
	    int cur = cols;
	    while (cur >= (int)sentence[ptr].size()) {
		cur -= sentence[ptr].size() + 1;
		++ptr;
		if (ptr == sentence.size()) {
		    ++count;
		    ptr = 0;
		}
	    }
	    dp[i] = count;
	    next[i] = ptr;
	}

	int count = 0;
	int cur = 0;
	for (int i = 0; i < rows; ++i) {
	    count += dp[cur];
	    cur = next[cur];
	}
	return count;
    }
};
