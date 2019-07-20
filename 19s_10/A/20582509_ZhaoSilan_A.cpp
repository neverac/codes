#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <ctype.h>
using namespace std;
int n,m,a,b,c;

struct Node
{
    int x,y,z;
    Node(){}
    Node(int a,int b,int c): x(a), y(b),z(c) {}
};

bool vis[1005][1005];
int dirx[] = {0,1,0,-1};
int diry[] = {1,0,-1,0};

char ma[1005][1005];


int bfs()
{
    queue<Node>Q;
    int ans=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(ma[i][j]=='#')
    {
    	Q.push(Node(i,j,0));
    	ans++;
    	vis[i][j]=1;
    }
    
    if(ans==n*m)
    return 0;
    
    while(!Q.empty())
    {
        Node node=Q.front(); 
		Q.pop();
        int x=node.x,y=node.y,z=node.z; 
        for(int i=0;i<4;i++)//四个方向 
        {
            int nx=x+dirx[i],ny=y+diry[i],nz=z+1;
            
            if(nx<1||nx>n||ny<1||ny>m) continue;
            if(vis[nx][ny]) continue;
//            printf("%d %d",ans,nz);
            vis[nx][ny]=1;
            ans++;
            if(ans==n*m)
            return nz;
            Q.push(Node(nx,ny,nz));
        }
    }
}


int main()
{
    scanf("%d%d\n", &n,&m); 
    for(int i=1;i<=n;i++)
    scanf("%s",ma[i]+1);
    
    int t = bfs();
    printf("%d\n",t);
    return 0;
}