#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
int val[N];

int main()
{
    int n;
    scanf("%d", &n);
    
    int ans = 0;
    int amin = 1e4 + 4, ai, bmax = -1e4 - 4, bi;
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &val[i]);
        if (val[i] < amin) amin = val[i], ai = i;
        if (val[i] > bmax) bmax = val[i], bi = i;
        ans += abs(val[i]);
    }
    if (ai == bi) ai ++;
    if (amin >= 0) ans -= 2 * amin;
    if (bmax <= 0) ans += 2 * bmax;

    printf("%d\n", ans);
    for (int i = 1; i <= n; i ++)
    {
        if (i == ai || i == bi) continue;
        if (val[i] > 0)
        {
            printf("%d %d\n", amin, val[i]);
            amin -= val[i];
        }
        else
        {
            printf("%d %d\n", bmax, val[i]);
            bmax -= val[i];
        }
        // cout << i << endl;
    }
    printf("%d %d\n", bmax, amin);
}