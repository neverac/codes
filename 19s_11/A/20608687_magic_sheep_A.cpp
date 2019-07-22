#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e5+100;

int n;
int a[maxn];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	long long ans=0,sum=0;
	for(int i=1;i<=n;i++) sum+=a[i]; 
	for(int i=1;i<=n;i++)
	{
		ans+=sum*a[i];
		ans+=(sum-a[i])*a[i];
		sum-=a[i];
	}
	cout<<ans<<endl;
	return 0;
}