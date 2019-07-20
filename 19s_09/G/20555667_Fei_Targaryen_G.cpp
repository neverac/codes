#include<bits/stdc++.h>
using namespace std;
unsigned long long dp[1000010];
int main()
{
    int n;
    dp[0]=0;
    dp[1]=1;
    dp[2]=5;
    int cnt=1;
    for(int i=3;i<=1000005;i++)
    {
        if(i%2!=0) dp[i]=3*dp[i-1]-3*dp[i-2]+dp[i-3]+1;
        else dp[i]=3*dp[i-1]-3*dp[i-2]+dp[i-3]+1+1;
    }
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<dp[n]<<endl;
    }
}
