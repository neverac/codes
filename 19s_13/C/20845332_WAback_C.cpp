#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int SIZEN = 510;
int N,M;
int id[SIZEN][SIZEN] = {0},cnt = 0;
int xx[] = {0,0,0,1,-1};
int yy[] = {0,1,-1,0,0};
int root[SIZEN * SIZEN] = {0};
char str[SIZEN][SIZEN];
int r1,c1,r2,c2;
struct Node{
	int x,y;
	Node(int x_,int y_):x(x_),y(y_){;}
	Node(){;}
};
vector <Node> v1,v2;

int find(int x){
	if(x == root[x])return x;
	return root[x] = find(root[x]);
}

int main(){
	scanf("%d",&N);
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
	for(int i = 1;i <= N;i++){
		scanf("%s",str[i]+1);
		for(int j = 1;j <= N;j++){
			id[i][j] = ++cnt;
			root[cnt] = cnt;
		}
	}
	for(int i = 1;i <= N;i++){
		for(int j = 1;j <= N;j++){
			if(str[i][j] == '1')continue;
			for(int k = 1;k <= 4;k++){
				int x = i + xx[k],y = j + yy[k];
				if(x < 1 || y < 1 || x > N || y > N || str[x][y] == '1')continue;
				int fa = find(id[i][j]),fb = find(id[x][y]);
				if(fa == fb)continue;
				root[fa] = fb;
			}
		}
	}
	for(int i = 1;i <= N;i++){
		for(int j = 1;j <= N;j++){
			if(str[i][j] == '1')continue;
			if(find(id[i][j]) == find(id[r1][c1]))v1.push_back(Node(i,j));
			else if(find(id[i][j]) == find(id[r2][c2]))v2.push_back(Node(i,j));
		}
	}
	if(find(id[r1][c1]) == find(id[r2][c2])){
		printf("0");
	}
	else{
		int ans = 0x3f3f3f3f;
		for(int i = 0;i < v1.size();i++){
			for(int j = 0;j < v2.size();j++){
				int x1 = v1[i].x,y1 = v1[i].y,x2 = v2[j].x,y2 = v2[j].y;
				ans = min(ans,(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
1 3
3 1
010
101
010
*/