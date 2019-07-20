#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,a;
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T --){
		cin >> a;
		int n = 3;
		bool ok = false;
		while(n <= 998244353){
			if(n*a % 180 != 0 || n*a/180 >= n-1){
				n ++;
			}
			else{
				cout << n << endl;
				ok =  true;
				break;
			}
		}
		if(!ok) cout << -1 << endl;
	}
    return 0;
}
