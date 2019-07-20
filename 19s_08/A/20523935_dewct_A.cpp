#include <bits/stdc++.h>
using namespace std;

int t[50];

int main()
{
    int n, ans = 0;
    cin >> n;
    int ls = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &ls);
        if (ls == 4)
            t[ls]++;
        if (ls == 8)
        {
            if (t[4])
                t[4]--, t[ls]++;
        }
        if (ls == 15)
        {
            if (t[8])
                t[8]--, t[ls]++;
        }
        if (ls == 16)
        {
            if (t[15])
                t[15]--, t[ls]++;
        }
        if (ls == 23)
        {
            if (t[16])
                t[16]--, t[23]++;
        }
        if (ls == 42)
        {
            if (t[23])
                t[23]--, ans++;
        }
    }
    cout << n - ans * 6;
    return 0;
}