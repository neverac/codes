#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=998244353;
const int MAXN=1E6+10;
const int INF=~0U>>1;
const TYPE x=13;
int N,M,tail;
int input() {
	int x;scanf("%d",&x);
	return x;
}
struct pair {
	int x,col;
}w[MAXN];
bool operator < (const pair&a,const pair&b) {
	if(a.x!=b.x)return a.x<b.x;
	return a.col<b.col;
}
int count,tong[MAXN];
void dec(int i) {
	tong[w[i].col]--;
	if(tong[w[i].col]==0)count--;
}
void inc(int i) {
	tong[w[i].col]++;
	if(tong[w[i].col]==1)count++;
}
bool check(int x) {
	count=0;
	int left=1;bool juc=false;
	for(int i=1;i<=tail;++i) {
		inc(i);
		while(w[i].x-w[left].x>x) dec(left++);
		if(count==N) {
			juc=true;
		} 
	}
	while(left<=tail)dec(left++);
	return juc;
}
int main() {
	N=input();
	M=input();
	tail=0;
	for(int t=1;t<=N;++t) {
		for(int i=1;i<=M;++i) {
			int x=input();
			++tail;
			w[tail].x=x;
			w[tail].col=t;
		}
	}std::sort(w+1,w+tail+1);
	int l=0,r=1E6+1,ans=INF;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) {
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}printf("%d\n",ans);
	return 0;
}
