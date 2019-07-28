#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<queue>

using namespace std;

#define N 200020

struct node{
	int id, num;
}a[N];
int n,m, tot;
int t[N * 5];

bool cmp(node a, node b) {
    if(a.num != b.num)return a.num < b.num;
    else return a.id < b.id;
}

void init(){
	int i,j,k;
	tot = 0;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			scanf("%d", &k);
			a[++tot].id = i;
			a[tot].num = k;
		}
	}
	sort(a + 1, a + 1 + tot, cmp);
	a[tot+1].num = 100000000;
	a[tot+1].id = 1000000;
}

void solve(){
	int ans;
	int l,r,i,j,k;
	memset(t, 0, sizeof(t));
	
	l = r = 1;
	int sum = 0;
	int ls = a[1].num, rs = a[1].num;
	while(a[r].num <= rs){
		t[a[r].id]++;
		if(t[a[r].id] == 1) sum++;
		r++;
	}
	while(sum < n){
		rs++;
		while(a[r].num <= rs){
			t[a[r].id]++;
			if(t[a[r].id] == 1) sum++;
			r++;
		}		
	}
	ans = rs - ls;
	while(ls <= a[tot].num && rs <= a[tot].num){
	//	cout<<ls<<endl;
		while(a[l].num == ls && l <= tot && ls <= a[tot].num){
			t[a[l].id]--;
			if(t[a[l].id] == 0)sum--;
			l++;
		}
		ls++;
//		cout<<ls<<endl;
//		cout<<sum<<endl;
		while(sum < n && rs <= a[tot].num){
			rs++;
			while(a[r].num <= rs && r <= tot){
				t[a[r].id]++;
				if(t[a[r].id] == 1) sum++;
				r++;
			}		
		}
		if(sum == n) ans = min(ans, rs - ls);	
		//cout<<ls<<' '<<rs<<endl;
		if(sum < n) break;
	}
	printf("%d\n", ans);
}

int main(){
	init();
	solve();
	return 0;
}
