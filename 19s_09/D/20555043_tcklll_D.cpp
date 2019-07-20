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
#define mod 998244353
using namespace std;
ll dp[100005][4]={0};
ll a[100005];
ll q[100005];
int main()
{
    int n;sf(n);getchar();
    char s[100005];
    scanf("%s",&s);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    int cnt=0;
    int p[100005];
    for(int i=0;i<n;i++){
        if(s[i]=='h'){p[cnt]=0;q[cnt]=a[i];}
        else if(s[i]=='a'){p[cnt]=1;q[cnt]=a[i];}
        else if(s[i]=='r'){p[cnt]=2;q[cnt]=a[i];}
        else if(s[i]=='d'){p[cnt]=3;q[cnt]=a[i];}
        else continue;
        cnt++;
    }
    if(p[0]==0)dp[0][0]=q[0];//cout<<dp[0][0]<<"  "<<dp[0][1]<<"  "<<dp[0][2]<<" 5 "<<dp[0][3]<<endl;
    for(int i=1;i<cnt;i++){
        for(int j=0;j<4;j++)
            dp[i][j]=dp[i-1][j];
        //cout<<p[i]<<endl;
        dp[i][p[i]]+=q[i];
        for(int j=0;j<p[i];j++){
            dp[i][p[i]]=min(dp[i][p[i]],dp[i-1][j]);
        }
        //cout<<dp[i][0]<<"  "<<dp[i][1]<<"  "<<dp[i][2]<<"  "<<dp[i][3]<<endl;
    }
    printf("%lld\n",dp[cnt-1][3]);
}
