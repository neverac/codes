#include<bits/stdc++.h>
using namespace std;
int la,lb,a[100010],b[100010];
void Get()
{
	int tot=0,i,j;
	for(i=1;i<=la;i++)tot+=(int)fabs(a[i]);
	for(i=1;i<=lb;i++)tot+=b[i];
	printf("%d\n",tot);
	for(i=2;i<=la;i++)
	{
		printf("%d %d\n",b[1],a[i]);
		b[1]-=a[i];
	}
	for(i=1;i<=lb-1;i++)
	{
		printf("%d %d\n",a[1],b[i]);
		a[1]-=b[i];
	}
	printf("%d %d\n",b[lb],a[1]);
}
bool cmp(int aa,int bb){return aa>bb;}
int main()
{
	int n,i,tot,x,zero=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x<0)
		{
			a[++la]=x;
		}
		else if(x>0)
		{
			b[++lb]=x;
		}
		else zero++;
	}
	sort(a+1,a+la+1,cmp);
	sort(b+1,b+lb+1);
	if(zero==n)
	{
		printf("0\n");
		for(i=1;i<n;i++)printf("0 0\n");
		return 0;
	}
	
	if(la==0)
	{
		if(zero>0){for(i=1;i<=zero;i++)a[i]=0;la=zero;}
		if(la!=0)Get();
		else
		{
			if(lb==2)
			{
				printf("%d\n",b[2]-b[1]);
				printf("%d %d",b[2],b[1]);
				return 0;
			}
			tot=0;
			for(i=2;i<=lb;i++)tot+=b[i];
			tot-=b[1];
			printf("%d\n",tot);
			printf("%d %d\n",b[1],b[2]);b[1]-=b[2];
			for(i=3;i<=n-1;i++)
			{
				printf("%d %d\n",b[1],b[i]);
				b[1]-=b[i];
			}
			printf("%d %d\n",b[n],b[1]);
		}
	}
	else if(lb==0)
	{
		if(zero>0){for(i=1;i<=zero;i++)b[i]=0;lb=zero;}
		if(lb!=0)Get();
		else
		{
			if(la==2)
			{
				printf("%d\n",a[1]-a[2]);
				printf("%d %d",a[1],a[2]);
				return 0;
			}
			tot=0;
			for(i=2;i<=la;i++)tot+=a[i];
			tot=a[1]-tot;
			printf("%d\n",tot);
			printf("%d %d\n",a[1],a[2]);a[1]-=a[2];
			for(i=3;i<=n;i++)
			{
				printf("%d %d\n",a[1],a[i]);
				a[1]-=a[i];
			}
			//printf("%d %d\n",a[n],a[1]);
		}
	}
	else
	{
		if(zero>0)
		{
			for(i=1;i<=zero;i++)a[++la]=0;
		}
		Get();
	}
	return 0;
}