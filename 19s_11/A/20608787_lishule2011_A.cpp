#include <bits/stdc++.h>

using namespace std;
bool cmp(int a,int b){return a>b;}
int a[100010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long sum=0;
	cin >> n;
	for (int i=1;i<=n;i++) {
		cin >>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long ans = 0;
	for (int i=1;i<=n;i++){
		ans+=(2*sum-a[i])*a[i];
		sum-=a[i];
	}
	cout << ans;
}