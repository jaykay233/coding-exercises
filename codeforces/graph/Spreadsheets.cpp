//https://codeforces.com/problemset/problem/1/B
#include <bits/stdc++.h>
using namespace std;

char str[2014],tempStr[1024];
int row,column;


void printcol(int c) 
{
    if(!c) {
        return;
    }
    printcol((c-1)/26);
    putchar((c-1)%26 + 'A');
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%s", str);
        if(sscanf(str,"R%dC%d", &row, &column) == 2) {
            printcol(column);
            printf("%d\n", row);
        } else {
            sscanf(str, "%[A-Z]%d", tempStr, &row);
			int j = 0;
			column = 0;
            while(tempStr[j] != '\0') {
                column *= 26;
                column += tempStr[j] - 'A' + 1;
				j++;
            }
            printf("R%dC%d\n", row, column);
        }
	}
	return 0;
}
