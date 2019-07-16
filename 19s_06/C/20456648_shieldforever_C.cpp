#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<queue>
#include<map>

using namespace std;

#define N 200020
typedef long long LL;
struct node{
	LL val;
	int id;
}a[N];
LL b[N], ans[N];
int n,m,k;
map<int, int> mp;

int cmp(const void *a, const void *b){
	return (*(node *)b).val - (*(node *)a).val;
}
int main(){
	LL i,j;
	cin>>n>>m>>k;
	for(i = 1; i <= n; i++){
		scanf("%lld", &a[i].val);
		a[i].id = i;
		//b[i] = a[i].val;
	}
	qsort(a + 1, n, sizeof(a[0]), cmp);
	//sort(a + 1, a + 1 + n, cmp);
	//reverse(a + 1, a + 1 + n);
	for(i = 1; i <= m * k; i++){
		//cout<<a[i].val<<' '<<a[i].id<<endl;
		mp[a[i].id] = 1;
	}
	//LL flag = a[m * k];
	j = 0;
	int tot = 0;
	for(i = 1; i <= n; i++){
		if(mp[i]) j++;
		if(j == m){
			ans[++tot] = i;
			j = 0;
			if(tot == k - 1)break;
		}
	}
	LL sum = 0LL;
	for(i = 1; i <= k * m; i++) sum += a[i].val;
	printf("%lld\n", sum);	
	for(i = 1; i < tot; i++)printf("%lld ", ans[i]);
	printf("%lld", ans[tot]);

	return 0;
}
