#include <bits/stdc++.h>

using namespace std;
int n, maxn, num;
bool ssp[1000005];
vector<int> vvp;

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    std::default_random_engine random(time(0));
    cin >> n;
    std::uniform_int_distribution<int> dis1;
    int l = 0, r = 1000000000, mid, x;
    while (l <= r) {
        if (r == l) {
            maxn = l;
            break;
        }
        mid = (l + r) >> 1;
        cout << "> " << mid << endl, ++num;
        cin >> x;
        if (x)l = mid + 1;
        else r = mid;
    }
    for (int i = num + 1; i <= 60 && i - num <= n; i++) {
        int ss = dis1(random) % n + 1;
        if (ssp[ss]) {
            --i;
            continue;
        }
        ssp[ss] = true, cout << "? " << ss << endl;
        cin >> x;
        vvp.push_back(x);
    }
    sort(vvp.begin(), vvp.end());
    int g = vvp[1] - vvp[0];///////////////////////
    for (int i = 2; i < vvp.size(); i++)g = gcd(g, vvp[i] - vvp[i - 1]);
    cout << "! " << maxn - (n - 1) * g << " " << g << endl;
    return 0;
}