#include<iostream>
#include<algorithm>
using namespace std;
int n;
int d[100000];
long long ans;
long long sumdis;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	sort(d,d+n);
	for(int i=n-1;i>=0;i--)
	{
		sumdis+=d[i];
		ans=ans+sumdis*d[i];
		sumdis+=d[i];
	}
	cout<<ans<<endl;
	return 0;
}