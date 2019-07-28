#include<iostream>
#include<math.h>
#include<iomanip>
#include <string>
#include <cstdio>
#include<stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
#define N 1000010
#define INF 0X3f3f3f3f
using namespace std;int stop;
int n;
int arr[110];
int main(){
    int i,j,k;
    scanf("%d",&n);
	int zheng = 0,fu = 0;
	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		if(arr[i]>0){
			zheng++;
		}else if(arr[i] < 0){
			fu++;
		}
	}
	//printf("%llf",ceil((double)n/2));
	int tmp = INF;
	if(zheng >= ceil((double)n/2)){
		for(i=1;i<=n;i++){
			if(arr[i] > 0 && arr[i] < tmp){
				tmp = arr[i];
			}
		}
		printf("%d\n",tmp);
		return 0;
	}else if(fu >= ceil((double)n/2)){
		tmp = -INF;
		for(i=1;i<=n;i++){
			if(arr[i] > tmp && arr[i] < 0){
				tmp = arr[i];
			}
		}
		printf("%d\n",tmp);
		return 0;
	}
	printf("0\n");
    return 0;
}