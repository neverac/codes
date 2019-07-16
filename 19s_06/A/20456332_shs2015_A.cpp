#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long LL;
const int SIZEN = 1000000 + 10;
LL prime[SIZEN] = {0};
LL sum[SIZEN] = {0};
LL bhave[SIZEN] = {0};
bool vis[SIZEN] = {0};
int tot = 0;
void Init(){
	for(int i = 2;i <= 1000000;i++){
		if(!vis[i])prime[++tot] = i;
		for(int j = 1;i * prime[j] <= 1000000;j++){
			vis[i * prime[j]] = true;
			if(i % prime[j] == 0)break;
		}
	}
}

LL n,b;
int main(){
	Init();
	scanf("%lld%lld",&n,&b);
	for(int i = 1;i <= tot && b!=1;i++){
		while(b % prime[i] == 0){
			bhave[i]++;
			b /= prime[i];
		}
	}
	if(b!=1){
		prime[++tot] = b;
		bhave[tot] = 1;
	}
	for(int i = 1;i <= tot;i++){
		for(LL j = prime[i];j <= n && j > 0;j*=prime[i]){
			sum[i] += n / j;
			if((n / j) < prime[i])break;
		}
	}
	LL ans = -1;
	for(int i = 1;i <= tot;i++){
		if(!bhave[i])continue;
		if(ans == -1)ans = sum[i]/bhave[i];
		else ans = min(ans,sum[i]/bhave[i]);
	}
	printf("%lld\n",ans);
	return 0;
}