#include <bits/stdc++.h>

using namespace std;

struct Node {
    long long pre;
    long long num;

    Node(long long a = 0, long long p = 0) : pre(a), num(p) {}
};

long long f(long long x, long long p) {
    if (x == 0)return 0ll;
    return f(x / p, p) + x / p;
}

vector<Node> vvp;

int main() {
    long long a, b;
    cin >> a >> b;
    for (long long i = 2; 1ll * i * i <= b; i++) {
        if (b % i == 0) {
            Node pp(i, 0);
            while (b % i == 0)b /= i, pp.num++;
            vvp.push_back(pp);
        }
    }
    if (b != 1)vvp.push_back(Node(b, 1));
    long long ans = 1ll << 62;
    for (long long i = 0; i < vvp.size(); i++)ans = min(ans, f(a, vvp[i].pre) / vvp[i].num);
    cout << ans;
    return 0;
}