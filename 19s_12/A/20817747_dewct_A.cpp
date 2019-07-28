#include <bits/stdc++.h>
using namespace std;

int num[23];
int used[2333333];

int main()
{
    int a, b;
    cin >> a >> b;
    a *= 10;
    while (a)
    {
        // cout << (int)(ls * 10) << endl;
        num[a / b] = 1;
        if (used[a % b] == 1)
            break;
        int ls = a % b;
        // cout << ls << endl;
        used[ls] = 1;
        a = ls * 10;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (num[i])
            cout << i;
    }
    return 0;
}