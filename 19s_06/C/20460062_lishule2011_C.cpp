#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5*2+1000;
//long long a[maxn],b[maxn];
struct Node {
	long long val,loc;
}a[maxn];
bool cmp1(Node a,Node b){return a.val>b.val;}
bool cmp2(Node a,Node b){return a.loc<b.loc;}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n,m,k;
	
	cin >> n >> m >>k;

	for (int i=1;i<=n;i++) {
		cin >> a[i].val;
		a[i].loc = i;
		// b[i] = a[i];
	}
	sort(a+1,a+1+n,cmp1);
	//cout << maxn << endl;
	//for (int i=1;i<=n;i++) cout << a[i];
	// map <int,int> mp;
	// mp.clear();	
	long long ans=0;	
	for (int i=1;i<=m*k;i++) ans+=a[i].val;
	int cnt = 0;
	cout << ans<<endl;
	int tot=0;
	sort(a+1,a+1+k*m,cmp2);
	for (int i=m;i<k*m;i+=m)
		cout << a[i].loc <<' ';
	//cout << mp.count(1);
	// for (int i=1;i<=n;i++){
	// 	if (mp.count(b[i]) == 1) {
	// 		cnt++;
	// 		if (cnt == m) {
	// 			cout << i << ' ';
	// 			cnt = 0;
	// 			tot++;
	// 			if (tot == k-1) return 0;
	// 		}
	// 	}

	// }

}