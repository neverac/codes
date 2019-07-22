#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;

char s[30][30];
int mp[30][30],b[30][30];

int ans;

void Rotate(int x,int y){

	// for (int l=0; l<4; l++){
	// 	for (int r=0; r<4; r++){
	// 		printf("%d ",mp[x+l][y+r]);
	// 	}
	// 	puts("");
	// } puts("");


	for (int l=0; l<4; l++){
		for (int r=0; r<4; r++){
			b[r][4-l-1]=mp[x+l][y+r];
		}
	}
	for (int l=0; l<4; l++){
		for (int r=0; r<4; r++){
			mp[x+l][y+r]=b[l][r];
		}
	}

	// for (int l=0; l<4; l++){
	// 	for (int r=0; r<4; r++){
	// 		printf("%d ",mp[x+l][y+r]);
	// 	}
	// 	puts("");
	// } puts("");

}

int visit[20];
bool check(int x,int y){
	for (int i=1; i<=x; i++){
		memset(visit,0,sizeof(visit));
		for (int j=1; j<=y; j++){
			if (visit[mp[i][j]]) return 0;
			visit[mp[i][j]]=1;
		}
	}
	for (int j=1; j<=y; j++){
		memset(visit,0,sizeof(visit));
		for (int i=1; i<=x; i++){
			if (visit[mp[i][j]]) return 0;
			visit[mp[i][j]]=1;
		}
	}
	return 1;
}

void dfs(int x,int y,int dep){
	// printf("debug %d %d %d\n",x,y,dep);
	if (dep>=ans) return;
	if (x==17){
		ans = min(ans,dep);
		return;
	}
	int tx,ty;
	if (y==13) tx = x+4,ty=1;
	else tx = x,ty = y+4;
	for (int i=0; i<4; i++){
		if (i) Rotate(x,y);
		if (check(x+3,y+3)) dfs(tx,ty,dep+i);
		else continue;
	}
	Rotate(x,y);
}

int main(){
	int T; cin>>T;
	while (T--){
		for (int i=1; i<=16; i++){
			scanf("%s",s[i]+1);
			for (int j=1; j<=16; j++){
				if (s[i][j]>='0' && s[i][j]<='9') mp[i][j]=s[i][j]-'0';
				else mp[i][j]=s[i][j]-'A'+10;
			}
		}
		ans = 16*4;
		dfs(1,1,0);
		printf("%d\n",ans);
	}
	return 0;
}