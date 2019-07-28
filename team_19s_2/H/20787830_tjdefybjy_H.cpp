#include <bits/stdc++.h>
//??????
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E6+10;
const int MAXM=1E7+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
TYPE prime[MAXN],tot;
bool vis[MAXM];
int cnt[MAXN],tail;
void setup(const int N=1E7) {
	for(int i=2;i<=N;++i) {
		if(!vis[i]) {
			++tot;prime[tot]=i;
		}
		for(int j=1;j<=tot&&i*prime[j]<=N;++j) {
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
void breakUp(TYPE x) {
	tail=0;
	for(int j=1;j<=tot && 1ll*prime[j]*prime[j]<=x;++j) {
		if(x%prime[j]==0) {
			cnt[++tail]=0;
			while(x%prime[j]==0) {
				x/=prime[j];
				cnt[tail]++;
			}
		}
	} 
	if(x!=1) {
		cnt[++tail]=1;
	}
}
TYPE count() {
	TYPE ix=1;
	for(int i=1;i<=tail;++i) {
		ix*=(cnt[i]+1);
	}
	TYPE ans=0;
	for(int i=1;i<=tail;++i) {
		ans+=ix/(cnt[i]+1)*cnt[i];
	}return ans;
}
int main() {
	setup();
//	printf("%lld\n",tot);
	TYPE T=input();
	while(T-->0) {
		TYPE x;scanf("%lld",&x);
		breakUp(x);
		printf("%lld\n",count());
	}return 0;
}
