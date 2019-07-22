#include <iostream>
#include <cstdio>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n;
int a[100005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	cin >> n;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a,a+n,cmp);
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=a[i]*sum;
		sum-=a[i];
		ans+=sum*a[i];
	}
	cout << ans << endl;
    return 0;
}