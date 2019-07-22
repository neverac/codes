#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int a[maxn],b[maxn],c[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		b[i] = a[i];
		c[i] = a[i];
	}
	sort(b+1,b+1+n,cmp);
	sort(c+1,c+1+n);
	int cnt1=0,cnt2=0;
	vector <int> q1,q2;
	for (int i=1;i<=n;i++) {
		if (a[i] != b[i]) cnt1++,q1.push_back(i);
		if (a[i] != c[i]) cnt2++,q2.push_back(i);
	}
	if (cnt1 == 0 || cnt2 == 0) cout << "Nothing to do here";//puts("Nothing to do here");
	else if (cnt1 == 2){
		//puts("Yes");
		cout << "Yes"<<endl<<q1[0] << ' ' << q1[1];
	}else if (cnt2 == 2){
		// puts("Yes");
		cout << "Yes"<<endl <<q2[0] << ' ' << q2[1];
	}else{
		cout << "No hope";
		// puts("No hope");
	}
}