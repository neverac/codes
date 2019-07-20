#include <bits/stdc++.h>
using namespace std;
long long k,a,b;
long long p;
long long maxv(long long x,long long y){
	if (x>y) return x;else return y;
}
int main(){
	cin>>k>>a>>b;
	if (a<b){
		long long l=a-1;
		if (l>=k) cout<<1+k<<endl;else {
			long long m=k;
			k-=l;
			if (k%2==0) p=(b-a)*(k/2-1)+b;else p=(b-a)*(k/2-1)+b+1;
			cout<<maxv(p,1+m)<<endl;
		}
	}else {
		cout<<1+k<<endl;
	}
	return 0;
}

