#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
typedef long long LL;
const int SIZEN = 2000010;
bool vis[SIZEN] = {0};
int prime[SIZEN] = {0};
int tot = 0;
LL r;
LL p[SIZEN] = {0},cnt = 0,mi[SIZEN] = {0};
LL tmi[SIZEN] = {0};
struct Node{
	int a[16];
	LL data;
	Node(LL x){
		data = x;
		memset(a,0,sizeof a);
	}
	Node(){;}
};
queue<Node> q;
map<LL,bool> mp;
void work(){
	scanf("%lld",&r);
	for(int i = 1;i <= cnt;i++)mi[i] = p[i] = 0;
	cnt = 0;
	mp.clear();
	for(int i = 1;i <= tot && 1LL * prime[i] * prime[i] <= r;i++){
		if(r % prime[i] == 0){
			p[++cnt] = prime[i];
			while(r % p[cnt] == 0)mi[cnt]++,r /= p[cnt];
		}
	}
	if(r != 1){
		p[++cnt] = r;
		mi[cnt] = 1;
	}
//	for(int i = 1;i <= cnt;i++)printf("(%d %d)",p[i],mi[i]);
	q.push(Node(1));
	LL ans = 0;
	while(!q.empty()){
		Node now = q.front();q.pop();
		if(mp[now.data])continue;
		mp[now.data] = true;
		for(int i = 1;i <= cnt;i++){
			if(now.a[i] < mi[i]){
				ans++;
				Node D = now;
				D.a[i]++;D.data *= p[i];
				q.push(D);
			}	
		}
	}
	printf("%lld\n",ans);
	
}
void Init(){
	for(int i = 2;i <= 2000000;i++){
		if(!vis[i])prime[++tot] = i;
		for(int j = 1;j <= tot && i * prime[j] <= 2000000;j++){
			vis[i * prime[j]] = true;
			if(i % prime[j] == 0)break;
		}
	}
//	for(int i = 1;i <= 10;i++)printf("%d ",prime[i]);
}
int main(){
	int n;
	Init();
	scanf("%d",&n);
	while(n--)work();
	return 0;
}