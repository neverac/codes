#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn  = 1e5+5;
typedef struct node{
    int x, y;
}node;
node a[1000005];
int top,topp,h,w,cnt,toppp;
int vis[1005][1005];
char m[1005][1005];
void bfs(){
    topp=top; toppp=1;
    while(top<h*w){
        for(int i=toppp;i<=top;i++){
            if(!vis[a[i].x+1][a[i].y] && a[i].x+1<=h){
                vis[a[i].x+1][a[i].y]=1;
                a[++topp]=node{a[i].x+1,a[i].y};
            }
            if(!vis[a[i].x-1][a[i].y] && a[i].x-1>=1) {
                vis[a[i].x-1][a[i].y]=1;
                a[++topp]=node{a[i].x-1,a[i].y};
            }
            if(!vis[a[i].x][a[i].y+1] && a[i].y+1<=w){
                vis[a[i].x][a[i].y+1]=1;
                a[++topp]=node{a[i].x,a[i].y+1};
            }
            if(!vis[a[i].x][a[i].y-1] && a[i].y-1>=1){
                vis[a[i].x][a[i].y-1]=1;
                a[++topp]=node{a[i].x,a[i].y-1};
            }
        }
        toppp=top;
        top=topp;
        cnt++;
    }
    cout << cnt << endl;
}
int main(){
    cin >> h >> w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> m[i][j];
            if(m[i][j]=='#') a[++top]=node{i,j},vis[i][j]=1;
        }
    }
    bfs();
    return 0;
}
