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
LL K, A, B;

int main(){
	cin>>K>>A>>B;
	if(A>=B||B-A==1){
		printf("%lld\n", K + 1);
		return 0;
	}
	if(K<=A){
		printf("%lld\n", K + 1);
		return 0;
	}
	LL ans = 0LL;
	K-=(A+1);
	ans=B;
	ans+=(K/2)*(B-A);
	if(K%2==1)ans++;
	printf("%lld\n",ans);
	return 0;
}
