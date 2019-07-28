#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int mp[310][310];
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        int n, a, b, dis, maxn = 0;
        cin >> n;
        for (int i = 0; i < n * (n - 1) / 2; i++){
            cin >> a >> b >> dis;
            mp[a][b] = dis;
            mp[b][a] = dis;
        }
        for(int i = 1; i <= n - 2; i++ ){
            for(int j = i + 1; j <= n - 1; j++){
                for(int k = j + 1; k <= n; k++){
                    maxn = max(maxn, mp[i][j]+ mp[j][k] + mp[i][k]);
                }
            }
        }
        cout << maxn << endl;

    }
    return 0;
}

