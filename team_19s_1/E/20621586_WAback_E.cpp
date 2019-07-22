#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;
const int SIZEN = 1010;
int L;
int a[SIZEN] = {0};
int t[110][110] = {0};
typedef long long LL;

LL Sum(int x,int y){
	LL beix = (x + 1) /(2*L);
	LL beiy = (y + 1) /(2*L);
	LL restx = (x + 1) % (2*L);
	LL resty = (y + 1) % (2 * L);
	LL ret = 0;
	
	ret = 
	beix * beiy * t[2*L-1][2*L-1] + 
	beix * t[2*L-1][resty-1] + 
	beiy * t[restx-1][2*L-1] + 
	t[restx-1][resty-1];
	
	return ret; 
}

LL Solve(int x1,int y1,int x2,int y2){
	return Sum(x2,y2) - Sum(x2,y1-1) - Sum(x1-1,y2) + Sum(x1-1,y1-1);
}
void work(){
	scanf("%d",&L);
	for(int i = 0;i <  L;i++)scanf("%d",&a[i]);
	int cursor = 0;
	for(int i = 0;i <= 4*L;i++){
		for(int j = 0;j <= i;j++){
			t[j][i-j] = a[cursor];
			cursor = (cursor + 1) % L;		
		}
	}
	for(int i = 0;i < 2*L;i++){
		for(int j = 0;j < 2*L;j++)t[i][j] += t[i-1][j] + t[i][j-1] - t[i-1][j-1];
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%lld\n",Solve(x1,y1,x2,y2));
	}
}
int main(){
	int T;cin>>T;
	while (T--){
		memset(t,0,sizeof t);
		work();
	}
	return 0;
}