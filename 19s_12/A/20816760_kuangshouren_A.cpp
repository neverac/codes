#include<iostream>
#include<cstdio>
using namespace std;
bool k[10],l[1000007];
int m,n;
int main()
{
	cin>>m>>n;
	while(l[m]==0)
	{
		l[m]=1;
		m*=10;
		k[m/n]=1;
		m%=n;
	}
	for(int i=0;i<=9;++i)if(k[i]==1)cout<<i;
	return 0;
}