#include<algorithm>
#include<cstdio>
#include<iostream>
#include<Cstring>
#include<queue>
#include<vector>
#define SIZE 200100
using namespace std;

struct st
{
    int num;
    int id;
}rec[SIZE];
int ans[SIZE];

bool cmp1(st a,st b)
{
	 return a.num>b.num;
}
bool cmp2(st a,st b)
{
	 return a.id<b.id;
}
int main()
{
    int n,m,k,i,j;
    long long num;
    long long sum=0;
	scanf("%d%d%d",&n,&m,&k);
	num=m*k;
	for(i=1;i<=n;i++)
    {
		scanf("%d",rec+i);
		rec[i].id=i;
	}
	sort(rec+1,rec+n+1,cmp1);
	for(i=1;i<=num;i++)
    {
		sum+=rec[i].num;
//		printf("xx%d\n",rec[i].num);
	}
	printf("%lld\n",sum);
	sort(rec+1,rec+num+1,cmp2);
	int cnt=0;
	for(i=m;i<=num-m;i+=m)
        ans[cnt++]=rec[i].id;
    for(i=0;i<k-2;i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[i]);

    return 0;
}
