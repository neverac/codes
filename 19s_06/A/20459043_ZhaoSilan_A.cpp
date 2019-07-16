#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string.h> 
using namespace std;
const long long int  N=1000005;
long long int p[1000005];
bool flag[1000005];
long long int a[1000005],aa[1000005];
int tot=0;
typedef long long int ll;
long long int fp(long long int a,long long int b)//快速幂 
{
    long long int ans = 1;
    while(b)
	{
        if(b&1) 
		ans=(ans*a);
        b >>= 1;
        a = (a*a);
    }
    return ans;
}

int main()
{
    flag[1]=1;
    int i,j,m=0;
    for(i=2;i<=N;i++)
    {
        if(!flag[i])
        {	
			p[m++]=i;
			if(i<=1000)
        	for(j=i*i;j<=N;j+=i)
        	{
            	flag[j]=1;
    		}
        }
	}//找质数 
	long long int n,b;
	scanf("%lld%lld",&n,&b);
	long long int num=b;
	for(i=0;i<m&&num!=1;i++)
	{
	   if(num%(long long int)(p[i])==0)
	   {
	   	   int cnt=0;
	   	   tot++;
	   	   while(num%(long long int)(p[i])==0)
	       {
		   	num/=(long long int)(p[i]);
			cnt++;
		   }
		   a[tot]=(long long int)(p[i]);
		   aa[tot]=(long long int)(cnt);
	   }	
	}	//质因数分解 

	if(num!=1)
	{
	  tot++;
	  a[tot]=(long long int)(num);
	  aa[tot]=1ll;
    }
    
    long long int pp=-1;
    for(i=1;i<=tot;i++)
    {
    	long long int yj=0;
    	// a[i]的aa[i]次方的 
    	long long int ans=0;
		int p=(int)(log(n)/log(a[i])); 
		long long int cc=fp(a[i],(long long int)(p));
//		printf("%d\n",p);
		for(j=p;j>=1;j--)
    	{
    		ans+=(n/cc-yj)*j;
    		yj=n/cc;
    		cc/=a[i];
		}
//		printf("%lld %lld %d\n",a[i],aa[i],ans);
		ans/=aa[i];//你要多少个
		
		if(pp==-1)
		pp=ans;
		else
		pp=min(pp,ans); 
	}
	printf("%lld",pp);
    return 0;
}