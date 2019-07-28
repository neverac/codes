#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool v[1100007];int prime[1000007];
int s[100007];int tot;
int N=1100000;
int n,num,T;
int main()
{
v[1]=1;
for(int i=2;i<=N;++i)
{if(v[i]==0)
{++num;prime[num]=i;}
for(int j=1;j<=num&&i*prime[j]<=N;++j)
{v[i*prime[j]]=1;
if(i%prime[j]==0)break;}}
cin>>T;
for(int w=1;w<=T;++w)
{
memset(s,0,sizeof(s));
tot=0;
long long n;
cin>>n;
for(int i=1;i<=num;++i)
{
if(n%prime[i]!=0)continue;
++tot;
while(n%prime[i]==0)
{++s[tot];n/=prime[i];}}
if(n!=1)
{++tot;s[tot]=1;}
int p=1,ans=0;
for(int i=1;i<=tot;++i)p*=(s[i]+1);
for(int i=1;i<=p-1;++i)
{
	int kkk=p,nnn=0,j=i;
	for(int k=tot;k>=1;--k)
	{kkk/=(s[k]+1);
	if(j>=kkk)++nnn;
	j%=kkk;}
	ans+=nnn;
}
cout<<ans<<endl;
}
return 0;
}