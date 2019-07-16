#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std; 
typedef long long ll;
struct node{
	int v,id;
	friend bool operator<(node a,node b)
	{
		return a.id<b.id;
	}
}a[200005];
int n,m,k;
bool cmp(node a,node b)
{
	return a.v>b.v;
}
int main()
{
	cin >> n >> m >> k;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].v);
		a[i].id=i+1;
	}
	sort(a,a+n,cmp);
	ll op=0;
	for(int i=0;i<k*m;i++)
	{
		op+=a[i].v;
	}
	sort(a,a+k*m);
	printf("%lld\n",op);
	for(int i=m-1;i+m<k*m;i=i+m)
	{
		printf("%d%c",a[i].id," \n"[i+m==k*m-1]);
	} 
    return 0;
}