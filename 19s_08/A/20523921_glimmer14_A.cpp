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
const int N = 5e5 + 5;
int val[N];
int cnt[45];
const int num[6] = {4, 8, 15, 16, 23, 42};

int get(int x)
{
    for (int i = 0; i < 6; i ++)
        if (num[i] == x) return i;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &val[i]);
    
    int ans = 0;
    int pre, nn;
    for (int i = 1; i <= n; i ++)
    {
        if (val[i] == 4)
        {
            cnt[val[i]] ++;
            continue;
        }
        pre = num[get(val[i]) - 1];
        if (cnt[val[i]] + 1 > cnt[pre]) ans ++;
        else cnt[val[i]] ++;
    }
    for (int i = 4; i >= 0; i --)
    {
        ans += (cnt[num[i]] - cnt[num[5]]);
    }
    cout << ans << endl;
}
