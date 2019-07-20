#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#define SIZE 200010

using namespace std;

int n;
int dis[SIZE];
bool vis[SIZE];
vector<int> rec[SIZE];

struct d
{
    int id,dist;
};
int bfs(int from)
{
    int i;
    d tmp;
    queue<d> que;
  //  dis[from]=0;
    que.push({from,1});
    vis[from]=true;
    while(!que.empty())
    {
        tmp=que.front();
    //    printf("id=%d\n",tmp.id);
        que.pop();
        dis[tmp.id]=tmp.dist;
        for(i=rec[tmp.id].size()-1;i>=0;i--)
        {
            if(!vis[rec[tmp.id][i]])
            {
                vis[rec[tmp.id][i]]=true;
                que.push({rec[tmp.id][i],tmp.dist+1});
            }
        }
    }
    return tmp.id;
}

int main()
{
    int i;
    int a,b;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        rec[a].push_back(b);
        rec[b].push_back(a);
    }
    int pos=bfs(1);
    memset(vis,false,sizeof(vis));
    pos=bfs(pos);
    if((dis[pos]+1)%3==0)
        puts("Second");
    else
        puts("First");
    return 0;
}
