#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int SIZEN = 110;
int N,M,K,a,b,c,d;
char str[SIZEN][SIZEN] = {0};
int F[SIZEN][SIZEN][60] = {0};

struct Node{
	int x,y,t;
	Node(int a,int b,int c){
		x = a;
		y = b;
		t = c;
	}
	Node(){;}
};queue<Node> q;
int xx[] = {0,0,0,1,-1};
int yy[] = {0,1,-1,0,0};
void BFS(){
	memset(F,0x3f,sizeof F);
	if(str[a][b]!='.'){
		F[a][b][1 << str[a][b] - 'a'] = 0;
		q.push(Node(a,b,1 << str[a][b] - 'a'));
	}
	else {
		F[a][b][0] = 0;
		q.push(Node(a,b,0));
	}
	while(!q.empty()){
		Node D = q.front();
		q.pop();
		for(int i = 1;i <= 4;i++){
			int x = D.x + xx[i],y = D.y + yy[i];
			if(str[x][y] == '#' || x < 1 || y < 1 || x > N || y > M)continue;
			if(str[x][y] == '.'){
				if(F[x][y][D.t] > F[D.x][D.y][D.t] + 1){
					F[x][y][D.t] = F[D.x][D.y][D.t] + 1;
					q.push(Node(x,y,D.t));
				}
			}
			else if(str[x][y] >= 'a' && str[a][b] <= 'z'){
				if(F[x][y][D.t | (1 << str[x][y] - 'a')] > F[D.x][D.y][D.t] + 1){
					F[x][y][D.t | (1 << str[x][y] - 'a')] = F[D.x][D.y][D.t] + 1;
					q.push(Node(x,y,D.t | (1 << str[x][y] - 'a')));
				}
			}
			else{
				if(D.t & (1 << str[x][y] - 'A')){
					if(F[x][y][D.t] > F[D.x][D.y][D.t] + 1){
						F[x][y][D.t] = F[D.x][D.y][D.t] + 1;
						q.push(Node(x,y,D.t));
					}
				}
			}
		}
	}
	int mn = 0x3f3f3f3f;
	for(int i = 0;i < (1 << K);i++)mn = min(mn,F[c][d][i]);
	if(mn != 0x3f3f3f3f)printf("%d\n",mn);
	else printf("-1");
}

int main(){
	scanf("%d%d%d%d%d%d%d",&N,&M,&K,&a,&b,&c,&d);
	a++;b++;c++;d++;
	for(int i = 1;i <= N;i++){
		scanf("%s",str[i] + 1);
	}
	for(int i = 1;i <= K;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x++;y++;
		str[x][y] = 'a'-1+i;
	}
	BFS();
	return 0;
}