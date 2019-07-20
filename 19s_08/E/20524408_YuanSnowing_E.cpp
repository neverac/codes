#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n;
int a[5],x,ans;
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T --){
		cin >> n;
		ans = 0;
		memset(a,0,sizeof a);
		for(int i = 1;i <= n;i ++){
			cin >> x;
			a[x%3] ++;
		}
		ans += a[0];
//		cout << a[0] <<' '<<a[1] <<' '<<a[2] <<endl;
		if(a[2] <= a[1]){
			a[1] -= a[2];
			ans += a[2];
			ans += a[1]/3;
		}
		else{
			a[2] -= a[1];
			ans += a[1];
			ans += a[2]/3;
		}
		cout << ans << endl;
	}
    return 0;
}
