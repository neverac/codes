#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll v,xb;
	bool co=false;
};
ll n,m,k,c,d;
node a[200200];
ll p[200200];
bool cmp(const node&a,const node&b){
	return a.v>b.v;
}
bool cmp2(const node&a,const node&b){
	return a.xb<b.xb;
}
int main(){
	cin >> n >> m >> k;
	for(int i=1; i<= n;i ++){
		scanf("%lld",&a[i].v);
		a[i].xb = i;
	}
	sort(a+1,a+1+n,cmp);
	ll cnt = 0,cnt2 = 0,ans = 0;
	for(int i = 1;i <= n;i ++){
		cnt2 ++;
		if(cnt2 <= m*k) ans += a[i].v;
		a[i].co = true;
		if(cnt2 == m*k) break;
	}
	printf("%lld\n",ans);
	sort(a+1,a+n+1,cmp2);
	cnt2 = 0;
	for(int i = 1;i <= n;i ++){
		if(a[i].co) cnt ++;
		if(cnt == m) {
			printf("%d ",i);
			cnt = 0;
			cnt2 ++;
		}
		if(cnt2 == k-1) break;
	}
    return 0;
}
