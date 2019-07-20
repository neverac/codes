#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500005;
int head[N];
int to[N];
int edge[N];
int Next[N];
int cnt;

void add(int x,int y){
    to[++cnt]=y;
    Next[cnt]=head[x];
    head[x]=cnt;
}

ll ans;
int d[N];
bool vis[N];
void dfs(int x){
    vis[x]=1;
    for(int i=head[x];i;i=Next[i]){
        int y=to[i];
        if(vis[y])continue;
        d[y]=d[x]+1;
        if(d[y]>d[ans])ans=y;
        dfs(y);
    }
}
int x,y;
int main(){
    int n;
    ans=0;
    d[0]=0;
    cin >> n;
    for(int i=1;i<n;++i){
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1);
    memset(d,0,sizeof(d));
    memset(vis,0,sizeof(vis));
    dfs(ans);
    if(d[ans]%3==1) cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}
