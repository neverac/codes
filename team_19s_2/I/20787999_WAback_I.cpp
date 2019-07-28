#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int SIZEN = 100;
vector<int> v[SIZEN];
int ans = 0;
int N,M,E; 
bool flag[SIZEN] = {0};


void Judge(){
	int t = 0;
	for(int i = 1;i <= N;i++)t += flag[i];
	for(int i = 1;i <= M;i++){
		for(int j = 0;j < v[i].size();j++){
			int p = v[i][j];
			if(!flag[p]){
				t++;
				break;
			}
		}
	}
	ans = min(ans,t);
}
void DFS(int x){
	if(x == N+1){Judge();return;}
	flag[x] = true;
	DFS(x+1);
	flag[x] = false;
	DFS(x+1);
}
int main(){
	while(scanf("%d",&N),N){
		memset(flag,0,sizeof flag);
		scanf("%d%d",&M,&E);
		for(int i = 1;i <= M;i++)v[i].clear();
		ans = 0x3f3f3f3f;
		for(int i = 1;i <= E;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			a++;b++;
			v[b].push_back(a); 
		}
		DFS(1);
		printf("%d\n",ans);
	}
	return 0;
} 

/*
4 
3 
6 
0 0 
0 1 
1 0 
1 1 
1 2 
2 1
0
*/