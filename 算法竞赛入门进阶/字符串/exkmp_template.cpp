//解决问题如下：
//定义母串S和字符串T，设S的长度为n，T的长度为m，求T与S的每一个后缀的最长公共前缀，
//也就是说设置extend数组，extend[i]表示T与S[i,n-1]的最长公共前缀，要求求出所
//有的extend[i]
//这里的next数组定义如下：next[i]表示T[i,m-1]和T的最长公共前缀长度
//设P为i + extend[i]- 1的最大值，对应的i为po
//https://blog.csdn.net/dyx404514/article/details/41831947
//https://segmentfault.com/a/1190000008663857

#include <iostream>
#include <string>

using namespace std;

/* 求解 T 中 next[]，注释参考 GetExtend() */
void GetNext(string & T, int & m, int next[])
{
    int a = 0, p = 0;
    next[0] = m;

    for (int i = 1; i < m; i++)
    {
        if (i >= p || i + next[i - a] >= p)
        {
            if (i >= p)
                p = i;

            while (p < m && T[p] == T[p - i])
                p++;

            next[i] = p - i;
            a = i;
        }
        else
            next[i] = next[i - a];
    }
}

/* 求解 extend[] */
void GetExtend(string & S, int & n, string & T, int & m, int extend[], int next[])
{
    int a = 0, p = 0;
    GetNext(T, m, next);

    for (int i = 0; i < n; i++)
    {
        if (i >= p || i + next[i - a] >= p) // i >= p 的作用：举个典型例子，S 和 T 无一字符相同
        {
            if (i >= p)
                p = i;

            while (p < n && p - i < m && S[p] == T[p - i])
                p++;

            extend[i] = p - i;
            a = i;
        }
        else
            extend[i] = next[i - a];
    }
}

int main()
{
    int next[100];
    int extend[100];
    string S, T;
    int n, m;
    
    while (cin >> S >> T)
    {
        n = S.size();
        m = T.size();
        GetExtend(S, n, T, m, extend, next);

        // 打印 next
        cout << "next:   ";
        for (int i = 0; i < m; i++)
            cout << next[i] << " ";
 
        // 打印 extend
        cout << "\nextend: ";
        for (int i = 0; i < n; i++)
            cout << extend[i] << " ";

        cout << endl << endl;
    }
    return 0;
}