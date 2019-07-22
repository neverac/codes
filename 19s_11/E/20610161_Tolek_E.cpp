#include <bits/stdc++.h>

using namespace std;
int op[100005], op2[100005], op3[100005], op4[100005], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> op[i];
        op3[i] = op4[n - i + 1] = op2[n - i + 1] = op[i];
    }
    int now = 0, a, b;
    sort(op + 1, op + n + 1);
    for (int i = 1; i <= n; i++) {
        if (op[i] != op3[i]) {
            ++now, a = i;
            for (int j = i + 1; j <= n; j++) {
                if (op[j] != op3[j] && now == 1)++now, b = j;
                else if (op[j] != op3[j]) {
                    ++now;
                    goto to;
                }
            }
            break;
        }
    }
    to:
    sort(op2 + 1, op2 + n + 1);
    int now2 = 0, a2, b2;
    for (int i = 1; i <= n; i++) {
        if (op2[i] != op4[i]) {
            ++now2, a2 = i;
            for (int j = i + 1; j <= n; j++) {
                if (op2[j] != op4[j] && now2 == 1)++now2, b2 = j;
                else if (op2[j] != op4[j]) {
                    ++now2;
                    goto to2;
                }
            }
            break;
        }
    }
    to2:;
    if (now == 0 || now2 == 0) {
        cout << "Nothing to do here";
        return 0;
    } else if (now == 2 || now2 == 2) {
        if (now == 2)cout << "Yes" << endl << a << " " << b;
        else cout << "Yes" << endl << n - b2 + 1 << " " << n - a2 + 1;
    } else {
        cout << "No hope";
    }
    return 0;
}