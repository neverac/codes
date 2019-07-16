#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 2e5+100;

int n,m,k;

struct node
{
	int val,pos;
};
node T[maxn];
int a[maxn];
bool vis[maxn];
long long ans;

bool cmp(node a,node b)
{
	return a.val>b.val;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>T[i].val;
		T[i].pos = i;
	}
	sort(T+1,T+1+n,cmp);
	for(int i=1;i<=m*k;i++)
	{
		ans+=T[i].val;
		vis[T[i].pos] = true;
	}
	cout<<ans<<endl;
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=vis[i];
		if(cnt==m)
		{
			sum++;
			cout<<i<<" ";
			if(sum==k-1) break;
			cnt=0;
		}
	}
	cout<<endl;
	return 0;
}