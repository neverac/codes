#include<bits/stdc++.h>
using namespace std;
long long  k,a,b,ans;
void work(){
	ans=1;
	if(b<=a+2){
		ans=ans+k;return ;
	}
	if(ans<a){
		if(ans+k<=a){
			ans=ans+k;return ;
		}
		k-=(a-ans);ans=a;
	}
	ans+=(k/2)*(b-a);
	if(k%2==1)ans++;
	return ;
}
int main(){
	cin>>k>>a>>b;
	work();
	printf("%lld\n",ans);


	return 0;
}