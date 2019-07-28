#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p,q,m,cnt;
bool vis[15];
int main(){
	memset(vis,0,sizeof vis);
	scanf("%lld%lld",&p,&q);
	cnt = 0;
	while(p){
		if(cnt > 10000ll) break;
		cnt ++;
		p*=10ll;
		ll i = p/q;
		vis[i]=true;
		if(i == 0) continue;
		p = p % q;
		
	}
	for(int i = 0;i <= 9;i ++){
		if(vis[i]) printf("%d",i);
	}
    return 0;
}
