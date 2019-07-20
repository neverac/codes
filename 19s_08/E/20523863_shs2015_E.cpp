#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int N;
int a[110] = {0};
int sum[10] = {0};
void work(){
	memset(sum,0,sizeof sum);
	scanf("%d",&N);
	for(int i = 1;i <= N;i++)scanf("%d",&a[i]),sum[a[i] % 3]++;
	int ans = 0;
	ans += sum[0];
	ans += min(sum[1],sum[2]);
	int x = min(sum[1],sum[2]);
	sum[1] -= x;
	sum[2] -= x;
	ans += (sum[1] + sum[2])/3;
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}