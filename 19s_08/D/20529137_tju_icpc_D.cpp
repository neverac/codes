#include <bits/stdc++.h>
using namespace std;

int getans(int x){
	if(x==0) return 2;
	else return x%2;
}

int t[200100];
int lowbit(int x){
	return x&(-x);
}
int add(int x,int y){
	while(x<=200000){
		t[x]=min(y,t[x]);
		x+=lowbit(x);
	}
}

int query(int x){
	int ans=4000000;
	if(x==0) return 0;
	while(x){
		ans=min(ans,t[x]);
		x-=lowbit(x);
	}
	return ans;
}
long long a[200010],ans0[200010],ans1[200100],sum[200100],sum0[200010];
int main(){
	int n;
	memset(t,0,sizeof(t));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sum[0]=0;
	ans0[0]=0;
	sum0[0]=0;
	
	int myans=400000;
	for(int i=1;i<=200000;i++)
		t[i]=400000;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		ans0[i]=min(ans0[i-1]+getans(a[i]),sum[i]);
		sum0[i]=sum0[i-1]+1-(a[i]%2);
		add(i,ans0[i]-sum0[i]);
	}
	myans=min((long long)sum0[n],sum0[n]+query(n));
	ans1[n+1]=0;
	sum[n+1]=0;
	for(int i=n;i>=1;i--){
		sum[i]=sum[i+1]+a[i];
		ans1[i]=min(ans1[i+1]+getans(a[i]),sum[i]);
		//cout << ans1[i] << " " << sum0[i-1] << endl;
		myans=min((long long)myans,ans1[i]+sum0[i-1]);
		myans=min((long long)myans,sum0[i-1]+ans1[i]+query(i-1));
		//cout << myans << " " << query(i) << endl;
	}
	printf("%d\n",myans);
}
