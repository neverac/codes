#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long F[1000010] = {0};
void Init(){
	F[1] = 1;
	for(long long i = 2;i <= 1000000;i++){
		F[i] = F[i-1] + i + i*(i-1)/2;
		if((i-1) & 1)F[i] = F[i] + i*i/4;
		else F[i] = F[i] + (1 + (i-1)/2)*((i-1)/2);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	Init();
	while(T--){
		int a;scanf("%d",&a);
		printf("%lld\n",F[a]);
	}
	return 0;
}