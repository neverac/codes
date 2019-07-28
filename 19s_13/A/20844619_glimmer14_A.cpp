// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int N = 100 + 5;


int main()
{
    int n;
    cin >> n;
    int x, po = 0, ne = 0;
    for (int i = 0; i < n; i ++)
    {
        cin >> x;
        if (x > 0) po ++;
        else if (x < 0) ne ++;
    }
    int ans = n / 2 + n % 2;
    // cout << ans << endl;
    if (po >= ans) cout << 1 << endl;
    else if(ne >= ans) cout << -1 << endl;
    else cout << 0 << endl;
}