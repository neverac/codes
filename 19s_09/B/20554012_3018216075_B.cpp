#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mode = 998244353;

char a[200010], pos1, pos2;

int main() {
    ll len, cnt1 = 0, cnt2 = 0, ans = 0;
    bool f1 = true, f2 = true;
    char s, l;
    cin >> len;
    cin >> a;
    s = a[0];
    l = a[len - 1];
    for (int i = 0; i < len; i++) {
        if (f1 && a[i] == s) {
            cnt1++;
        } else {
            f1 = false;
        }
        if (f2 && a[len - i - 1] == l) {
            cnt2++;
        } else {
            f2 = false;
        }
        if (!f1 && !f2) {
            break;
        }
    }
    cnt1 %= mode;
    cnt2 %= mode;
    if (s == l) {
        ans += cnt2 + 1 + cnt1;
        ans %= mode;
        ans += (cnt1 * cnt2) % mode;
        ans %= mode;
    } else {
        ans += cnt1 + cnt2 + 1;
        ans %= mode;
    }

    cout << ans << endl;
    return 0;
}