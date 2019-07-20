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

#define N 100010
int a[N],b[N];
int ans,n; 

int main(){
	int i,j,k;
	int x=0,y=0,z=0;
	ans = 0;
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<0)x++;
		if(a[i]==0)y++;
		if(a[i]>0)z++;
	}
	sort(a+1,a+1+n);
	if(z==0){
		ans = a[n];
		for(i=n-1;i>=1;i--){
			ans -= a[i];
		}
		cout<<ans<<endl;
		for(i=n-1;i>=1;i--){
			printf("%d %d\n",a[n],a[i]);
			a[n]-=a[i];
		}
		return 0;
	}
	if(x==0){
		ans = a[1];
		for(i=2;i<n;i++){
			ans-=a[i];
		}
		ans = a[n] - ans;
		printf("%d\n",ans);
		for(i=2;i<n;i++){
			printf("%d %d\n",a[1],a[i]);
			a[1]-=a[i];
		}
		printf("%d %d\n", a[n], a[1]);
		return 0;
	}
	for(i=1;i<=n;i++){
		ans+=abs(a[i]);
	}

	printf("%d\n",ans);
	for(i=1;i<z;i++){
		printf("%d %d\n",a[1], a[n-i+1]);
		a[1]-=a[n-i+1];
	}
	j=1;
	for(i=z;i<n;i++){
		printf("%d %d\n",a[n-z+1],a[j]);
		a[n-z+1]-=a[j];
		j++;
	}

	

	return 0;
}
