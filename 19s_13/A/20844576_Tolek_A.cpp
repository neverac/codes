#include <bits/stdc++.h>

using namespace std;
int op[500], n;
int s1, s2, xian;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> op[i];
    for (int i = 1; i <= n; i++)if (op[i] > 0)s1++; else if (op[i] < 0)s2++;
    xian = n % 2 == 0 ? n / 2 : n / 2 + 1;
    if (s1 >= xian || s2 >= xian) {
        if (s1 >= xian)cout << 1;
        else if (s2 >= xian)cout << -1;
    } else cout << 0;
    return 0;
}