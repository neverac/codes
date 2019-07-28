#include<iostream>
using namespace std;
struct node
{int to;node *next;};
int num[27];int sum=0,maxn=9999;
node a[27];node* q[27];
int n1,n2,m;
void dfs(int k)
{
	if(k==n1+1)
	{maxn=min(maxn,sum);
	return;}
	++sum;
	dfs(k+1);
	--sum;
	node* p=&a[k];
	while(p->next)
	{p=p->next;
	if(num[p->to]==0)++sum;
	++num[p->to];}
	dfs(k+1);
	p=&a[k];
	while(p->next)
	{p=p->next;
	--num[p->to];
	if(num[p->to]==0)
	--sum;}
}
int main()
{
	for(;;)
	{
		maxn=9999;
		cin>>n1;if(n1==0)break;
		cin>>n2;cin>>m;
	for(int i=1;i<=n1;++i){q[i]=&a[i];q[i]->next=NULL;}
	for(int i=1;i<=m;++i)
	{
		int x,y;cin>>x>>y;
		++x;++y;
		q[x]->next=new node;
		q[x]=q[x]->next;
		q[x]->to=y;
		q[x]->next=NULL;
	}
	dfs(1);
	cout<<maxn<<endl;
	}
	return 0;
}