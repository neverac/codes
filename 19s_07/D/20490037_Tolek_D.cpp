#include <bits/stdc++.h>

using namespace std;
int dp[1500][2];

int main() {
    string str;
    int n;
    cin >> n;
    while (n--) {
        cin >> str;
        dp[str.length() - 1][str[str.length() - 1] - '0'] = 0;
        dp[str.length() - 1][(str[str.length() - 1] - '0') ^ 1] = 1;
        for (int i = str.length() - 2; i >= 0; i--) {
            dp[i][0] = min(dp[i + 1][0], dp[i + 1][1]) + (str[i] != '0');
            dp[i][1] = dp[i + 1][1] + (str[i] != '1');
        }
        cout << min(dp[0][0], dp[0][1]) << endl;
    }
    return 0;
}