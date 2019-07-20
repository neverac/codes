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

int main()
{
    ll k, a, b;
    cin >> k >> a >> b;
    ll ans = 1;
    ll hhh = b - a;
    if (hhh <= 2 || k <= (a - 1))
    {
        ans += k;
    }
    else
    {
        ans += (a - 1);
        k -= (a - 1);
        ans += (k / 2) * hhh;
        ans += k % 2;
    }
    cout << ans << endl;
}