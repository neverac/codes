#include <bits/stdc++.h>

#define MOD  998244353
using namespace std;
string str;

int main() {
    int n;
    cin >> n >> str;
    int k1 = 0, k2 = str.length() - 1;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[0])k1 = i;
        else break;
    }
    for (int i = str.length() - 2; i >= 0; i--) {
        if (str[i] == str[str.length() - 1])k2 = i;
        else break;
    }
    k1++, k2--;
//    cout << k1 << " " << k2 << endl;
    if (str[0] == str[str.length() - 1]) {
        cout << 1ll * (k1 + 1ll) * (1ll * str.length() - k2) % MOD;
        return 0;
    } else {
        cout << (1ll * k1 + str.length() - k2) % MOD;
        return 0;
    }
}