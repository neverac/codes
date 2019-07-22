#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <iomanip>
#include <cstring>
#define N 100010
using namespace std;
typedef long long ll;
int t,n;
int w[N];
int dis[N];
int main(){
	int i, j, k;
	scanf("%d", &t);
	while (t > 0) {
		t--;
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &w[i]);
		}
		memset(dis, 0, sizeof(dis));
		int ans = abs(w[1] - w[n]);
		ans = sqrt(ans);
		printf("%d\n", ans);

	}
	return 0;
}


	