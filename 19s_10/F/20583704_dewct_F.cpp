#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int fst[233333], nxt[233333], d[233333], tot = 0;
bool used[233333];
int ans1[233333], ans2[233333];
bool mm[1050][1050];

struct edge
{
    int f, t;
} es[233333];

queue<int> q;

void init()
{
    memset(fst, -1, sizeof(fst));
    memset(d, 0x3f, sizeof(d));
    tot = 0;
}

void build(int f, int t)
{
    es[++tot] = (edge){f, t};
    nxt[tot] = fst[f];
    fst[f] = tot;
}

void spfa(int s)
{
    used[s] = 1;
    d[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        used[u] = 0;
        q.pop();
        for (int i = fst[u]; i != -1; i = nxt[i])
        {
            int v = es[i].t;
            if (d[v] > d[u] + 1)
            {
                d[v] = d[u] + 1;
                if (!used[v])
                {
                    used[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    init();
    int t, c, ts, te;
    cin >> t >> c >> ts >> te;
    memset(mm, 0, sizeof(mm));
    for (int i = 1; i <= c; i++)
    {
        int f, t;
        scanf("%d%d", &f, &t);
        build(f, t);
        build(t, f);
        mm[f][t] = 1;
        mm[t][f] = 1;
    }
    spfa(ts);
    int lsans = d[te];
    for (int i = 1; i <= t; i++)
    {
        ans1[i] = d[i];
    }
    memset(d, 0x3f, sizeof(d));
    spfa(te);
    for (int i = 1; i <= t; i++)
    {
        ans2[i] = d[i];
    }
    int ans = 0;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (i != j && !mm[i][j] && !mm[j][i])
            {
                if (ans1[i] + ans2[j] + 1 < lsans)
                    mm[i][j] = 1, mm[j][i] = 1, ans++;
            }
        }
    }
    cout << t * (t - 1) / 2 - c - ans;
    return 0;
}
