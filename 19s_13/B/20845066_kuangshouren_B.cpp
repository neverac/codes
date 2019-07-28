#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[200007],b[100007][2];
int n;long long sum;
int main()
{
	cin>>n;
	for(int i=1;i<=n*2;++i)
	{cin>>a[i];
	if(b[a[i]][0]==0)b[a[i]][0]=i;
	else b[a[i]][1]=i;}
	b[0][0]=1;b[0][1]=1;
	for(int i=1;i<=n;++i)
	sum+=min(abs(b[i][0]-b[i-1][0])+abs(b[i][1]-b[i-1][1]),abs(b[i][0]-b[i-1][1])+abs(b[i][1]-b[i-1][0]));
	cout<<sum;
	return 0;
}