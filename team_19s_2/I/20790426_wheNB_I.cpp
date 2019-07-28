#include <bits/stdc++.h>
using namespace std;
int mp[105][105];
int vis[1000];
int c[1000];
int n,m,e;
bool dfs(int v)
{
    vis[v] = true;
    for(int i=0; i<100; i++)
    {
    	if(!mp[v][i]) continue;
        int u = i,w = c[u];
        if(w < 0 || !vis[w] && dfs(w))
        {
            c[u] = v;
            c[v] = u;
            return true;
        }
    }
    return false;
}
int match()
{
    int res = 0;
    memset(c,-1,sizeof(c));
    for(int v = 0; v < m; v++)
    {
        if(c[v] < 0)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(v)) res++;
        }
    }
    return res;
}
int main()
{
	int a,b; 
	int op;
	while(scanf("%d",&m)!=EOF&&m)
	{
		scanf("%d%d",&n,&e);
		memset(mp,0,sizeof(mp));
		for(int i=0;i<e;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a][b+30]=mp[b+30][a]=1;
		}
		op=match();
		cout << op << endl;
	}
    return 0;
}


 