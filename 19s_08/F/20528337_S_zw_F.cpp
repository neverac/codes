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
#define INF 2147483647
#define N 100000
using namespace std;int stop;
int n,m,k;
int arr[N];

int main(){
    int i,j,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr+1,arr+1+n);
    ll sum = 0;
    int biaoji  = -1;
    if(arr[1] < 0 && arr[n] > 0){
        for(i=1;i<=n;i++){
            if(arr[i] <= 0){
                sum+=(-arr[i]);
                biaoji = i;
            }else{
                sum+=arr[i];
            }
        }
        printf("%lld\n",sum);
        int x = arr[1],y = arr[n];
        for(i=biaoji+1;i<n;i++){
            printf("%d %d\n",x,arr[i]);
            x -= arr[i];
        }
        printf("%d %d\n",y,x);y-=x;
        for(i=2;i<=biaoji;i++){
            printf("%d %d\n",y,arr[i]);
            y-=arr[i];
        }

    }else if(arr[1] >= 0){
        sum = -arr[1];
        for(i=2;i<=n;i++){
            sum+=arr[i];
        }
        printf("%lld\n",sum);
        x = arr[1];
        for(i=2;i<n;i++){
            printf("%d %d\n",x,arr[i]);
            x-=arr[i];
        }
        printf("%d %d\n",arr[n],x);
    }else if(arr[n] <= 0){
        sum = arr[n];
        for(i=1;i<=n-1;i++){
            sum-=arr[i];
        }
        printf("%lld\n",sum);

        int x = arr[n];
        for(i=1;i<n;i++){
            printf("%d %d\n",x,arr[i]);
            x-=arr[i];
        }
     }
    //else{
    //     for(i=1;i<=n;i++){
    //         sum+=arr[i];
    //     }
    //     printf("%lld\n",sum);
    //     int x = arr[1];
    //     for(i=2;i<n;i++){
    //         printf("%d %d\n",x,arr[i]);
    //         x-=arr[i];
    //     }
    //     printf("%d %d\n",arr[n],x);
    // }
    
    return 0;
}