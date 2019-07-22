#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,n,ans,tot;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a;
		tot += a;
	}
	cout << tot*tot;
    return 0;
}
