#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E5+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
int a[MAXN],z[MAXN],d[MAXN];
int main() {
	int N=input();
	for(int i=1;i<=N;++i) {
		a[i]=input();
		z[i]=a[i];
		d[i]=a[i];
	}
	std::sort(z+1,z+N+1);
	std::sort(d+1,d+N+1);std::reverse(d+1,d+N+1);
	bool judge =true;
	if(judge) {
		bool jud=true;
		for(int i=1;i<=N;++i) {
			if(a[i]!=z[i]) {
				jud=false;
			}
		}
		if(jud) {
			judge=false;
			printf("Nothing to do here\n");
		}
	}
	if(judge) {
		bool jud=true;
		for(int i=1;i<=N;++i) {
			if(a[i]!=d[i]) {
				jud=false;
			}
		}
		if(jud) {
			judge=false;
			printf("Nothing to do here\n");
		}
	}
	
	if(judge) {
		int cnt=0,ptr=0;
		for(int i=1;i<=N;++i) {
			if(a[i]!=z[i]) {
				++cnt;
				ptr=i;
			}
		}
		if(cnt==2) {
			judge=false;
			int ptr2=0;
			for(int i=1;i<=N;++i) {
				if(a[i]!=z[i] && i!=ptr) {
					ptr2=i;
				}
			}
			printf("Yes\n");
			printf("%d %d\n",ptr2,ptr);
		}
	}
	if(judge) {
		int cnt=0,ptr=0;
		for(int i=1;i<=N;++i) {
			if(a[i]!=d[i]) {
				++cnt;
				ptr=i;
			}
		}
		if(cnt==2) {
			judge=false;
			int ptr2=0;
			for(int i=1;i<=N;++i) {
				if(a[i]!=d[i] && i!=ptr) {
					ptr2=i;
				}
			}
			printf("Yes\n");
			printf("%d %d\n",ptr2,ptr);
		}
	}
	if(judge) {
		printf("No hope\n");
	}
	return 0;
}
