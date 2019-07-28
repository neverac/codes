#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int SIZEN = 100010;
int N,M;
int a[SIZEN] = {0};
void work(){
	
}

int main(){
	scanf("%d",&N);
	for(int i = 1;i <= N;i++)scanf("%d",&a[i]);
	int fushu = 0,zhengshu = 0;
	for(int i = 1;i <= N;i++){
		if(a[i] < 0)fushu ++;
		if(a[i]> 0)zhengshu++;
	}
	int len = (N+1)/2;
	if(zhengshu >= len)puts("1");
	else if(fushu >= len)puts("-1");
	else puts("0");
	return 0;
}
/*
7
0 0 1 -1 0 0 2
*/