#include <bits/stdc++.h> 
using namespace std;
bool cmp(int a,int b){return a>b;}
int a[100010],b[100010];
int main(){
	
	int n;
	long long sum=0;
	cin >> n;
	for (int i=1;i<=n;i++) {
		cin >>a[i];
		b[i] = a[i];
	}
	sort(a+1,a+1+n,cmp);
	int cnt=0;
	vector <int> Q;
	for (int i=1;i<=n;i++) if (a[i]!=b[i]){
		cnt++;
		Q.push_back(i);
	}
	bool ever=0;
	int aa,bb;
	if (!cnt) {cout << "Nothing to do here";return 0;}
	if (cnt == 2){
		// puts("Yes");
		// cout << Q[0] <<' ' << Q[1];
		// return 0;
		ever=1;
		aa = Q[0];
		bb = Q[1];
	}
	sort(a+1,a+1+n);
	cnt=0;
	Q.clear();
	//cout << Q.empty()<<endl;
	for (int i=1;i<=n;i++) if (a[i]!=b[i]){
		cnt++;
		Q.push_back(i);
	}
	if (!cnt) {cout << "Nothing to do here";return 0;}
	if (ever){
		puts("Yes");
		cout << aa <<' ' <<bb;
		return 0;
	}
	if (cnt == 2){
		puts("Yes");
		cout << Q[0] <<' ' << Q[1];
		return 0;
	}
	cout << "No hope";

}