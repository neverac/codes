/*	TJU [2019暑期训练] 组队赛2 D Network Report
	1st Edition:2019.7.26 Friday
	Algorithm:Brute Force,Floyd
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>
using namespace std;

#define is_lower(c) (c>='a' && c<='z')
#define is_upper(c) (c>='A' && c<='Z')
#define is_alpha(c) (is_lower(c) || is_upper(c))
#define is_digit(c) (c>='0' && c<='9')
#define stop system("PAUSE")
#define ForG(i,a,b,c) for(rg int (i)=c.head[a],(b)=c.E[i].v;(i);(i)=c.E[i].nxt,(b)=c.E[i].v)
#define ForR(a,b,c) for(rg int (a)=b;(a)>=(c);--(a))
#define For(a,b,c) for(rg int (a)=(b);(a)<=(c);++a)
#define qmin(a,b) ((a)<(b)?(a):(b))
#define qmax(a,b) ((a)>(b)?(a):(b))
#define qabs(a) ((a)>=0?(a):-(a))
#define shl(x,y) ((x)<<(y))
#define shr(x,y) ((x)>>(y))
#define pc __builtin_popcount
#define mp make_pair
#define pb push_back
#define rg register
#ifdef ONLINE_JUDGE
#define hash rename_hash
#define next rename_next
#define prev rename_prev
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ull,ull> pull;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef double db;
const ll inf=1000000007LL;
const db EPS=1e-10;
const ll inf_ll=(ll)1e18;
const ll maxn=205LL;
const ll mod=1000003LL;

int n,m;
int d[maxn][maxn];
int cnt[maxn];
int maxd;

int main(){
	while(true){
		memset(d,-1,sizeof(d));memset(cnt,0,sizeof(cnt));maxd=0;
		scanf("%d",&n);if(!n) break;
		scanf("%d",&m);
		For(i,1,m){
			int u,v;
			scanf("%d%d",&u,&v);++u;++v;
			d[u][v]=d[v][u]=1;
		}
		For(i,1,n) d[i][i]=0;
		For(k,1,n) For(i,1,n) For(j,1,n) if(d[i][k]>=0 && d[k][j]>=0 && (d[i][j]<0 || d[i][j]>d[i][k]+d[k][j])) d[i][j]=d[i][k]+d[k][j];
		For(i,1,n) For(j,1,n) ++cnt[d[i][j]],maxd=max(maxd,d[i][j]);
		For(i,1,maxd) printf("%d %d\n",i,cnt[i]);
	}
	return 0;
}