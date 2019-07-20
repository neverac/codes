#include<bits/stdc++.h>
using namespace std;
int const maxn=1e6+10;
long long n,ans,a[maxn];
void work(){
	a[1]=1,a[2]=5,a[3]=13;
	for(long long i=4;i<maxn;i++){
		a[i]=a[i-1]+i*(i+1)/2;
		if((i-1)%2==0)a[i]+=(i+1)*(i-1)/4;
		else a[i]+=i*i/4;
	}
}
int main(){
	int t;
	work();
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		
		printf("%lld\n",a[n]);
	}
	return 0;
}
