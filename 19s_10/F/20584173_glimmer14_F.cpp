#include <iostream>
#include <cstring>
using namespace std;
const int N = 1010;

const int INF = 0x3f3f3f3f;
bool vis[N];

int cost [N][N];
int ss[N], tt[N];

void Dijkstra(int* lowcost, int n, int beg)
{
    for (int i = 1; i <= n; i++)
    {
        lowcost[i] = INF;
        vis[i] = false;
    }
    lowcost[beg] = 0;
    for (int j = 1; j <= n; j++)
    {
        int k = -1;
        int Min = INF;
        for (int i = 1; i <= n; i++)
            if (!vis[i] && lowcost[i] < Min)
            {
                Min = lowcost[i];
                k = i;
            }
        if (k == -1)
            break;
        vis[k] = true;
        for (int i = 1; i <= n; i++)
            if (!vis[i] && lowcost[k] + cost[k][i] < lowcost[i])
                lowcost[i] = lowcost[k] + cost[k][i];
    }
}

int main()
{
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    memset(cost, INF, sizeof cost);
    int u, v;
    for (int i = 0; i < m; i ++)
    {
        scanf("%d%d", &u, &v);
        cost[u][v] = 1;
        cost[v][u] = 1;
    }
    Dijkstra(ss, n, s);
    Dijkstra(tt, n, t);

    int ll = ss[t], ans = 0;
    // cout << ss[t] << tt[s];
    for (int i = 1; i < n; i ++)
        for (int j = i + 1; j <= n; j ++)
        {
            if (cost[i][j] == INF)
            {
                if ((ss[i] + tt[j] + 1) >= ll && (ss[j] + tt[i] + 1) >= ll) ans ++;
            }
        }
    cout << ans << endl;
}