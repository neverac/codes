#include <iostream>

using namespace std;
typedef long long ll;
ll lll[11];
ll t, l, q;
ll x0, y0, x1, y1;

ll getpos(int i, int j) {
    ll n = i + j + 1;
    return (n + 1) * n / 2 - j - 1;
}

ll sum[22][22];
ll aa[22];

ll solve() {
    ll pos = getpos(x0, y0);
    long long pp;
    for (int i = 0; i < 2 * l; i++) {
        pp = pos;
        sum[i][0] = lll[pos % l];
        for (int j = 1; j < 2 * l; j++) {
            pp += i + x0 + y0 + j;
            sum[i][j] = sum[i][j - 1] + lll[pp % l];
        }
        pos += (x0 + y0 + i + 2);
    }
//    for (int i = 0; i < 2 * l; i++) {
//        for (int j = 0; j < 2 * l; j++)cout << sum[i][j] << " ";
//        cout << endl;
//    }
    ll a = (y1 - y0 + 1) / (2 * l), b = (y1 - y0 + 1) % (2 * l);
    aa[0] = a * sum[0][2 * l - 1];
    if (b > 0)
        aa[0] += sum[0][b - 1];
    for (int i = 1; i < 2 * l; i++) {
        aa[i] = aa[i - 1] + a * sum[i][2 * l - 1];
        if (b > 0)
            aa[i] += sum[i][b - 1];
    }

    a = (x1 - x0 + 1) / (2 * l), b = (x1 - x0 + 1) % (2 * l);
    ll ans = 0;
    ans += a * aa[2 * l - 1];
    if (b > 0)
        ans += aa[b - 1];
    return ans;

}

int main() {
    ll ans;
    cin >> t;
    while (t--) {
        cin >> l;
        for (int i = 0; i < l; i++)
            cin >> lll[i];
        cin >> q;
        while (q--) {
            cin >> x0 >> y0 >> x1 >> y1;
            ans = solve();
            cout << ans << endl;
        }
    }
    return 0;
}
