#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define SIZE 1010
#define MOD 998244353

using namespace std;

int n,m;
int ans;
char map[SIZE][SIZE];
int step[SIZE][SIZE];
bool vis[SIZE][SIZE];
struct point
{
    int x,y;
    int steps;
}tmp;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool legal(int x,int y)
{
    if(x==0 || y==0)
        return false;
    if(x>n || y>m)
        return false;
    return !vis[x][y];
}
void bfs()
{
    int i,j;
    queue<point> que;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(map[i][j]=='#')
            {
                que.push({i,j,0});
                vis[i][j]=true;
            }
        }
    }
    while(!que.empty())
    {
        tmp=que.front();
        que.pop();
        ans=max(ans,tmp.steps);
        for(i=0;i<4;i++)
        {
            int tmpx=tmp.x+dir[i][0];
            int tmpy=tmp.y+dir[i][1];
            if(legal(tmpx,tmpy))
            {
                vis[tmpx][tmpy]=true;
                que.push({tmpx,tmpy,tmp.steps+1});
            }
        }
    }
    return ;
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%s",map[i]+1);
    bfs();
    printf("%d\n",ans);
    return 0;
}

