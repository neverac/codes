#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 2e5+100;

vector<int> f[maxn];
int id1,dth,id2;
void dfs(int u,int fa,int deep)
{
	if(deep>dth) {
		dth = deep; id1=u;
	}
	for(int i=0;i<f[u].size();i++)
	{
		int v=f[u][i];
		if(v==fa) continue;
		dfs(v,u,deep+1);
	}
}
int n,x,y;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	if(n==1){
		cout<<"First"<<endl;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		f[x].push_back(y);
		f[y].push_back(x);
	}
	dfs(1,-1,1);dth=0;
	dfs(id1,-1,1);
	if(dth%3==2) cout<<"Second"<<endl;
	else cout<<"First"<<endl;
	return 0;
}