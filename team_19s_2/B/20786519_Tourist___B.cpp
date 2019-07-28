#include <iostream>
using namespace std;
const int maxn=400;
int G[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int m=n*(n-1)/2;
        for (int i=1;i<=m;i++){
            int x,y,z;
            cin >> x >> y >> z;
            G[x][y] = G[y][x] =z;
        }
        int ans = -1;
        for (int i=1;i<=n-2;i++)
            for (int j=i+1;j<=n-1;j++)
                for (int k=j+1;k<=n;k++)
                    ans = max (ans,G[i][j]+G[i][k]+G[j][k]);
        cout << ans << endl;
    }
    return 0;
}
