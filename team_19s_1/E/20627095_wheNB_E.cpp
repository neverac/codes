#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int l;
int t;
int a[30];
int mp[100][100];
ll cnt[100][3];
ll sum=0; 
int q;
long long ans=0;
int main()
{
	int x1,x2,y1,y2;
   	scanf("%d",&t);
   	while(t--)
   	{
   		scanf("%d",&l);
   		sum=0;
   		memset(cnt,0,sizeof(cnt));
   		for(int i=0;i<l;i++)
   		{
   			scanf("%d",&a[i]);
		}
		int cur=0;
		for(int i=0;i<l*4;i++)
		{
			for(int j=0;j<=i;j++)
			{
				mp[j][i-j]=a[cur];
				cur=(cur+1)%l;
			}
		}
		for(int i=0;i<l*2;i++)
		{
			for(int j=0;j<l*2;j++)
			{
				cnt[i][0]+=mp[i][j];
				cnt[i][1]+=mp[j][i];
				sum+=mp[i][j];
			}
		}
		int x,y;
		int l1=l*2;
		scanf("%d",&q);
		for(int i=0;i<q;i++)
		{
			ans=0;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			int p1=(x2+1)/l1,p2=(y2+1)/l1;
			x=(x2+1)%l1;y=(y2+1)%l1;
			ans+=(ll)p1*p2*sum;
			for(int i=0;i<x;i++)
			ans+=(ll)cnt[i][0]*p2;
			for(int i=0;i<y;i++)
			ans+=(ll)cnt[i][1]*p1;
			for(int i=0;i<x;i++)
			{
				for(int j=0;j<y;j++)
				ans+=(ll)mp[i][j];
			} 
			p1=(x2+1)/l1,p2=y1/l1;
			x=(x2+1)%l1;y=y1%l1;
			ans-=(ll)p1*p2*sum;
			for(int i=0;i<x;i++)
			ans-=(ll)cnt[i][0]*p2;
			for(int i=0;i<y;i++)
			ans-=(ll)cnt[i][1]*p1;
			for(int i=0;i<x;i++)
			{
				for(int j=0;j<y;j++)
				ans-=(ll)mp[i][j];
			} 
			p1=x1/l1,p2=(y2+1)/l1;
			x=x1%l1;y=(y2+1)%l1;
			ans-=(ll)p1*p2*sum;
			for(int i=0;i<x;i++)
			ans-=(ll)cnt[i][0]*p2;
			for(int i=0;i<y;i++)
			ans-=(ll)cnt[i][1]*p1;
			for(int i=0;i<x;i++)
			{
				for(int j=0;j<y;j++)
				ans-=(ll)mp[i][j];
			} 
			p1=x1/l1,p2=y1/l1;
			x=x1%l1;y=y1%l1;
			ans+=(ll)p1*p2*sum;
			for(int i=0;i<x;i++)
			ans+=(ll)cnt[i][0]*p2;
			for(int i=0;i<y;i++)
			ans+=(ll)cnt[i][1]*p1;
			for(int i=0;i<x;i++)
			{
				for(int j=0;j<y;j++)
				ans+=(ll)mp[i][j];
			} 
			printf("%lld\n",ans);
		}
	}
    return 0;
}
