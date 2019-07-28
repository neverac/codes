#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
int  a[200005];
int pos1[100005],pos2[100005];
long long int ans;
int p1,p2;	
int n,x;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++) 
	{
		scanf("%d",&x);
		if(!pos1[x]) 
		pos1[x]=i;
		else 
		pos2[x]=i;
	}
 	p1=1;
 	p2=1;
	for(int i=1;i<=n;i++)
	{ 
		ans+=abs(pos1[i]-p1);
		ans+=abs(pos2[i]-p2);
		p1=pos1[i];
		p2=pos2[i];
	}
	printf("%lld\n",ans);
	return 0;
}
