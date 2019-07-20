#include <stdio.h>
using namespace std;
const int N = 2e5 + 5;
char s[N], t[N];

int main()
{
    int h, w, n, x, y;
    scanf("%d%d%d%d%d%s%s", &h, &w, &n, &x, &y, &s, &t);

    bool flag = true;
    int l = y, r = y, u = x, d = x;
    for (int i = 0; i < n; i ++)
    {
        switch (s[i])
        {
        case 'U': u--; break;
        case 'D': d++; break;
        case 'R': r++; break;
        case 'L': l--; break;
        }
        if (u == 0 || d == h + 1 || l == 0 || r == w + 1)
        {
            flag = false;
            break;
        }
        switch (t[i])
        {
        case 'U': if(d != 1) d--; break;
        case 'D': if(u != h) u++; break;
        case 'R': if(l != w) l++; break;
        case 'L': if(r != 1) r--; break;
        }
    }
    if (flag) printf("YES\n");
    else printf("NO\n");
}