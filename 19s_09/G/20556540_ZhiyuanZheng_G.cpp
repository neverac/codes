#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long a[maxn];

int main(){
	a[1]=1;
	a[2]=5;
	a[3]=13;
	for (int i=4;i<=maxn;i++){
		a[i]=a[i-1]+(1LL*i*1LL*(i+1))/2;
		if (i%2==0){
			a[i]+=1LL*(1LL*i*1LL*i/4);
		}else a[i]+=(1LL*(i+1)*1LL*(i/2)/2);
	}
	int T;
	cin>>T;
	while (T--){
		int n;
		cin>>n;
		cout<<a[n]<<endl;
	}
	return 0;
}

