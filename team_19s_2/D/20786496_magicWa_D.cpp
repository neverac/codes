#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#define LL long long
using namespace std;

LL f[250][250];
map<LL,int> mp;

LL n,m,x,y,z,tot;
LL ans[1001005];
int main()
{
	while(cin>>n)
	{
		if(n==0) return 0;
		cin>>m;
		mp.clear();
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y;
			f[x][y]=1;f[y][x]=1;
		}
		for(int i=0;i<=n;i++) f[i][i] = 0;
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					f[i][j] =min (f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		int tot = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(f[i][j]<1e15&&f[i][j])
				{
					//cout<<i<<" "<<j<<" "<<f[i][j]<<" f i j"<<endl;
					if(!mp[f[i][j]]){
						ans[++tot] = f[i][j];
					}
					mp[f[i][j]]++;
				}
			}
		}
		sort(ans+1,ans+1+tot);
		for(int i=1;i<=tot;i++)
		{
			cout<<ans[i]<<" "<<mp[ans[i]]<<endl;
		}
	}
	return 0;
}
/*
3 
3 
0 1 
1 2 
2 0
5
5 
0 1 
1 2 
1 3 
2 4 
3 4 
0
 */