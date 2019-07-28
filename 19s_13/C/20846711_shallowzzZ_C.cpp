#include<iostream>
#include<queue>
#define ll long long
using namespace std;

int dir[4][2]={1,0,-1,0,0,1,0,-1};
typedef struct Node{
    int x,y;
}Node;
queue<Node> q;
queue<Node> qq;
Node e[3000];
int top,n,ans,r1,r2,c1,c2;
bool vis[55][55], vis2[55][55];
char mmp[55][55];

void check(Node m){
    for(int i=1;i<=top;i++){
        ans=min(ans,(m.x-e[i].x)*(m.x-e[i].x)+(m.y-e[i].y)*(m.y-e[i].y));
    }
    return ;
}

void bfs(){
    q.push(Node{r1,c1});
    vis[r1][c1]=true;
    while(!q.empty()){
        Node p=q.front();
        q.pop();
        check(p);
        for(int i=0;i<4;i++){
            int xx=p.x+dir[i][0];
            int yy=p.y+dir[i][1];
            if(xx<1 || xx>n || yy<1 || yy>n || mmp[xx][yy]=='1') continue;
            if(!vis[xx][yy]) q.push(Node{xx,yy}), vis[xx][yy]=true;
        }
    }
}

void bfs2(){
    qq.push(Node{r2,c2});
    vis2[r2][c2]=true;
    e[++top]=Node{r2,c2};
    while(!qq.empty()){
        Node pp=qq.front();
        qq.pop();
        for(int i=0;i<4;i++){
            int xx=pp.x+dir[i][0];
            int yy=pp.y+dir[i][1];
            if(xx<1 || xx>n || yy<1 || yy>n || mmp[xx][yy]=='1') continue;
            if(!vis[xx][yy]) qq.push(Node{xx,yy}),e[++top]=Node{xx,yy}, vis[xx][yy]=true;
        }
    }
    return ;
}

int main(){
    cin >> n >> r1 >> c1 >> r2 >> c2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> mmp[i][j];
        }
    }
    ans=1000000007;
    bfs2();
    bfs();
    cout << ans << endl;
    return 0;
}
