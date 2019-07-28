#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define SIZE 5500

using namespace std;

int n;
int num[SIZE];
int mindis[SIZE];
int mintime[SIZE];
int spend(int from,int to)
{
    return (n-from+to)%n;
}
int main()
{
    int i,j,m;
    int tmp,ans;
    int from,to;
    int maxnum=-1;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        mindis[i]=1008611;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&from,&to);
        num[from]++;
        maxnum=max(maxnum,num[from]);
        mindis[from]=min(mindis[from],spend(from,to));
    }
    for(i=1;i<=n;i++)
    {
        if(num[i] && num[i]>maxnum-2)
            mintime[i]=n*(num[i]-1)+mindis[i];
    }
    for(i=1;i<=n;i++)
    {
        ans=0;
        for(j=1;j<=n;j++)
        {
            if(mintime[j])
                ans=max(ans,spend(i,j)+mintime[j]);
        }
        printf("%d ",ans);
    }
    putchar('\n');
    return 0;
}
