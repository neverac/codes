#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZEN = 1010;
int N;
int a[SIZEN][SIZEN] = {0};
int down[SIZEN][SIZEN] = {0};
int right[SIZEN][SIZEN] = {0};
bool Check(int x){
	int sum = 0;
//	printf("x = %d\n",x);
	for(int i = 1;i <= N;i++){
		int now = 0;sum = 0;
		while(now != x){
			now++;
			if(down[i][now] < x)sum++;
		}
	//	printf("now - x + 1 = %d now = %d sum = %d i = %d\n",now-x+1,now,sum,i);
		if(!sum && right[i][1] >= x)return true;
		while(now != N){
			if(down[i][now - x + 1]<x)sum--;
			now++;
			if(down[i][now] < x)sum++;
			if(!sum && right[i][now-x+1] >= x)return true;
		}
	}
	return false;
}

int main(){
	scanf("%d",&N);
	for(int i = 1;i <= N;i++){
		for(int j = 1;j <= N;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = N;i >= 1;i--){
		for(int j = 1;j <= N;j++){
			if(i == N || a[i][j]+1 != a[i+1][j])down[i][j] = 1;
			else down[i][j] = down[i+1][j] + 1;
		}
	}
	for(int j = N;j >= 1;j--){
		for(int i = 1;i <= N;i++){
			if(j == N || a[i][j] + 1!=a[i][j+1])right[i][j] = 1;
			else right[i][j] = right[i][j+1] + 1;
		}
	}
//	for(int i = 1;i <= N;i++){
//		for(int j = 1;j <= N;j++)printf("%d ",right[i][j]);
//		printf("\n");
//	}
//	for(int i = 1;i <= N;i++){
//		for(int j = 1;j <= N;j++)printf("%d ",down[i][j]);
//		printf("\n");
//	}
	int l = 1,r = N,mid,ans=  1;
	while(l <= r){
		mid = (l+r)/2;
		if(Check(mid))ans = max(ans,mid),l = mid+1;
		else r = mid-1;
	}
	printf("%d",ans);
	return 0;
}