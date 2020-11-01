/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

//推文法
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int pos = 0;

    NestedInteger parse(string &s) {
        // 如果当前位置是个"["则已更改返回list
        if (s[pos] == '[') return parseList(s);
        // 否则解析一个数
        return parseNum(s);
    }

    // 解析一个数字
    NestedInteger parseNum(string &s) {
        int num = 0;
        // 判断正负
        int sign = s[pos] == '-' ? -1 : 1;
        if (s[pos] == '-' || s[pos] == '+') pos++;

        for (; pos < s.size() && isdigit(s[pos]); pos++)
            num = num * 10 + s[pos] - '0';
        // 返回该数字
        return NestedInteger(sign * num);
    }

    // 解析一个List
    NestedInteger parseList(string &s) {
        NestedInteger ni;
        while (s[pos] != ']') {
            pos++;                    // 跳过[和,
            if (s[pos] == ']') break;
            // 对List中的每个元素进行解析，可能存在数字或者嵌套的List
            ni.add(parse(s));
        }
        pos++;                        // 跳过]
        // 返回解析的List
        return ni;
    }

public:
    NestedInteger deserialize(string s) {
        return parse(s);
    }
};


//STRING -> NUM 
//STRING -> [STRING,STRING,STRING,...]
