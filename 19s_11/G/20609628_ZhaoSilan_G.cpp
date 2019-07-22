//大质数处理办法 
#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
typedef long long int ll;
const long long int N=1000000ll;
long long int p[1000005];
bool flag[1000005];

int main()
{
    flag[1]=1;
    long long int i,j,m=0ll,x;
    for(i=2ll;i<=N;i++)
    {
        if(!flag[i])
        {
		   p[m++]=i;
//		   printf("%lld ",i);
	   }
        
        for(j=0ll;j<m&&i*p[j]<=N;j++)
        {
            flag[i*p[j]]=1;
            
            if(i%p[j]==0ll)
            break;
    	}
    }
	
	scanf("%lld",&x);
	long long int tmp=1ll,pp=sqrt(x);
	for(i=0;i<m&&x!=1ll&&p[i]<pp;i++)
	{
		if(x%p[i]==0ll)
		{
			long long int tt=1ll,tot=0ll;
			while(x%p[i]==0ll)
			{
				x/=p[i];
				tt*=p[i];
				tot++;
			}
			
			if(tot%2ll)
			{
			    tmp*=sqrt(tt/p[i]);	
			} 
			else
			{
				tmp*=sqrt(tt);
			}
		}
	}
	
	if((long long int)sqrt(x)*(long long int)sqrt(x)==x)
	{
		tmp*=(long long int)sqrt(x);
	}
    
    printf("%lld\n",tmp/2ll+1ll);
    return 0;
}