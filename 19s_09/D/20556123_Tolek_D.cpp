#include <bits/stdc++.h>

using namespace std;
int op[100005];
long long dp[100005][4];
int zy[100005][4];
long long sum[100005];
vector<char> vc;
vector<int> vi;
const char P[] = {'h', 'a', 'r', 'd'};

long long DP(int x, int y) {
    if (x >= vc.size())return 0;
    if (dp[x][y] != -1)return dp[x][y];
    if (y < 3) {
        if (zy[x][y] != -1)return dp[x][y] = min(vi[zy[x][y]] + DP(zy[x][y] + 1, y), DP(zy[x][y] + 1, y + 1));
        return dp[x][y] = 0;
    } else return dp[x][y] = sum[x];
}

int main() {
    int n;
    string str;
    cin >> n >> str;
    memset(dp, -1, sizeof(dp)), memset(zy, -1, sizeof(zy));
    for (int i = 1; i <= n; i++)cin >> op[i];
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'h' || str[i] == 'a' || str[i] == 'r' || str[i] == 'd')
            vc.push_back(str[i]), vi.push_back(op[i + 1]);
    }
    for (int i = vc.size() - 1; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (vc[i] == P[j])zy[i][j] = i;
            else zy[i][j] = zy[i + 1][j];
        }
    }
    for (int i = vc.size() - 1; i >= 0; i--) {
        if (vc[i] == 'd')sum[i] = vi[i] + sum[i + 1];
        else sum[i] = sum[i + 1];
    }
    cout << DP(0, 0);
    return 0;
}