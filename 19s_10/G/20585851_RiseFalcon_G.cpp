#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=5E5+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
const TYPE INR=10000000000000000LL;
struct big{
	TYPE a,b;
	big(TYPE x,TYPE y) {
		a=x;b=y;
	}
	big(TYPE x=0) {
		a=x/INR;
		b=x%INR;
	}
	big div() const{
		return (a%2==1) ? big(a/2,b/2+INR/2):big(a/2,b/2);
	}
	void print()const{
		if(a!=0) {
			printf("%lld%016lld",a,b);
		}else	printf("%lld",b);
	}
};
typedef const big& cbig;
big operator + (cbig x,cbig y) {
	return big(x.a+y.a+(x.b+y.b)/INR,(x.b+y.b)%INR);
}
big operator - (cbig x,cbig y) {
	TYPE a=x.a-y.a;
	TYPE b=x.b-y.b;
	return x.b-y.b< 0 ? big(a-1,b+INR):big(a,b);
}
bool operator == (cbig x,cbig y) {
	return x.a==y.a && x.b==y.b;
}
bool operator < (cbig x,cbig y) {
	if(x.a!=y.a) return x.a<y.a;
	else return x.b<y.b;
}
big a[MAXN],_a[MAXN],b[MAXN];
int N,r;TYPE k;
bool check(big x) {
	memset(b,0,sizeof b);
	big w=k,pre=0;
//	printf("in ");x.print();printf("\n");
	for(int i=1;i<=N;++i) {
		pre=pre+b[i];
		if(pre+a[i] < x) {
			big c=x-pre-a[i];
			int rr=std::min(N,i+r+r)+1;
			b[rr]=b[rr]-c;
			pre=x-a[i];
			if(w<c) {
//				printf("\n");
				return false;
				
			}
			else w=w-c;
		}
//		(pre+a[i]).print();printf(" ");
	}//printf("\n");
	//return !(w<0);
	return true;
}
int main() {
//	(big(15,0).div()).print();
	scanf("%d%d%lld",&N,&r,&k);
	for(int i=1;i<=N;++i) {
		TYPE x;scanf("%lld",&x);
		_a[i]=x;
	}
	for(int i=1;i<=N;++i) {
		int L=std::max(1,i-r);
		int R=std::min(N,i+r)+1;
		a[L]=a[L]+_a[i];
		a[R]=a[R]-_a[i];
	}
	for(int i=1;i<=N;++i) {
		a[i]=a[i]+a[i-1];
	//	a[i].print();printf(" ");
	}
	big L=big(0,0);
	big R=big(1E7,INR);
	big ans=0;
	while (L<R || L==R) {
		big mid=(L+R).div();
		if (check(mid)) {
			ans=mid;
			L=mid+1;
		}else {
			R=mid-1;
		}
	}ans.print();
	return 0;
}
