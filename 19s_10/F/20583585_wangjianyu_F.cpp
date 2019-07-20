#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define SIZE 1010
#define MAX 10000000
using namespace std;

int n;
int map[SIZE][SIZE];
bool ma[SIZE][SIZE];
bool vis[SIZE];
int dis1[SIZE];
int disn[SIZE];

void djs(int from)
{
    int i,cyc;
    int cen=from;
    memset(vis,false,sizeof(vis));
    vis[from]=true;
    for(i=1;i<=n;i++)
        dis1[i]=map[from][i];
    for(cyc=1;cyc<=n;cyc++)
    {
  //      printf("cen=%d\n",cen);
        int pos;
        int dis=MAX;
        for(i=1;i<=n;i++)
        {
            if(!vis[i] && dis1[i]<dis)
            {
                dis=dis1[i];
                pos=i;
            }
        }
        vis[pos]=true;
        for(i=1;i<=n;i++)
        {
            if(!vis[i] && dis1[pos]+map[pos][i]<dis1[i])
            {
                dis1[i]=dis1[pos]+map[pos][i];
         //       map[i][from]=map[from][i];
            }
        }
    }
}
void djt(int from)
{
    int i,cyc;
    int cen=from;
    memset(vis,false,sizeof(vis));
    vis[from]=true;
    for(i=1;i<=n;i++)
        disn[i]=map[from][i];
    for(cyc=1;cyc<=n;cyc++)
    {
  //      printf("cen=%d\n",cen);
        int pos;
        int dis=MAX;
        for(i=1;i<=n;i++)
        {
            if(!vis[i] && disn[i]<dis)
            {
                dis=disn[i];
                pos=i;
            }
        }
        vis[pos]=true;
        for(i=1;i<=n;i++)
        {
            if(!vis[i] && disn[pos]+map[pos][i]<disn[i])
            {
                disn[i]=disn[pos]+map[pos][i];
         //       map[i][from]=map[from][i];
            }
        }
    }
}
void print()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            //printf("%11d ",map[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i,m,j,k,s,t;
    int from,to;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    memset(map,0x7f,sizeof(map));
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&from,&to);
        map[from][to]=1;
        map[to][from]=1;
        ma[from][to]=true;
        ma[to][from]=true;
    }
    memset(vis,false,sizeof(vis));
    djs(s);
  //  for(i=1;i<=n;i++)
 //       printf("to->%d %d\n",i,dis1[i]);
    memset(vis,false,sizeof(vis));
    djt(t);
  //  for(i=1;i<=n;i++)
  //      printf("to->%d %d\n",i,disn[i]);
    dis1[s]=0;
    disn[t]=0;
   // print();
    int ans=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            if(ma[i][j])
                continue;
            if(dis1[i]+disn[j]+1>=dis1[t] && dis1[j]+disn[i]+1>=dis1[t])
            {
       //         printf("new %d-%d\n",i,j);
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
