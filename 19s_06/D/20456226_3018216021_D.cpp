#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 32000 + 77;

int x, y, z;
int a, b, c;
bool flag = false;

int main()
{
    ios::sync_with_stdio(false);
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    if (x <= a)
    {
        a -= x;
        if (y <= a + b)
        {
            c = c + a + b - y;
            if (z <= c)
                flag = true;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}