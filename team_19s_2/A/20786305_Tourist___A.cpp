#include <bits/stdc++.h>

using namespace std;
int n, d;
int op[1005], gap;
vector<int> vvp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        if (n == 0)break;
        cin >> d;
        gap = 0;
        for (int i = 1; i <= n; i++)cin >> op[i];
        for (int i = 1; i < n; i++)gap = max(gap, abs(op[i] - op[i + 1]));
        if (gap <= d)cout << "Y\n";
        else {
            vvp.clear();
            for (int i = 1; i < n; i++)if (abs(op[i] - op[i + 1]) > d)vvp.push_back(i);
            if (vvp.size() > 2)cout << "N\n";
            else if (vvp.size() == 2 && vvp[0] + 1 != vvp[1])cout << "N\n";
            else {
                if (vvp.size() == 1) {
                    if (vvp[0] == 1)cout << "Y\n";
                    else if (abs(op[vvp[0] - 1] - op[vvp[0] + 1]) <= 2 * d)cout << "Y\n";
                    else if (vvp[0] == n - 1)cout << "Y\n";
                    else if (abs(op[vvp[0]] - op[vvp[0] + 2]) <= 2 * d)cout << "Y\n";
                    else cout << "N\n";
                } else {
                    if (abs(op[vvp[0]] - op[vvp[1] + 1]) <= 2 * d)cout << "Y\n";
                    else cout << "N\n";
                }
            };
        }
    }
    return 0;
}