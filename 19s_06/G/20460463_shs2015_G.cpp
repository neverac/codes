#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZEN = 1010;
int N;
int a[SIZEN] = {0};
int sum[SIZEN] = {0};
int F[SIZEN][SIZEN] = {0};
int main(){
	while(scanf("%d",&N)!=EOF){
		for(int i = 1;i <= N;i++){
			scanf("%d",&a[i]);
			sum[i] = (a[i] + sum[i-1]);
		}
		memset(F,0x3f,sizeof F);
		for(int i = 0;i <= N;i++)F[i][i] = 0;
		for(int len = 2;len <= N;len++){
			for(int i = 1;i <= N;i++){
				int j = i+len-1;
				if(j > N)break;
				for(int k = i;k < j;k++){
					int tmp = ((sum[k] - sum[i-1]) % 100) * ((sum[j] - sum[k])%100);
					tmp = tmp+F[i][k]+F[k+1][j]; 
					F[i][j] = min(F[i][j],tmp);
				}
			}
		}
		printf("%d\n",F[1][N]);
	}
	return 0;
}