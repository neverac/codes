#include <bits/stdc++.h>
using namespace std;
#define ll long long
int maxx,cnt;
int col[5005];
int dp[5005][5005];
int n,c;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> c;
        if(c!=col[cnt]){
            col[++cnt]=c;
            //num[c]++;
        }
    }
    for(int j=1;j<=cnt;j++){
        for(int i=j-1;i>=1;i--){
            if(col[i]==col[j]) dp[i][j]=dp[i+1][j-1]+1;
            else dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
        }
    }
    cout << dp[1][cnt] << endl;
    return 0;
}
