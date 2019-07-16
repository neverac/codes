#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<queue>

using namespace std;

#define N 1000100
typedef long long LL;
LL p[N], num[N];
LL n, b, tot;

int main(){
	LL i,j,k;
	scanf("%lld%lld", &n, &b);
	tot = 0;
	i = 2;
	while(b > 0){
		j = 0;
		while(b % i == 0){
			b /= i; j++;
		}
		if(j > 0) {
			p[++tot] = i;
			num[tot] = j;
		}
		i++;
		if(i > 1000000) break;
	}
	if(b > 1){
		p[++tot] = b;
		num[tot] = 1;
	}
	//for(i = 1; i <= tot; i++)cout<<p[i]<<' '<<num[i]<<endl;
	LL ans = 1e18;
	for(i = 1; i <= tot; i++){
		j = 1;
		LL sum = 0;
		LL q = p[i];
		//cout<<n<<' '<<q<<endl;
		LL m = n;
		while(m > 0){
			sum += m / q;
			m /= q;
		}
		//cout<<sum<<' '<<num[i]<<endl;
		ans = min(ans, sum / num[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
