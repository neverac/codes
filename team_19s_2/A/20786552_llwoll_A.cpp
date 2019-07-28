#include <bits/stdc++.h>
#define rep(i,j,k) for (int i = j; i <= k; i++)
#define dow(i,j,k) for (int i = j; i >= k; i--)

using namespace std;
 
int a[1005];
int n, d;
int flag;
int main() {
	while(scanf("%d", &n) && n) {
		scanf("%d", &d);
		rep(i,1,n) scanf("%d", &a[i]);
		flag = 0;
		rep(i,2,n) {
			if (abs(a[i] - a[i-1]) > d) {
				if( flag ) { flag = 2; break; }
				if(i - 2 == 0 || abs(a[i] - a[i-2]) <= d * 2) flag = 1, i++;
				else if (i + 1 > n || abs(a[i+1] - a[i-1]) <= d * 2) flag = 1, i++;
				else {
					flag = 2;
					break;
				}
			}
		}
		if (flag == 2) printf("N\n");
		else printf("Y\n");
	}
}