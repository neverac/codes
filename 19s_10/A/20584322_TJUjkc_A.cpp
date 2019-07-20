#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<stdlib.h>
using namespace std;


struct node{
    int x,y,cnt;
};
int n,m;
int ans;
queue<node> q;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int vis[1005][1005];

int main(){
    cin>>n>>m;
    ans=0;
    memset(vis,-1,sizeof(vis));
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=m;j++){
            if(s.at(j-1)=='#'){
                vis[i][j]=1;
                node a;
                a.x=i;
                a.y=j;
                a.cnt=0;
                q.push(a);
            }
            else{
                vis[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        node a=q.front();
        q.pop();
        ans=max(ans,a.cnt);
        for(int i=0;i<4;i++){
            node b=node{a.x+dx[i],a.y+dy[i],a.cnt+1};
            if (vis[b.x][b.y]==0){
                vis[b.x][b.y]=1;
                q.push(b);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
