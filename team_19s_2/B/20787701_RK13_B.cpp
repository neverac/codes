#include <bits/stdc++.h>
using namespace std;
int nods[305][305];
int ans;
int n;
int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        int l = n * (n - 1) / 2;
        for (size_t i = 0; i < (size_t)l; i++) {
            int x, y, c;
            scanf("%d %d %d", &x, &y, &c);
            nods[x][y] = nods[y][x] = c;
        }
        ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    ans = max(ans, nods[i][j] + nods[j][k] + nods[i][k]);
                }
            }
        }
        printf("%d\n", ans);
    }
}