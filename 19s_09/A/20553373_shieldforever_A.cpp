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

typedef long long LL;

int main(){
	LL l,r;
	int T;
	cin>>T;
	while(T--){
		scanf("%lld%lld", &l, &r);
		if(l <= r * 2LL){
			printf("%lld %lld\n", l, l * 2LL);
		}
	}
	return 0;
}
