#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[1000100];
ll T,n,t;
int main(){
	ios::sync_with_stdio(false);
	f[1] = 1;
	f[2] = 5;
	for(ll i = 3;i <= 1000000;i ++){
		f[i] = f[i-1ll]+(i+1ll)*i/2ll;
		if(i % 2ll == 0) f[i] += i*i/4ll;
		else {
			t = i/2ll;
			f[i] += (i+1ll)*t/2ll;
		}
	}
	cin >> T;
	while(T --){
		cin >> n;
		cout << f[n] << endl;
	}
    return 0;
}
