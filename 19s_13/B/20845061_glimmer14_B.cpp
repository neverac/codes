#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e5 + 5;
int p[N], q[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n;
    for (int i = 1; i <= 2 * n; i ++)
    {
        cin >> x;
        if (p[x]) q[x] = i;
        else p[x] = i;
    }
    long long  ans = abs(p[1] -1) + abs(q[1] - 1);
    for (int i = 1; i < n; i ++)
    {
        ans += min(abs(p[i] - p[i + 1]) + abs(q[i] - q[i + 1]), abs(p[i] - q[i + 1]) + abs(q[i] - p[i + 1]));
    }
    cout << ans << endl;
    
}