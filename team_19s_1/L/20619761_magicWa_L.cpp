#include <bits/stdc++.h>
using namespace std;

int num[233333];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &num[i]);
        cout << (int)(sqrt(abs(num[n] - num[1]))) << endl;
    }
    return 0;
}