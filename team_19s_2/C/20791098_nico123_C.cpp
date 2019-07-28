#include<bits/stdc++.h>
using namespace std;
int s[1010],ls,s1[1010],ls1,cc[350],lans,ans[10100];
int Gcd(int aa,int bb){if(bb==0)return aa;else return Gcd(bb,aa%bb);}
void cheng(int kk)
{
	int i;
	for(i=1;i<=ls;i++)
	{
		s[i]*=kk;
	}
	for(i=1;i<=ls;i++)
	{
		s[i+1]+=(s[i]/10);
		s[i]%=10;
	}
	while(s[ls+1]!=0)
	{
		ls++;
		s[ls+1]+=(s[ls]/10);
		s[ls]%=10;
	}
}
int main()
{
	int T,n,k,d,nn,lcc,i,ii,j,gcd1,tot;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&k,&d);
		nn=n;lcc=0;
		for(i=1;i<=k;i++)
		{
			cc[++lcc]=nn;
			nn--;
		}
		for(i=1;i<=k;i++)
		{
			ii=i;
			for(j=1;j<=lcc;j++)
			{
				gcd1=Gcd(ii,cc[j]);
				cc[j]/=gcd1;ii/=gcd1;
				if(ii==1)break;
			}
		}
		memset(s,0,sizeof(s));
		s[1]=1;ls=1;
		for(j=1;j<=lcc;j++)
		{
			if(cc[j]==1)continue;
			cheng(cc[j]);
		}
		
		lans=0;
		while(1)
		{
			ls1=0;tot=0;
			for(i=ls;i>=1;i--)
			{
				tot=tot*10+s[i];
				s1[++ls1]=tot/d;
				tot%=d;
			}
			ans[++lans]=tot;
			for(i=1;i<=ls1/2;i++)swap(s1[i],s1[ls1-i+1]);
			while(s1[ls1]==0&&ls1>0)ls1--;
			for(i=1;i<=ls1;i++)s[i]=s1[i];
			ls=ls1;
			if(ls1==0)break;
		}
		for(i=lans;i>=1;i--)
		{
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}