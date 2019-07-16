#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E5+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
char str[MAXN];
int doing() {
	scanf("%s",str);
	int N=strlen(str),ans=INF;
	{
		int cnt=0;
		for(int i=0;i<N;++i) {
			if(str[i]!='0')++cnt;
		}ans=std::min(cnt,N-cnt);
		
	}
	for(int i=0;i<N;++i) {
		int cnt=0;
		for(int k=0;k<i;++k) {
			if(str[k]!='0')++cnt;
		}
		for(int k=i;k<N;++k) {
			if(str[k]!='1')++cnt;
		}
		ans=std::min(ans,cnt);
	//	printf(">>> %d %d\n",i,cnt);
	}printf("%d\n",ans);
	return 0;
}
int main() {
	int T=input();
	while(T-->0)doing();
	return 0;
}
