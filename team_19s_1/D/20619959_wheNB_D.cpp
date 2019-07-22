#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int t;
int main()
{
    cin >> t;
    int x,y;
    while(t--)
    {
    	scanf("%d%d",&n,&m);
    	for(int i=1;i<=n;i++)
    	{
    		scanf("%d%d",&x,&y);
    		a[i]=x+y;
		}
		sort(a+1,a+1+n);
		long long ans=1;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(ans*a[i]<=m)
			ans*=a[i],cnt++;
			else break;
		}
		printf("%d\n",cnt);
	}
    return 0;
}
