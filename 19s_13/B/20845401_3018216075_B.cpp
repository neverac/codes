//
// Created by Septieme on 2019/7/27.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;


struct node {
    int value;
    int id;
} a[200010];

int comp(node m, node n) {
    return m.value < n.value;
}

ll dp[200010], pos1, pos2;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n * 2; i++) {
        cin >> a[i].value;
        a[i].id = i;
    }
    sort(a + 1, a + 2 * n + 1, comp);
    for (int i = 1; i <= n * 2; i += 2) {
        ll l1 = abs(a[i].id - a[pos1].id) + abs(a[i + 1].id - a[pos2].id);
        ll l2 = abs(a[i].id - a[pos2].id) + abs(a[i + 1].id - a[pos1].id);
        if (l1 < l2) {
            dp[i] = dp[i - 2] + l1;
            pos1 = i;
            pos2 = i + 1;
        } else {
            dp[i] = dp[i - 2] + l2;
            pos2 = i;
            pos1 = i + 1;
        }
    }
    cout << dp[2 * n - 1] - 2 << " ";

    return 0;
}
