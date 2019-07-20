#include<bits/stdc++.h>
using namespace std;
int const maxn=998244353;
int n,t;
int work(){
	if(360%(180-n)==0)return 360/(180-n);
	else {
		double u,v;
		int z;
		for(int i=4;i<=360;i++){
			if((double)n<=180*1.0*(i-2)/i){
			if(180%i==0){
				z=180/i;
				if(n%z==0)return i;
			}
			else{
				u=180*1.0/i;v=n/u;z=floor(v);
				if(abs(z*u-n)<1e-5)return i;
			}}
		}
		return -1;
	}

}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ans=work();
		printf("%d\n",ans);
	}
	return 0;
}