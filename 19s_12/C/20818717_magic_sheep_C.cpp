#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 200100;

int n,m,x;
vector<int> f[maxn];
int cnt;

struct node
{
	int val,id;
};
node T[maxn];

bool cmp(node a,node b)
{
	return a.val<b.val;
}
int mp[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>x;
			f[i].push_back(x);
			T[++cnt].val = x;
			T[cnt].id = i;
		}
		sort(f[i].begin(),f[i].end());
	}
	sort(T+1,T+1+cnt,cmp);
	int l=1,res=0,ans = 1e9;
	for(int i=1;i<=cnt;i++)
	{
		if(!mp[T[i].id]) res++;
		mp[T[i].id]++;
		while(mp[T[l].id]>1){
			mp[T[l].id]--;
			l++;
		}
		//cout<<res<<" "<<ans<<" "<<i<<endl;
		if(res==n){
			ans=min(ans,T[i].val-T[l].val);
		}
	}
	cout<<ans<<endl;
	return 0;
}