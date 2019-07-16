#include<bits/stdc++.h>
#define  MAX 100005
#define  MOD 1000000007
#define ll long long
using namespace std;

int dp[105][105];
int arr[105];
int s[105];
int main(){
    int n;
    while(cin>>n){
        s[0]=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            s[i]=arr[i]+s[i-1];
        }
        memset(dp,0x3f,sizeof(dp));
        for(int i=1;i<=n;i++)dp[i][i]=0;
        for(int p=1;p<n;p++){
            for(int i=1,j=i+p;j<=n;i++,j++){
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+((s[k]-s[i-1])%100)*((s[j]-s[k])%100));
                }
            }
        }
        cout<<dp[1][n]<<endl;
    }
}
