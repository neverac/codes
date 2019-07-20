#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZEN = 100010;
int N,M;
int chafen[33][SIZEN] = {0};
int ans[SIZEN] = {0};
int a[SIZEN],b[SIZEN],c[SIZEN];
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i = 1;i <= M;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		int now = 0;
		int tmp = c[i];
		while(tmp){
			now++;
			if(tmp & 1){
				chafen[now][a[i]]++;
				chafen[now][b[i]+1]--;
			}
			tmp>>=1;
		}
	}
	for(int j = 1;j <= 31;j++){
		for(int i = 1;i <= N;i++){
			chafen[j][i] += chafen[j][i-1];
		}
		for(int i = 1;i <= N;i++)if(chafen[j][i])chafen[j][i] = 1;
		for(int i = 1;i <= N;i++){
			chafen[j][i] += chafen[j][i-1];
		}
	}
	for(int i = 1;i <= M;i++){
		int now = 0;
		int tmp = c[i];
		while(now < 31){
			now++;
			if(!(tmp & 1)){
				int x = chafen[now][b[i]] - chafen[now][a[i]-1];
				if(x == b[i] - a[i] + 1){
					printf("NO");
					return 0;
				}
			}
			tmp>>=1;
		}
	}
	for(int i = 1;i <= 31;i++){
		for(int j = 1;j <= N;j++){
			ans[j] |= (1 << i-1) * (chafen[i][j] - chafen[i][j-1]);
		}
	}
	printf("YES\n");
	for(int i = 1;i <= N;i++)printf("%d ",ans[i]);printf("\n");
	return 0;
}