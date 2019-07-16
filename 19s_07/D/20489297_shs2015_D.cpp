#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZEN = 1010;
char str[SIZEN] = {0};
int a[SIZEN] = {0};
int b[SIZEN] = {0};
void work(){
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	scanf("%s",str+1);
	int N = strlen(str+1);
	for(int i = 1;i <= N;i++){
		if(str[i] == '1')a[i] = a[i-1] + 1;
		else a[i] = a[i-1];
	}
	for(int i = N;i >= 1;i--){
		if(str[i] == '0')b[i] = b[i+1] + 1;
		else b[i] = b[i+1];
	}
	int ans = 0x3f3f3f3f;
	for(int i = 1;i <= N+1;i++){
		ans = min(ans ,a[i-1]+b[i]);
	}
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}