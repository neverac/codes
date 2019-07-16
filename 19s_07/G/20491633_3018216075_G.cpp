#include <bits/stdc++.h>

using namespace std;

int a[1010][1010], hsum[1010][1010], ssum[1010][1010];
int sum2[1010];
int main() {
    int n, ans = 0, sum1 = 1, mlen;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(j != 1 && a[i][j] == a[i][j-1] + 1){
                sum1++;
                hsum[i][j] = sum1;
            }
            else{
                sum1 = 1;
                hsum[i][j] = sum1;
            }

            if(i != 1 && a[i][j] == a[i - 1][j] + 1){
                sum2[j]++;
                ssum[i][j] = sum2[j];
            }
            else{
                sum2[j] = 1;
                ssum[i][j] = sum2[j];
            }

        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
           if(ssum[i][j] == hsum[i][j]){
               ans = max(ssum[i][j], ans);
           }
        }
    }

    cout << ans << endl;


    return 0;
}