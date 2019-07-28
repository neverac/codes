#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define maxn 1000005
#define R register
#define debug(x, y) cout << x << " " << y << endl
#define ll long long
using namespace std;
struct Edge{
    int next, to, c;
}e[maxn];
int n, m, k;
int head[maxn], cnt;
int dep[maxn];
int dx[8] = {1,1,-1,-1,2,2,-2,-2};
int dy[8] = {2,-2,2,-2,1,-1,1,-1};
bool vis[300][300];

int s, t;
inline void adde(int from, int to, int fl){
    e[++cnt].to = to;
    e[cnt].next = head[from];
    e[cnt].c = fl;
    head[from] = cnt;
}
void add(int from, int to, int c){
    adde(from, to, c);
    adde(to, from, 0);
}
int pos(int x, int y){
    return (x - 1) * n + y;
}
inline int bfs(){
    memset(dep, 0, sizeof(dep));
    queue<int> que;
    que.push(s);
    dep[s] = 1;
    while(!que.empty()){
        int x = que.front(); que.pop();
        for(R int i = head[x]; i; i = e[i].next){
            if(e[i].c > 0 && !dep[e[i].to]){
                dep[e[i].to] = dep[x] + 1;
                que.push(e[i].to);
            }
        }
    }
    return dep[t];
}
int dfs(int now, int flow){
    if(now == t) return flow;
    int ret = 0;
    for(R int i = head[now]; i; i = e[i].next){
        if(ret == flow) return flow;
        if(dep[e[i].to] == dep[now] + 1 && e[i].c > 0){
            int fl = dfs(e[i].to, min(flow, e[i].c));
            if(fl > 0){
                ret += fl;
                e[i].c -= fl;
                e[i ^ 1].c += fl;
            }
        }
    }
    if(!ret) dep[now] = 0;
    return ret;
}
inline int  dinic(){
    int ans = 0;
    while(bfs()){
        int x = 1;
        while(x){
            x = dfs(s, INF);
            ans += x;
        }
    }
    return ans;
}
int main(){
    while(~scanf("%d", &n) && n){
        memset(vis, false, sizeof(vis));
        memset(head, 0, sizeof(head));
        cnt = 1;
        scanf("%d%d", &m, &k);
        s = 100; t = 200;
        for(int i = 0; i < n; i++){
            add(s, i, 1);
        }
        for(int i = 0; i < m; i++){
            add(i + 30, t, 1);
        }
        while(k--){
            int x, y;
            scanf("%d%d", &x, &y);
            add(x, y + 30, INF);
        }
        printf("%d\n", dinic());
    }
    return 0;
}
