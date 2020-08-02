#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXN = 1e2 + 10;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    if(n == 1) printf("0\n");
    else printf("%d\n", n-2);
  }
  return 0;
}