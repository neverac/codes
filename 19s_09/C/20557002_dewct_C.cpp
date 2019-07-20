#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool flag = 0;
        for (int i = 1; i <= 400; i++)
        {
            for (int j = 1; j < i - 1; j++)
            {
                if (180 * j / i == n && 180 * j % i == 0)
                {
                    cout << i << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
    }
    return 0;
}