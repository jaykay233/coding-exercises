// #include <bits/stdc++.h>
// using namespace std;


// struct BigInteger {
// 	int big[1000];
// 	int length;
// 	BigInteger() {
// 		memset(big, 0, sizeof(big));
// 		length = 0;
// 	}
// 	BigInteger(long long num) {
// 		*this = num;
// 	}
// 	BigInteger(const string& str) {
// 		*this = str;
// 	}
// 	BigInteger operator = (long long num) {
// 		memset(big, 0, sizeof(big));
// 		length = 0;
// 		do {
// 			big[length++] = num % 10;
// 			num /= 10;
// 		} while (num);
// 		return *this;
// 	}
// 	BigInteger operator = (const string& str) {
// 		memset(big, 0, sizeof(big));
// 		length = str.size();
// 		for (int i = 0; i < length; i++) {
// 			big[i] = str[length - i - 1] - '0';
// 		}
// 		return *this;
// 	}
// 	bool operator < (const BigInteger& b) const {
// 		if (length != b.length)return length < b.length;
// 		for (int i = length - 1; i >= 0; i--) {
// 			if (big[i] != b.big[i])return big[i] < b.big[i];
// 		}
// 		return false;
// 	}
// 	bool operator > (const BigInteger& b) const { return b < *this; }
// 	bool operator <= (const BigInteger& b) const { return !(b < *this); }
// 	bool operator >= (const BigInteger& b) const { return !(*this < b); }
// 	bool operator != (const BigInteger& b) const { return b < *this || *this < b; }
// 	bool operator == (const BigInteger& b) const { return !(b < *this) && !(*this < b); }
// 	BigInteger operator + (const BigInteger& b) const {
// 		BigInteger c;
// 		int carry = 0;
// 		for (int i = 0; ; i++) {
// 			if (carry == 0 && i >= length && i >= b.length)break;
// 			int x = carry;
// 			if (i < length)x += big[i];
// 			if (i < b.length)x += b.big[i];
// 			c.big[c.length++] = x % 10;
// 			carry = x / 10;
// 		}
// 		return c;
// 	}
// 	BigInteger operator += (const BigInteger& b) {
// 		*this = *this + b;
// 		return *this;
// 	}
// 	BigInteger operator - (const BigInteger& b) const {// *this >= b
// 		BigInteger c;
// 		bool borrow = false;
// 		for (int i = 0; i < length; i++) {
// 			int x = borrow ? big[i] - 1 : big[i];
// 			if (x < b.big[i]) {
// 				borrow = true;
// 				x += 10;
// 			}
// 			else {
// 				borrow = false;
// 			}
// 			c.big[c.length++] += x - b.big[i];
// 		}
// 		while (c.big[c.length - 1] == 0 && c.length > 1)c.length--;
// 		return c;
// 	}
// 	BigInteger operator -= (const BigInteger& b) {
// 		*this = *this - b;
// 		return *this;
// 	}
// 	BigInteger operator * (const BigInteger& b) const {
// 		BigInteger c(0);
// 		for (int i = 0; i < length; i++) {
// 			BigInteger t;
// 			t.length = i;
// 			int carry = 0;
// 			for (int j = 0; j < b.length; j++) {
// 				int x = big[i] * b.big[j] + carry;
// 				t.big[t.length++] = x % 10;
// 				carry = x / 10;
// 			}
// 			if (carry) {
// 				t.big[t.length++] = carry;
// 			}
// 			c += t;
// 		}
// 		BigInteger e;
// 		e.length = c.length;
// 		if (c == e) {
// 			return BigInteger(0);
// 		}
// 		return c;
// 	}
// 	BigInteger operator *= (const BigInteger& b) {
// 		*this = *this * b;
// 		return *this;
// 	}
// 	BigInteger operator ^ (long long num) const {
// 		BigInteger b(*this);
// 		BigInteger c(1);
// 		while (num) {
// 			if ((num & 1) == 1) {
// 				c *= b;
// 			}
// 			b *= b;
// 			num >>= 1;
// 		}
// 		return c;
// 	}
// 	BigInteger operator / (const BigInteger& b) const {
// 		if (*this < b) {
// 			return BigInteger(0);
// 		}
// 		BigInteger c;
// 		BigInteger d(10);
// 		BigInteger m(*this);
// 		BigInteger n;
// 		int digit = length - b.length;
// 		for (int i = digit; i >= 0; i--) {
// 			n = b * (d ^ i);
// 			int j = 0;
// 			for ( ; ; j++) {
// 				if (m >= n) {
// 					m = m - n;
// 				}
// 				else {
// 					break;
// 				}
// 			}
// 			BigInteger t(j);
// 			c += t * (d ^ i);
// 		}
// 		return c;
// 	}
// 	BigInteger operator /= (const BigInteger& b) {
// 		*this = *this / b;
// 		return *this;
// 	}
// };

// int main(){
//     int n;
//     while(~scanf("%d",&n)){
//         BigInteger t(1);
//         for(int i=1;i<=n;i++){
//             t *= BigInteger((long long )i);
//         }
//         for(int i = t.length-1;i>=0;i--){
//             printf("%d",t.big[i]);
//         }
//         printf("\n");
//     }

//     return 0;
// }

//压位
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 20000;
int result[MAXN];

void fac(int n){
    memset(result,0,sizeof result);
    result[0] = 1;
    for(int i=2;i<=n;i++){
        int t =0,k = 0;
        for(int j =0;j<MAXN;j++){
            int temp = result[j]*i+t;
            result[j] = temp%10000;
            t = temp/10000;
        }
    }
    int i = MAXN - 1;
    for(;!result[i];i--) ;
    cout<<result[i];
    for(i-=1;i>=0;i--){
        if(result[i]<10){
            cout<<"000";
        }
        else if(result[i]<100){
            cout<<"00";
        }
        else if(result[i]<1000){
            cout<<"0";
        }
        cout<<result[i];
    }
    cout<<endl;
}

int main(){
    int n;
    while(cin>>n){
        fac(n);
    }

    return 0;
}