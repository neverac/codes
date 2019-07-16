#include <bits/stdc++.h>
using namespace std;
int mp[1005][1005];
int n;
int vis[1005][1005];
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		scanf("%d",&mp[i][j]);
		}
	}
	int op=1;
	for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(vis[i][j]||mp[i][j+1]-mp[i][j]!=1||mp[i+1][j]-mp[i][j]!=1||mp[i+1][j+1]-mp[i][j]!=2) continue;
    		int d=j+2;
    		while(mp[i][d]-mp[i][d-1]==1) d++,vis[i][d]=1;
    		for(int k=j;k<d;k++)
    		{
    			for(int l=i+1;l-i<d-j;l++)
    			{
    				if(mp[l][k]-mp[l-1][k]!=1)
    				{
    					d=l-i+j;break;
					}
					else vis[l][k]=1;
				}
			}
    		op=max(op,d-j);
		}
	}
	cout << op << endl;
	return 0;
}