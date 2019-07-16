#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#define sf(n) scanf("%d",&n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define ll long long
#define MAXL 1000000
#define eps 1e-6
#define MAXV 10005
#define INF 1000000005
#define mod 1000000007
using namespace std;
int a[1005][1005];
bool  f[1005][1005]={0};
int dp[1005][1005]={0};
int main()
{
    int n;sf(n);
    memset(a,-1,sizeof(a));
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        sf(a[i][j]);
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        if(a[i][j]==a[i-1][j]+1||a[i-1][j]==-1)
            if(a[i][j]==a[i][j-1]+1||a[i][j-1]==-1){
                f[i][j]=1;
                //cout<<
                //cout<<i<<"  "<<j<<endl;
            }
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i][1])dp[i][1]=1;
        if(f[1][i])dp[1][i]=1;
    }
    for(int i=2;i<=n;i++)
    for(int j=2;j<=n;j++){
        if(f[i][j]==0){dp[i][j]=1;continue;}
        dp[i][j]=max(2,min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1);
        //cout<<i<<" "<<j<<"  "<<dp[i][j]<<endl;
    }
    int mmax=1;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        mmax=max(mmax,dp[i][j]);
    }
    printf("%d\n",mmax);

}

