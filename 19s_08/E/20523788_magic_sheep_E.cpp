#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e6+100;

int T,n;
int a[maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int T0=0,T1=0,T2=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]%3==1) T1++;
			else if(a[i]%3==0) T0++;
			else if(a[i]%3==2)  T2++;
		}
		if(T1>T2)
		{
			ans+=T0;
			ans+=T2;
			T1-=T2;
			ans+=T1/3;
		}
		else
		{
			ans+=T0;
			ans+=T1;
			T2-=T1;
			ans+=T2/3;
		}
		cout<<ans<<endl;
	}
	return 0;
}