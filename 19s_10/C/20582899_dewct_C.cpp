#include <bits/stdc++.h>
using namespace std;

int fst[433333], nxt[433333], tot = 0;

struct qer
{
    int f, t;
} es[433333];

void build(int f, int t)
{
    es[++tot] = (qer){f, t};
    nxt[tot] = fst[f];
    fst[f] = tot;
}

int ans = 0, st = 0;

void dfs(int u, int fa, int len)
{
    if (len > ans)
        st = u, ans = len;
    for (int i = fst[u]; i; i = nxt[i])
        if (es[i].t != fa)
            dfs(es[i].t, u, len + 1);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int f, t;
        scanf("%d%d", &f, &t);
        build(f, t);
        build(t, f);
    }
    dfs(1, 0, 0);
    ans = 0;
    dfs(st, 0, 0);
    if (ans % 3 == 1)
        puts("Second");
    else
        puts("First");
    return 0;
}