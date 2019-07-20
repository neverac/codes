#include<iostream>
#include<math.h>
#include<iomanip>
#include <string>
#include <cstdio>
#include<stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
#define N 101
using namespace std;int stop;
int t,n;
ll arr[3];

int main(){
    int i,j;
    ll x;
    scanf("%d",&t);
    while (t>0)
    {
        t--;
        memset(arr,0,sizeof(arr));
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&x);
            arr[x%3]++;
        }
        ll sum = 0;
        sum+=arr[0];
        if(arr[2] >= arr[1]){
            sum+=arr[1];arr[2]-=arr[1];
            sum+=arr[2]/3;
            printf("%lld\n",sum);
            continue;
        }else{
            sum+=arr[2];
            arr[1]-=arr[2];
            sum+=arr[1]/3;
            printf("%lld\n",sum);
            continue;
        }
    }
    
return 0;
}