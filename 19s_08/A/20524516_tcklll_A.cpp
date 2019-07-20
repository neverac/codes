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
int a[500005];
int k[6]={4,8,15,16,23,42};
int dp[6][500005]={0};
int cnt[6]={0};
int main()
{
    int n;sf(n);
    for(int i=0;i<n;i++){
        sf(a[i]);
        for(int j=0;j<6;j++){
            if(a[i]==k[j]){
                dp[j][cnt[j]]=i;
                cnt[j]++;
                break;
            }
        }
    }
    for(int i=0;i<6;i++){
        if(cnt[i]==0){printf("%d\n",n);return 0;}
    }
    int p[6]={0};
    int sum=0;
    bool flag=1;
    while(1){
        for(int i=1;i<6;i++){
            if(dp[i][p[i]]>dp[i-1][p[i-1]]){continue;}
            else{
                while(dp[i][p[i]]<dp[i-1][p[i-1]]){
                    p[i]++;
                    if(p[i]==cnt[i]){flag=0;break;}
                }
            }
        }
        if(flag==0)break;
        else{
            sum++;
            for(int i=0;i<6;i++)
            {
                p[i]++;
                if(p[i]==cnt[i]){flag=0;break;}
            }
        }
        if(flag==0)break;
    }
    printf("%d\n",n-sum*6);
}
