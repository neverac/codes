#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int SIZEN = 200010;
int a[SIZEN] = {0};
int id[SIZEN] = {0};
bool Cmp(const int &A,const int &B){
	return a[A] > a[B];
}
typedef long long LL;
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;i++)scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++)id[i] = i;
	sort(id + 1,id + 1 + n,Cmp);
//	for(int i = 1;i <= n;i++)printf("%d ",a[id[i]]);printf("\n"); 
	LL ans = 0;
	for(int i = 1;i <= m*k;i++)ans += a[id[i]];
	sort(id + 1,id + 1 + m*k);
	printf("%lld\n",ans);
//	for(int i = 1;i <= m * k;i++)printf("%d ",id[i]);printf("\n");
	for(int i = 1;i < k;i++){
		int x = i * m;
		printf("%d ",id[x]);
	}
	return 0;
} 