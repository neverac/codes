#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 110;

int a[maxn];

int main() {
    int n, t, temp;
    cin >> t;
    while (t--) {
        cin >> n;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            a[i] = temp % 3;
            if (a[i] == 1) {
                cnt1++;
            } else if (a[i] == 2) {
                cnt2++;
            } else {
                cnt3++;
            }
        }
        ans = cnt3;
        if (cnt1 >= cnt2) {
            cnt1 -= cnt2;
            ans += cnt2 + cnt1 / 3;
        } else {
            cnt2 -= cnt1;
            ans += cnt1 + cnt2 / 3;
        }

        cout << ans << endl;
    }


    return 0;
}