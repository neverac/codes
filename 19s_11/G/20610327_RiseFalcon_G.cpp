#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E5+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
TYPE lsqrt(TYPE x) {
	TYPE ans=0;
	TYPE l=0,r=1E9+1;
	while(l<=r) {
		TYPE mid=l+(r-l)/2;
//		printf(">>> %lld\n",mid);
		if(mid*mid<=x) {
			ans=mid;
			l=mid+1;
		}else r=mid-1; 
	}return ans;
} 
int main() {
	TYPE c,jc,ans=1;
	scanf("%lld",&c);jc=c;
	if(c==0) {
		printf("%lld\n",1LL);
		return 0;
	}
	for(TYPE i=2;i<=1E7 && i<=c;++i) {
		if(c%i==0) {
			int cnt=0;
			while(c%i==0) {
				c/=i;
				++cnt;
				if(cnt%2==0) {
					ans*=i;
					jc/=i*i;
				}
			}
		}
	}
	if(c!=1) {
		TYPE i=lsqrt(c);
		if(c==i*i) {
			ans*=i;
			c=1;
			jc/=i*i;
		}
	}
//	printf(">>%lld %lld\n",ans,jc);
	printf("%lld\n",(ans+2)/2);
	return 0;
}
