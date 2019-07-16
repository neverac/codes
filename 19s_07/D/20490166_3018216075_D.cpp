#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        int minus = 1005;
        cin >> str;
        int len = str.length();
        for (int i = 0; i <= len; i++) {
            int ans = 0;
            for (int j = 0; j < len; j++) {
                if (j < i) {
                    if (str[j] != '0') {
                        ans++;
                    }
                } else {
                    if (str[j] != '1')
                        ans++;
                }
            }
            minus = min(ans, minus);
        }

        cout << minus << endl;
    }
}