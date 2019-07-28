/*	TJU [2019暑期训练] 组队赛2 A Smooth Sequences
	1st Edition:2019.7.26 Friday
	Algorithm:Brute Force
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
const ll maxn=1005LL;
const ll mod=1000003LL;

int n,d;
int a[maxn];

inline bool check(){
	For(i,1,n-1) if(abs(a[i+1]-a[i])>d) return false;
	return true;
}

int main(){
	while(true){
		scanf("%d",&n);if(!n) break;
		scanf("%d",&d);
		For(i,1,n) scanf("%d",a+i);
		int cnt=0,pos=0;
		
		if(check()) {puts("Y");continue;}
		For(i,2,n-1) if(abs(a[i]-a[i-1])>d && abs(a[i+1]-a[i])>d) ++cnt,pos=i;
		if(cnt>1) {puts("N");continue;}
		if(cnt==1){
			if(abs(a[pos+1]-a[pos-1])>d+d) {puts("N");continue;}
			a[pos]=(a[pos+1]+a[pos-1])>>1;
			puts(check()?"Y":"N");
			continue;
		}
		cnt=pos=0;
		For(i,1,n-1) if(abs(a[i+1]-a[i])>d) ++cnt,pos=i;
		if(cnt>1) {puts("N");continue;}
		else{
			if(pos>1 && abs(a[pos+1]-a[pos-1])<=d+d) puts("Y");
			else if(pos<n-1 && abs(a[pos+2]-a[pos])<=d+d) puts("Y");
			else puts("N");
		}
	}
	return 0;
}