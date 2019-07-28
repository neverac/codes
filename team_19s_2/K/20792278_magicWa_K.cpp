#include <bits/stdc++.h>
using namespace std;

int M[50][50], d[350], n, m;

bool dfs(int x)
{
    for (int i = 0; i < x; i++)
    {
        if (M[x][i] && d[x] == d[i])
            return 0;
    }
    if (x == n )
        return 1;
    for (int i = 1; i <= 3; i++)
    {
        d[x + 1] = i;
        if (dfs(x + 1))
            return 1;
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(M, 0, sizeof(M));
        memset(d, 0, sizeof(d));
        scanf("%d%d", &n, &m);
        int ff, tt;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &ff, &tt);
            M[ff][tt] = 1;
            M[tt][ff] = 1;
        }
        bool flag = 0;
        d[0] = 1;
        flag = dfs(0);
        if (flag)
            puts("Y");
        else
            puts("N");
    }
    return 0;
}
/*
100
6 
6 
0 3 
1 5 
3 2 
2 5 
0 4 
1 0 
7 
12 
6 5 
0 3 
2 6 
3 5 
5 0 
0 4 
4 5 
6 3 
1 4 
1 2 
3 4 
2 3 
7 
8 
6 5 
0 3 
2 6 
3 5 
1 4 
1 2 
3 4 
2 3 
6 
9 
0 1 
1 2 
2 3 
5 2 
5 3 
3 4 
2 4 
1 4 
4 5

 */