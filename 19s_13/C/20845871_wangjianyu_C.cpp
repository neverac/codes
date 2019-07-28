#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define SIZE 60

using namespace std;

struct point
{
    int x,y;
};
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char map[SIZE][SIZE]={"11111111111111111111111111111111111111111111111111111111111"};
point rec[2][SIZE*SIZE];
bool vis[SIZE][SIZE];
int cnt[2];

bool bfs(int x,int y,int a)
{
    queue<point> que;
    point tmp,temp;
    tmp.x=x;
    tmp.y=y;
    que.push(tmp);
    vis[x][y]=true;
    while(!que.empty())
    {
        tmp=que.front();
        que.pop();
        rec[a][cnt[a]]=tmp;
        cnt[a]++;
        for(int i=0;i<4;i++)
        {
            temp.x=tmp.x+dir[i][0];
            temp.y=tmp.y+dir[i][1];
            if(!vis[temp.x][temp.y] && map[temp.x][temp.y]=='0')
            {
                vis[temp.x][temp.y]=true;
                que.push(temp);
            }
        }
    }
    return false;
}
int main()
{
    int i,n,j;
    int sx,sy,tx,ty;
    int tmp;
    scanf("%d",&n);
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
    for(i=1;i<=n;i++)
    {
        map[i][0]='1';
        scanf("%s",map[i]+1);
        map[i][n+1]='1';
    }
    for(i=1;i<=n;i++)
        map[n+1][i]='1';
    bfs(sx,sy,0);
    if(vis[tx][ty])
    {
        printf("0\n");
        return 0;
    }
    bfs(tx,ty,1);
    int ans=999999999;
  //  printf("cnt0=%d cnt1=%d\n",cnt[0],cnt[1]);
    for(i=0;i<cnt[0];i++)
        for(j=0;j<cnt[1];j++)
            ans=min(ans,(rec[0][i].x-rec[1][j].x)*(rec[0][i].x-rec[1][j].x)
                    +(rec[0][i].y-rec[1][j].y)*(rec[0][i].y-rec[1][j].y));
    printf("%d\n",ans);
    return 0;
}
