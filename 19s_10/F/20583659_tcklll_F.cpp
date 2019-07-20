#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#define sf(n) scanf("%d",&n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define ll long long
#define MAXL 1000000
#define eps 1e-6
#define INF 1000000000
#define MAXN 100000
#define mod 998244353
using namespace std;
struct edge {int to,cost;};//边的下一个节点to，边权cost
typedef pair<int,int> P; //first是最短距离，second是顶点的编号
vector<edge> G[MAXN];
int d[MAXN];
int dd[MAXN];
void dijkstra1(int s)
{
    priority_queue<P,vector<P>,greater<P> > q;
    d[s] = 0;
    q.push(P(0,s));
    while(!q.empty())
    {
        P p = q.top(); q.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                q.push(P(d[e.to],e.to));
            }
        }
    }
}
void dijkstra2(int s)
{
    priority_queue<P,vector<P>,greater<P> > q;
    dd[s] = 0;
    q.push(P(0,s));
    while(!q.empty())
    {
        P p = q.top(); q.pop();
        int v = p.second;
        if (dd[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if (dd[e.to] > dd[v] + e.cost)
            {
                dd[e.to] = dd[v] + e.cost;
                q.push(P(dd[e.to],e.to));
            }
        }
    }
}
bool f[1005][1005]={0};
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    int s,t;sff(s,t);
    for(int i=0;i<m;i++)
    {
        int p,q;scanf("%d%d",&p,&q);
        f[p][q]=1;f[q][p]=1;
        edge e={q,1};//单向
        G[p].push_back(e);
        e={p,1};
        G[q].push_back(e);
    }
    for(int i=1;i<=n;i++)
        d[i]=INF;
    dijkstra1(s);
    for(int i=1;i<=n;i++)
        dd[i]=INF;
    dijkstra2(t);
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(f[i][j]==0){
                //cout<<"??"<<i<<"  "<<j<<endl;
                int er1=d[i]+dd[j]+1,er2=d[j]+dd[i]+1;
                //cout<<er1<<"  "<<er2<<endl;
                if(er1>=d[t]&&er2>=d[t])sum++;
            }
        }
    }
    //printf("%d\n",d[n]);
    printf("%d\n",sum);
}
/*
5 5 2 5
1 2
2 3
3 4
4 5
5 1
*/
