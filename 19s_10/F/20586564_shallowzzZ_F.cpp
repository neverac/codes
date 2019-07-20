#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1005;
const int INF=0x3f3f3f3f;
bool vis[MAXN];
int cost[MAXN][MAXN];
int sl[MAXN], tl[MAXN];
int n,m,x,y,s,t,ans;

void Dijkstra(int lowcost[],int beg){
    for(int i=1;i<=n;i++){
        lowcost[i]=cost[beg][i];vis[i]=false;
    }
    vis[beg]=true;
    for(int j=1;j<=n;j++){
        int k= -1;
        int Min=INF;
        for(int i=1;i<=n;i++)
            if(!vis[i]&&lowcost[i]<Min){
                Min=lowcost[i];
                k=i;
            }
        if(k==-1)break;
        vis[k]=true;
        for(int i=1;i<=n;i++)
            if(!vis[i]&&lowcost[k]+cost[k][i]<lowcost[i]){
                lowcost[i]=lowcost[k]+cost[k][i];
            }
    }
}

int main(){
    cin >> n >> m >> s >> t;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++)
            cost[i][j]=cost[j][i]=INF;
        cost[i][i]=0;
    }

    for(int i=1;i<=m;i++){
        cin >> x >> y;
        cost[x][y]=cost[y][x]=1;
    }
    Dijkstra(sl,s);
    memset(vis,false,sizeof(vis));
    Dijkstra(tl,t);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(cost[i][j]==INF && sl[i]+tl[j]+1>=sl[t] && sl[j]+tl[i]+1>=sl[t])
                ans++;
        }
    }
    cout << ans << endl;
}
