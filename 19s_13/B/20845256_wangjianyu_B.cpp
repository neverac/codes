#include<cstdio>
#include<algorithm>
#define SIZE 100100

using namespace std;

int pos[SIZE][2];
long long dis[SIZE];

int main()
{
    int i,n;
    int tmp;
    scanf("%d",&n);
    pos[0][0]=1;
    pos[0][1]=1;
    dis[0]=0;
    for(i=1;i<=n+n;i++)
    {
        scanf("%d",&tmp);
        if(pos[tmp][0])
            pos[tmp][1]=i;
        else
            pos[tmp][0]=i;
    }
    for(i=1;i<=n;i++)
    {
        int dis1=abs(pos[i-1][0]-pos[i][0])+abs(pos[i-1][1]-pos[i][1]);
        int dis2=abs(pos[i-1][1]-pos[i][0])+abs(pos[i-1][0]-pos[i][1]);
        dis[i]=dis[i-1]+min(dis1,dis2);
    }
    printf("%lld\n",dis[n]);
    return 0;
}
