#include<cstdio>
#include<algorithm>
#include<cstring>
#define SIZE 100010
#define MOD 998244353

using namespace std;

long long dp[5][SIZE];
char s[SIZE];
int val[SIZE];
char tag[]=" hard";

int main()
{
    int t,n;
    int i,j;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(i=1;i<=n;i++)
        scanf("%d",val+i);
    for(i=1;i<=n;i++)
    {
        dp[0][i]=99824435399824435LL;
        for(j=1;j<=4;j++)
        {
            if(s[i]==tag[j])
            {
                dp[j][i]=val[i];
            }
        }
    }
    for(j=1;j<5;j++)
    {
        for(i=1;i<=n;i++)
        {
            dp[j][i]+=min(dp[j-1][i-1],min(dp[j-1][i],dp[j][i-1]));
        }
    }
    long long ans=99824435399824435LL;
    for(i=1;i<=4;i++)
        ans=min(ans,dp[i][n]);
    printf("%lld\n",ans);
    return 0;
}

