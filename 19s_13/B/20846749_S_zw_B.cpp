#include<iostream>
#include<math.h>
#include<iomanip>
#include <string>
#include <cstdio>
#include<stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
#define N 100010
using namespace std;int stop;
int n;
int map[N][2];
ll dp[N];
int main(){
    int i,j,k,x;
    scanf("%d",&n);
    for(i=1;i<=2*n;i++){
        scanf("%d",&x);
        if(map[x][0] == 0){
            map[x][0] = i;
        }else{
            map[x][1] = i;
        }
    }
    memset(dp,0x3f,sizeof(dp));
    map[0][0] = map[0][1] = 1;
    dp[0] = 0;
    for(i=1;i<=n;i++){
        dp[i] = dp[i-1] + min(abs(map[i][0]-map[i-1][0]) + abs(map[i][1]-map[i-1][1]),abs(map[i][0]-map[i-1][1]) + abs(map[i][1]-map[i-1][0]));
    }
    printf("%lld\n",dp[n]);
    return 0;
}