#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define SIZE 1010

using namespace std;

int rec[SIZE][SIZE];
int dp[SIZE][SIZE];
int main()
{
    int i,j,n;
    int ans=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&rec[i][j]);
        }
        dp[i][n]=1;
    }
    for(i=1;i<n;i++)
    {
        dp[n][i]=1;
    }
    for(i=n-1;i>0;i--)
    {
        for(j=n-1;j>0;j--)
        {
            if(rec[i][j]==rec[i+1][j]-1 && rec[i][j]==rec[i][j+1]-1)
            {
                dp[i][j]=min(dp[i+1][j],dp[i][j+1]);
                dp[i][j]=min(dp[i][j],dp[i+1][j+1])+1;
                ans=max(ans,dp[i][j]);
            }
            else
                dp[i][j]=1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
