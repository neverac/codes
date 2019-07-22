#include<iostream>
#include<math.h>
#include<iomanip>
#include <string>
#include <cstdio>
#include<stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
#define N 100001
using namespace std;int stop;
int n,m;
int road[N];
ll sum[N];
int main(){
    int i,j,k,x;
    ll fee = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d",&road[i]);
    }
    sort(road+1,road+1+n);
    for(i=1;i<=n;i++){
      sum[i] = (ll)road[i] + sum[i-1];
    }

    for(i=n;i>=2;i--){
      fee+=road[i] * (sum[i] + sum[i-1]);
    }
    fee+=road[1]*sum[1];
    printf("%lld\n",fee);
    return 0;
}