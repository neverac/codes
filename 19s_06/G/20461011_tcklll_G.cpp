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
int main(){
    int n;
    while(~sf(n)){
        int a[105];
        int s=0;
        for(int i=0;i<n;i++){
            sf(a[i]);
            s+=a[i];
        }
        int dp[105][105]={0};
        int sum[105][105]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++){
                for(int k=i;k<=j;k++){
                    sum[i][j]=(sum[i][j]+a[k])%100;
                }
            }
        }
        //cout<<sum[0][2]<<sum[1][2]<<endl;
        for(int j=2;j<=n;j++){
            for(int i=0;i+j-1<n;i++){
                if(j==2)dp[i][i+j-1]=a[i]*a[i+1];
                else{
                    int mmin=1000000000;
                    for(int k=0;k<j-1;k++){
                        mmin=min(mmin,dp[i][i+k]+dp[i+k+1][i+j-1]+sum[i][i+k]*sum[i+k+1][i+j-1]);
                    }
                dp[i][i+j-1]=mmin;
                }
            }
        }
        printf("%d\n",dp[0][n-1]);
    }
}
/*
4
24 25 51 52
*/

