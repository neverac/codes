#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int lx, ly, lz;
    cin >> lx >> ly >> lz;
    if (x > lx)
    {
        puts("NO");
        return 0;
    }
    else
    {
        lx -= x;
        if (lx > 0)
            y -= lx, lx = 0;
        ly -= y;
        if (lx > 0)
            z -= lx;
        if (ly > 0)
            z -= ly;
        if (lz > 0)
            z -= lz;
    }
    if (ly < 0 || z > 0)
        puts("NO");
    else
    {
        puts("YES");
    }
    return 0;
}