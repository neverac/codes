#include <bits/stdc++.h>
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=1E3+10;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
int mp[MAXN][MAXN];
int f1[MAXN][MAXN];
int f2[MAXN][MAXN];
int f3[MAXN][MAXN];
int main() {
	int N=input();
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=N;++j) {
			mp[i][j]=input()-i-j;
			f3[i][j]=1;
		}
	}
	for(int i=1;i<=N;++i) {
		f1[i][1]=1;
		for(int j=2;j<=N;++j) {
			if(mp[i][j]==mp[i][j-1])f1[i][j]=f1[i][j-1]+1;
			else f1[i][j]=1;
		}
	}
	for(int i=1;i<=N;++i) {
		f2[1][i]=1;
		for(int j=2;j<=N;++j) {
			if(mp[j][i]==mp[j-1][i])f2[j][i]=f2[j-1][i]+1;
			else f2[j][i]=1;
		}
	}
	int ans=0;
	for(int i=2;i<=N;++i) {
		for(int j=2;j<=N;++j) {
			int x=INF;
			if(mp[i][j]==mp[i][j-1])x=std::min(x,f1[i][j-1]);else x=0;
			if(mp[i][j]==mp[i-1][j])x=std::min(x,f2[i-1][j]);else x=0;
			if(mp[i][j]==mp[i-1][j-1])x=std::min(x,f3[i-1][j-1]);else x=0;
			f3[i][j]=x+1;
			ans=std::max(ans,f3[i][j]);
		}
	}printf("%d\n",ans);
	return 0;
}
