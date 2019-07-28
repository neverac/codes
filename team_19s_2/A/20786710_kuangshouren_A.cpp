#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,d;
int a[1007],b[1007];
int main()
{
	for(;;)
	{
		scanf("%d",&n);if(n==0)break;
		scanf("%d",&d);
	memset(b,0,sizeof(b));
		int num=0,k=0;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n-1;++i)
	{if(abs(a[i]-a[i+1])>d)
	{if(b[i-1]==0)++num;
	b[i]=b[i-1]+1;
	k=i;}}
	if(num==0){cout<<"Y"<<endl;continue;}
	if(num>1||b[k]>2){cout<<"N"<<endl;continue;}
	if(num==1&&b[k]==1)
	{if(k==1||k==n-1||abs(a[k]-a[k+2])<=d*2||abs(a[k-1]-a[k+1])<=d*2)cout<<"Y"<<endl;
	else cout<<"N"<<endl;}
	else
	{if(abs(a[k-1]-a[k+1])<=d*2)cout<<"Y"<<endl;
	else cout<<"N"<<endl;}
		}	
return 0;
}