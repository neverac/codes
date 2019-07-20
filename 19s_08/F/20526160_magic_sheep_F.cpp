#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e5+100;

int n,m;
int a[maxn],b[maxn],ans;
bool ok1=false,ok2=false;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];b[i]=a[i];
		if(a[i]>=0) ok1=true;
		if(a[i]<=0) ok2=true;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	if(ok1&&ok2)
	{
		for(int i=2;i<=n-1;i++)
		{
			if(b[i]>0) b[1]-=b[i];
		}
		b[n]-=b[1];
		for(int i=2;i<=n-1;i++)
		{
			if(b[i]<=0) b[n]-=b[i];
		}
		cout<<b[n]<<endl;
		for(int i=2;i<=n-1;i++)
		{
			if(a[i]>0)
			{
				cout<<a[1]<<" "<<a[i]<<endl;
				a[1]-=a[i];
			}
		}
		cout<<a[n]<<" "<<a[1]<<endl;
		a[n]-=a[1];
		for(int i=2;i<=n-1;i++)
		{
			if(a[i]<=0) {
				cout<<a[n]<<" "<<a[i]<<endl;
				a[n]-=a[i];
			}
		}
		return 0;
	}
	if(ok1)
	{
		b[1]-=b[n];
		for(int i=2;i<=n-2;i++) b[1]-=b[i];
		b[n-1]-=b[1];
		cout<<b[n-1]<<endl;
		cout<<a[1]<<" "<<a[n]<<endl;
		a[1]-=a[n];
		for(int i=2;i<=n-2;i++) cout<<a[1]<<" "<<a[i]<<endl,a[1]-=a[i];
		cout<<a[n-1]<<" "<<a[1];
		return 0;
	}
	if(ok2)
	{
		b[n]-=b[1];
		for(int i=2;i<n;i++) b[n]-=b[i];
		cout<<b[n]<<endl;
		cout<<a[n]<<" "<<a[1]<<endl;
		a[n]-=a[1];
		for(int i=2;i<n;i++) cout<<a[n]<<" "<<a[i]<<endl,a[n]-=a[i];
		return 0;
	}
	return 0;
}
/*

5
-1 -3 -5 6 3

5
1 3 4 5 6
5
-4 -7 -1 -2 0
 */