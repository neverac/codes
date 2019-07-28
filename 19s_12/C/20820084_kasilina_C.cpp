#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
struct node{
	int id,x;
	friend bool operator <(node a,node b)
	{
		return a.x<b.x;
	}
}a[200005];
int n,m;
int vis[200005];

int main()
{
	int t=0;
	int op=inf;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i].x);
		if(i%m==0)
		a[i].id=t++;
		else a[i].id=t;
	}
	sort(a+1,a+1+m*n);
	int p=0;
	int q=1;
	for(int i=1;i<=n*m;i++)
	{
		vis[a[i].id]++;
		if(vis[a[i].id]==1) p++;
		while(p==n)
		{
			if(a[q].id==a[i].id) 
			{
				vis[a[q].id]--;
				q++;
				continue;
			}
			op=min(op,a[i].x-a[q].x);
			vis[a[q].id]--;
			if(vis[a[q].id]==0) p--;
			q++;
		}
	}
	cout << op << endl;
    return 0;
} 
