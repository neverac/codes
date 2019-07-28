#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int SIZEN = 10001000;
int N,M;
int a[SIZEN] = {0};
bool flag[10010] = {0};
int main(){
	scanf("%d%d",&N,&M);
	N *= 10;
	for(int i = 1;i <= 10000000 && N;i++){
		if(N < M){
			a[i] = 0;
			N *= 10;
		}
		else{
			a[i] = N/M;
			N %= M;
			N *= 10;
		}
		flag[a[i]] = true;
	}
	for(int i = 0;i < 10;i++)if(flag[i])printf("%d",i);
	return 0;
}
/*
13 123
*/