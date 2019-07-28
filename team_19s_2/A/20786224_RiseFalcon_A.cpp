#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E5+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
int n,d,a[MAXN];bool juc;
int main() {
	n=input();
	if(n==0)return 0;
	d=input();
	for(int i=1;i<=n;++i) {
		a[i]=input();
	} 
	juc=true;
	if(juc){
		bool ric=false;
		for(int i=2;i<=n;++i) {
			if(abs(a[i]-a[i-1]) > d)  {
				ric=true;break;
			}
		}if(!ric) {
			juc=false;
			printf("Y\n");
		}
	}
	if(juc) {
		int cnt=0,j0=0;
		for(int i=2;i<=n;++i) {
			if(abs(a[i]-a[i-1])>d) {
				cnt++;j0=i;
			}
		}
		if(cnt==1 && (j0==2 || j0==n)) {
		//	printf("???");
			juc=false;
			printf("Y\n");
		}else if(cnt==2) {
			int j1=0;
			for(int i=2;i<=n;++i) {
				if(abs(a[i]-a[i-1])>d&&j0!=i) {
					j1=i;
				}
			}
			if(j1==j0-1) {
				int mid=(a[j0]+a[j1-1])/2;
				if(abs(mid-a[j1-1])<=d && abs(a[j0]-mid)<=d) {
					juc=false;
					printf("Y\n");
				}
			}
		}
	}
	if(juc) {
		printf("N\n");
	}
	return main();
}
