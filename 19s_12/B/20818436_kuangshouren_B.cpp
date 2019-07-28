#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[500007];int n;
bool c[500007][4];
struct node
{int lazy[4];int l,r;};
node tree[2000007];
void build(int lef,int righ,int x)
{
	tree[x].l=lef;tree[x].r=righ;
	if(lef==righ)
	{for(int i=1;i<=3;++i)
	tree[x].lazy[i]=c[lef][i];}
	else
	{int mid=(lef+righ)>>1;
	build(lef,mid,x<<1);
	build(mid+1,righ,x<<1|1);
	for(int i=1;i<=3;++i)tree[x].lazy[i]=tree[x<<1].lazy[i]&tree[x<<1|1].lazy[i];
	}
}
int look(int lef,int righ,int h,int x)
{
	if(tree[x].l>righ||tree[x].r<lef)return 1;
	if(tree[x].l>=lef&&tree[x].r<=righ)return tree[x].lazy[h];
	return look(lef,righ,h,x<<1)&look(lef,righ,h,x<<1|1);

}
int main()
{
	scanf("%s+1",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)
	{if(s[i]==s[n-i])c[i][1]=1;
	if(s[i]==s[n+1-i])c[i][2]=1;
	if(s[i]==s[n+2-i])c[i][3]=1;}
	build(1,n,1);
	for(int i=1;i<=(n+1)/2;++i)
	{
		int k=look(1,i-1,2,1)&look(n+2-i,n,2,1)&look(i+1,n+1-i,3,1);
		if(k==1)
		{cout<<i;return 0;}
	}
	for(int i=(n+1)/2+1;i<=n;++i)
	{
		int k=look(i+1,n,2,1)&look(1,n-i,2,1)&look(n-i+1,i-1,1,1);
		if(k==1)
		{cout<<i;return 0;}
	}
	return 0;
}