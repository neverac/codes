#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 1e3+100;

char s[maxn];
int a[maxn];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{	
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1') a[i]=1;
			else a[i]=0;
		}
		for(int i=1;i<=n;i++) a[i]+=a[i-1];
		int ans = 1e9+100;
		ans = a[n];
		for(int i=1;i<=n;i++)
		{
			int res = 0;
			int pre = i-1;
			res += a[pre];
			res += (n-pre) -a[n]+a[pre];
			ans = min(ans,res);
		}
		cout<<ans<<endl;
	}
}
/*
4
1111110001
 */