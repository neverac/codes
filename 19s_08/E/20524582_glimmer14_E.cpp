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
const int N = 100 + 5;
int val[N];

int cnt[3];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int x;
        cnt[0] = cnt[1] = cnt[2] = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &x), cnt[x % 3] ++;
        
        int ans = cnt[0];
        if (cnt[1] <= cnt[2])
        {
            ans += cnt[1];
            ans += (cnt[2] - cnt[1]) / 3;
        } 
        else
        {
            ans += cnt[2];
            ans += (cnt[1] - cnt[2]) / 3;
        }
        cout << ans << endl;
    }
}