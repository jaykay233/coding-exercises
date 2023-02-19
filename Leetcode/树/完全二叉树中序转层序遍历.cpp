#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n;
int ans[10];
int idx = 0;
int a[10];

void dfs(int t) {   
    if(t > n) return ;
    dfs(t << 1);
    ans[t] = a[++ idx];
    dfs(t << 1 | 1);
}

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):val(val),left(nullptr),right(nullptr)
    {

    }
};

TreeNode* construct(int i,int j, int level_num)
{
    if(level_num < 1)
        return nullptr;
    if(i > j)
        return nullptr;
    if(i == j)
        return new TreeNode(a[i]);
    int mid = i + pow(2, level_num - 1) - 1;
    cout << "idx: " << mid << " val: " << a[mid] << endl;
    if(mid > j)
    {
        level_num--;
        cout << level_num << endl;
        return construct(i, j , level_num);
    }
    TreeNode* node = new TreeNode(a[mid]);
    node->left = construct(i, mid-1, level_num - 1);
    node->right = construct(mid+1, j, level_num - 1);
    return node;
}


int main()
{
    // vector<int> d = {1,2,2,6,7,5};
    a[1] = 1;
    a[2] = 2;
    a[3] = 2;
    a[4] = 6;
    a[5] = 7;
    a[6] = 5;
    n = 6;
    // dfs(1);
    // for(int i = 1; i <=6; i ++)
    //     cout << ans[i] << " ";
    // cout << endl;
    TreeNode* node = construct(1, 6, 3);
    queue<TreeNode*> q;
    q.push(node);
    while(!q.empty())
    {
        int size = q.size();
        for(int i =0;i<size;i++)
        {
            TreeNode* node = q.front(); q.pop();
            cout << node->val << " ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }

    return 0;
}