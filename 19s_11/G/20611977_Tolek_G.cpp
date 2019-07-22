#include <bits/stdc++.h>

using namespace std;
struct Node {
    long long a, num;
};
vector<Node> vvp;
long long s = 1, ans;

int main() {
    long long x;
    cin >> x;
    long long sta = static_cast<long long int>(sqrt(x));
    if (sta * sta == x) {
        cout << sta / 2 + 1;
        return 0;
    }
    for (long long i = 1; i * i * i <= x; i++) {
        if (x % i == 0) {
            long long a = x / i, s = static_cast<long long int>(sqrt((long double)a));
            if (s * s == a) {
                cout << s / 2 + 1;
                return 0;
            }
            if (a % i == 0)ans = i;
        }
    }
    cout << ans / 2 + 1;
    return 0;
}