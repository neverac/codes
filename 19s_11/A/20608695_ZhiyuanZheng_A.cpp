#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long a[110000]; 

int main(){
	cin>>n;
	long long s=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	sort(a+1,a+1+n);
	long long ans=0;
	for (int i=1;i<=n;i++){
		ans+=1ll*s*(a[i]+a[i-1]);
		s-=a[i];
	}
	cout<<ans<<endl;
	return 0;
}