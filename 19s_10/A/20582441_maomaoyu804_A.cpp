#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

//char s[1003][1003];
int vis[1003][1003];
struct node
{
    int x;int y;
};

int main()
{
    int h,w;
    cin>>h>>w;
    queue<node> q;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char s;cin>>s;
            if(s=='#'){
                node a;a.x=i;a.y=j;
                q.push(a);
                vis[i][j]=1;
            }
        }
    }
    while(!q.empty()){
        node a;a=q.front();q.pop();
        if(a.x>0&&!vis[a.x-1][a.y]){
            vis[a.x-1][a.y]=vis[a.x][a.y]+1;
            node b;b.x=a.x-1;b.y=a.y;
            q.push(b);
        }
        if(a.y>0&&!vis[a.x][a.y-1]){
            vis[a.x][a.y-1]=vis[a.x][a.y]+1;
            node b;b.x=a.x;b.y=a.y-1;
            q.push(b);
        }
        if(a.x<h-1&&!vis[a.x+1][a.y]){
            vis[a.x+1][a.y]=vis[a.x][a.y]+1;
            node b;b.x=a.x+1;b.y=a.y;
            q.push(b);
        }
        if(a.y<w-1&&!vis[a.x][a.y+1]){
            vis[a.x][a.y+1]=vis[a.x][a.y]+1;
            node b;b.x=a.x;b.y=a.y+1;
            q.push(b);
        }
    }
    int ans=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            ans=max(ans,vis[i][j]);
            //cout<<vis[i][j];
        }
        //cout<<endl;
    }
    cout<<ans-1<<endl;
    return 0;
}
