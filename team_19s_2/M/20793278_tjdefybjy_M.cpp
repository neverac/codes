#include <bits/stdc++.h>
//??????
typedef long long TYPE;
const TYPE mod=1E9+7;
const int MAXN=30;
const int MAXM=30;
const int INF=~0U>>1;
int input() {
	int x;scanf("%d",&x);
	return x;
}
int tong[MAXN],task[MAXM][MAXM];
int N,D,ans,lastans;
bool check(const int&x,const int&th) {
	for(int i=1;i<=D;++i) {
		tong[i]=0;
	}
	int left=1;
	for(int r=1;r<=D;++r) {
		left=1;
		for(int l=1;l<=r;++l) {
			left=std::max(left,l);
			if(task[l][r]!=0 && r<left)return false;
			if(task[l][r]!=0) {
				int xx=task[l][r];
				while(tong[left]+xx>x && left<=r) {
					xx-=(x-tong[left]);
					tong[left]=x;
					left++;
					//printf("????\n");
				}
				if(left>r) return false;
				tong[left]+=xx;
			}
		}
	}
	return true;
}
void count(int th) {
	if(!check(ans,th))
		ans=ans+1;
}
int aw[10010];
int doing() {
	N=input();
	if(N==0)return 0;
	D=input();
	lastans=ans=0;
	memset(task,0,sizeof task); 
	int tail=0;
	for(int i=1;i<=N;++i) {
		int l=input();
		int r=input();
		task[l][r]++;count(i);
		if(lastans!=ans) {
			aw[++tail]=i; 
	//		printf(">>> %d\n",i);
		}
		lastans=ans;
	}
	for(int i=1;i<=tail;++i) {
		printf("%d",aw[i]);
		if(i!=tail)printf(" ");
	}printf("\n");
	//printf("%d \n",int(check(0,1)));
	return 1;
}
int main() {
//	freopen("stdin.txt","r",stdin);
//	freopen("stdout.txt","w",stdout);
	while(doing());
	return 0;
}
