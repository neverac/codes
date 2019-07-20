#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
const int SIZEN = 100010;
typedef long long LL;
char s[SIZEN] = {0};
int N;
LL a[SIZEN] = {0};
LL F[SIZEN][10] = {0};
int f(char c){
	if(c == 'h')return 1;
	if(c == 'a')return 2;
	if(c == 'r')return 3;
	if(c == 'd')return 4;
	return 5;
}
int main(){
	scanf("%d",&N);
	scanf("%s",s+1);
	for(int i = 1;i <= N;i++)scanf("%lld",&a[i]);
	memset(F,0x3f,sizeof F);
	F[0][0] = 0;
	for(int i = 1;i <= N;i++){
		int x = f(s[i]);
		if(x == 5){
			for(int j = 0;j <= 3;j++)F[i][j] = F[i-1][j];
			continue;
		}
		for(int j = 0;j <= 3;j++)F[i][j] = F[i-1][j] + a[i];
		
		if(x != 1)F[i][0] = F[i-1][0];
		if(x <= 3){
			for(int j = 1;j <= x-2;j++)F[i][j] = min(F[i][j],F[i-1][j]);
			F[i][x-1] = min(F[i][x-1],F[i-1][x-1] + a[i]);
			F[i][x] = min(F[i][x],min(F[i-1][x-1],F[i-1][x]));
			for(int j = x+1;j <= 3;j++)F[i][j] = min(F[i][j],F[i-1][j]);
		}
		if(x == 4){
			F[i][3] = min(F[i][3],F[i-1][3] + a[i]);
			F[i][2] = min(F[i][2],F[i-1][2]);
			F[i][1] = min(F[i][1],F[i-1][1]);
		}
	}
	LL ans = LLONG_MAX;
	for(int i = 0;i <= 3;i++)ans = min(ans,F[N][i]);
	printf("%lld\n",ans);
	return 0;
}