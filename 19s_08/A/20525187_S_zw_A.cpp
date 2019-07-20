#include<iostream>
#include<math.h>
#include<iomanip>
#include <string>
#include <cstdio>
#include<stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;int stop;
int n;
int arr[7];
int main(){
    int i,j,k,x;
    scanf("%d",&n);
    memset(arr,0,sizeof(arr));
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        switch (x)
        {
        case 4:
            arr[0]++;
            break;
        case 8:
            if(arr[0]!=0){
                arr[0]--;arr[1]++;
            }
            break;
        case 15:
            if(arr[1]!=0){
                arr[1]--;arr[2]++;
            }
            break;
        case 16:
            if(arr[2]!=0){
                arr[2]--;arr[3]++;
            }
            break;
        case 23:
            if(arr[3]!=0){
                arr[3]--;arr[4]++;
            }
            break;
        default:
            if(arr[4]!=0){
                arr[4]--;arr[5]++;
            }
            break;
        }
    }
    printf("%d",n-6*arr[5]);
    return 0;
}