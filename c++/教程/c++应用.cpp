#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class BigInt
{
public:
    BigInt(string str) : strDigit(str) {}

private:
    string strDigit;
    friend ostream &operator<<(ostream &out, const BigInt &src);
    friend BigInt &operator+(const BigInt &lhs, const BigInt &rhs);
    friend BigInt &operator-(const BigInt &lhs, const BigInt &rhs);
};

ostream& operator<<(ostream& out, const BigInt& src)
{
    out << src.strDigit;
    return out;
}

BigInt &operator-(const BigInt &lhs, const BigInt &rhs)
{
    string result;
    bool flag = false;
    bool minor = false;
    BigInt t("");
    string maxStr = lhs.strDigit;
    string minStr = rhs.strDigit;
    if (maxStr.length() < minStr.length())
    {
        maxStr = rhs.strDigit;
        minStr = lhs.strDigit;
        minor = true;
    }
    else if (maxStr.length() == minStr.length())
    {
        if (maxStr < minStr)
        {
            maxStr = rhs.strDigit;
            minStr = lhs.strDigit;
            minor = true;
        }
        else if (maxStr == minStr)
        {
            t.strDigit="0";
            return t;
        }
    }
    else
    {
        ;
    }
    int size1 = maxStr.length() - 1;
    int size2 = minStr.length() - 1;
    int i = size1, j = size2;
    for(; i >=0 && j>=0; --i, --j)
    {
        int ret = maxStr[i] - minStr[j];
        if(flag)
        {
            ret -= 1;
            flag = false;
        }
        if(ret < 0){
            ret += 10;
            flag = true;
        }
        result.push_back(ret + '0');
    }
    while(i>=0)
    {
        int ret = maxStr[i] - '0';
        if(flag)
        {
            ret -= 1;
            flag = false;
        }
        if(ret < 0){
            ret += 10;
            flag = true;
        }
        result.push_back(ret + '0');
        i --;
    }
    if(minor ){
        result.push_back('-');
    }
    reverse(result.begin(),result.end());
    t.strDigit = result;
    return t;
}

int main()
{
    BigInt int1("34353352325466855");
    BigInt int2("65808450348504895034");
    BigInt t  =(int1 - int2);
    cout << t<< endl;
    return 0;
}