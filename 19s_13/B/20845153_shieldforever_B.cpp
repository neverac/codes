#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<queue>

using namespace std;

#define N 200010
typedef long long LL;
int a[N], n;
LL pos[N];
int vis[N];

int main(){
	cin>>n;
	int i,j,k;
	for(i = 1; i <= n * 2; i++) scanf("%d", &a[i]);
	memset(pos, -1, sizeof(pos));
	pos[0] = 1;
	memset(vis, 0, sizeof(vis));
	for(i = 1; i <= n * 2; i++){
		if(pos[a[i]] == -1){
			pos[a[i]] = i;
			vis[i] = 1;
		}
	}
	LL s1 = 0LL;
	for(i = 1; i <= n; i++) s1 += (LL)(abs(pos[i] - pos[i - 1]));

	memset(pos, -1, sizeof(pos));
	pos[0] = 1LL;
	for(i = 1; i <= n * 2; i++){
		if(pos[a[i]] == -1 && !vis[i]){
			pos[a[i]] = i;
			vis[i] = 1;
		}
	}
	LL s2 = 0;
	for(i = 1; i <= n; i++) s2 += (LL)(abs(pos[i] - pos[i - 1]));
	printf("%lld\n", s1 + s2);
	return 0;
}
