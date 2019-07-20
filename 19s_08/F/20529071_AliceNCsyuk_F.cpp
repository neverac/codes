#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int num[100000];
int N;
int tempnum;
long long ans;
long long tempsub;
long long tempbes;
long long sumn;
long long sump;
bool flagn=false;
bool flagp=false;
int minp1;
int minp2;
int maxn1;
int maxn2;
int loc;
long long getans()
{
	long long temp;
	if(flagn==false&&flagp==true)
	{
		temp=sump-2*minp1;
	}
	else if(flagn==true&&flagp==false)
	{
		temp=sumn+2*maxn1;
	}
	else
	{
		temp=sumn+sump;
	}
	return temp;
}
int main()
{
	loc=1000000;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>tempnum;
		num[i]=tempnum;
		if(tempnum<0)
		{
			flagn=true;
			sumn+=num[i];
		}
		if(tempnum>=0)
		{
			flagp=true;
			sump+=num[i];
		}
	}
	sort(num,num+N);
	for(int i=0;i<N;i++)
	{
		if(num[i]>=0)
		{
			loc=i;
			break;
		}
	}
	sumn=-sumn;
	if(N==2)
	{
		cout<<num[1]-num[0]<<endl;
		cout<<num[1]<<" "<<num[0]<<endl;
		return 0;
	}
	if(flagn==false&&flagp==true)
	{
		minp1=num[loc];
		minp2=num[loc+1];
		ans=getans();
		cout<<ans<<endl;
		cout<<minp1<<" "<<minp2<<endl;
		tempsub=minp1-minp2;
		for(int i=2;i<N-1;i++)
		{
			cout<<tempsub<<" "<<num[i]<<endl;
			tempsub-=num[i];
		}
		cout<<num[N-1]<<" "<<tempsub<<endl;
	}
	else if(flagn==true&&flagp==false)
	{
		maxn1=num[N-1];
		maxn2=num[N-2];
		ans=getans();
		cout<<ans<<endl;
		cout<<maxn1<<" "<<maxn2<<endl;
		tempsub=maxn1-maxn2;
		for(int i=N-3;i>=0;i--)
		{
			cout<<tempsub<<" "<<num[i]<<endl;
			tempsub-=num[i];
		}
	}
	else
	{
		maxn1=num[loc-1];
		ans=getans();
		cout<<ans<<endl;
		tempsub=maxn1;
		for(int i=loc;i<N-1;i++)
		{
			cout<<tempsub<<" "<<num[i]<<endl;
			tempsub-=num[i];
		}
		tempbes=tempsub;
		tempsub=num[N-1];
		cout<<tempsub<<" "<<tempbes<<endl;
		tempsub-=tempbes;
		for(int i=loc-2;i>=0;i--)
		{
			cout<<tempsub<<" "<<num[i]<<endl;
			tempsub-=num[i];
		}
	}
	return 0;
}