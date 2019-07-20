#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<queue>

using namespace std;

int a[110];
int a0,a1,a2,n;

void solve(){
	int i,j,k;
	cin>>n;
	a0=0;a1=0;a2=0;
	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
		if(a[i]%3==0)a0++;
		if(a[i]%3==1)a1++;
		if(a[i]%3==2)a2++;
	}
//	cout<<a0<<endl;
//	cout<<a1<<endl;
//	cout<<a2<<endl;
	int ans=0;
	ans+=a0;
	j=min(a1,a2);
	a1-=j;a2-=j;
	ans+=j;
	ans+=(max(a1,a2))/3;
	printf("%d\n",ans);
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
