#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#include <queue>
struct Node{
	int x,y;
	Node(int a,int b){
		x = a;
		y = b;
	}
	Node(){;}
};
 
queue<Node> q;
int N,M;
int xx[] = {0,0,0,1,-1};
int yy[] = {0,1,-1,0,0};
char str[1010][1010];
int F[1010][1010] = {0};
int main(){
	memset(F,0x3f,sizeof F);
	scanf("%d%d",&N,&M);
	for(int i = 1;i <= N;i++)scanf("%s",str[i]+1);
	for(int i = 1;i <= N;i++){
		for(int j = 1;j <= M;j++){
			if(str[i][j] == '#'){
				F[i][j] = 0;
				q.push(Node(i,j));
			}
		}
	}
	while(!q.empty()){
		Node D= q.front();
		q.pop();
		for(int i = 1;i <= 4;i++){
			int x = D.x + xx[i],y = D.y + yy[i];
			if(x < 1 || y < 1 || x > N || y > M)continue;
			if(F[x][y] > F[D.x][D.y] + 1){
				F[x][y] = F[D.x][D.y] + 1;
				q.push(Node(x,y));
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= N;i++){
		for(int j = 1;j <= M;j++){
			ans = max(ans,F[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}