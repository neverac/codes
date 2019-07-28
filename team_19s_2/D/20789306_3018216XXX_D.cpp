#include <iostream>
#include <string.h>
using namespace std;
int ans[1000];
const long long INF  = 99999999999;
long long maze[1000][1000];
bool visited[1000];
int n,m;
long long d[1000];
void dijkstrla(int s){
    for(int i = 0;i < n;i++){
        visited[i] = 0;
        d[i] = INF;
    }
    d[s] = 0;
    for(int i = 0;i < n;i++){
        int u = -1;
        long long minn = INF;
        for(int j = 0;j < n;j++){
            if(!visited[j] && d[j] < minn){
                minn = d[j];
                u = j;
            }
        }
        if(u == -1) break;
        visited[u] = 1;
        for(int j = 0;j < n;j++){
            if(!visited[j] && maze[u][j] + d[u] < d[j]){
                d[j] = d[u] + maze[u][j];
            }
        }
    }
    for(int i = 0;i < n;i++){
        if(d[i] != INF){
            ans[d[i]]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);

    while(cin >> n){
        if(n == 0) break;
        memset(ans,0,sizeof(ans));
        cin >> m;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                maze[i][j] = INF;
            }
        }
        for(int i = 0;i < m;i++){
            int u,v;
            cin >> u >> v;
            maze[u][v] = maze[v][u] = 1;
        }
        for(int i = 0;i < n;i++){
            dijkstrla(i);
        }
        for(int i = 1;i <= n;i++){
            if(ans[i] != 0){
                cout << i << " " << ans[i] << endl;
            }
        }
    }
    return 0;
}