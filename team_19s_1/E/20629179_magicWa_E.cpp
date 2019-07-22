#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int num[233];
LL sum[105][105];
int l;
        
LL deal(int x, int y)
{
    LL ls = 0;
    ls = sum[2*l-1][2*l-1] * (x / (2*l)) * (y / (2*l)) + sum[x % (2*l)][y % (2*l)] + (x / (2 * l)) * sum[2*l-1][y % (2*l)] + (y / (2 * l)) * sum[x%(2*l)][2*l-1];
    return ls;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%d", &l);
        for (int i = 0; i < l; i++)
            scanf("%d", &num[i]);
        memset(sum, 0, sizeof(sum));
        int cursor = 0; 
        for (int i = 0; i <= 4*l; ++i) 
        {
            for (int j = 0; j <= i; ++j) 
            { 
                sum[j][i - j] = num[cursor];
                cursor = (cursor + 1) % l;
            }
        }
        for (int i = 0; i <= 2*l; i++)
        {
            for (int j = 0; j <= 2*l; j++)
            {
                sum[i][j] += sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
            }
        }
        int q, x1, y1, x2, y2;
        cin >> q;
        for (int i = 1; i <= q; i++)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            printf("%lld\n", deal(x2, y2) - deal(x1-1, y2) - deal(x2, y1-1) + deal(x1-1, y1-1));
        }
    }
    return 0;
}
