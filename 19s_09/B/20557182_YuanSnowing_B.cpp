#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M = 998244353ll;
string s;
ll l,c1,c2;
int main(){
	ios::sync_with_stdio(false);
	cin >> l >> s;
	ll i = 1ll,j = l-2ll;
	c1=1ll;c2=1ll;
	while(i < l){
		if(s[i] != s[i-1ll]) break;
		i ++;
		c1 ++;
	}
	while(j >= i){
		if(s[j] != s[j+1ll]) break;
		j --;
		c2 ++;
	}
	/*if(j == i)	cout << '#'<<((l%M)*((l+1)%M)/2)%M<<endl;
	else*/ if(s[0ll] == s[l-1ll]) cout <<(((c1+1ll)%M)*((c2+1ll)%M))%M << endl;
	else cout << (c1+c2+1ll)%M<<endl; 
    return 0;
}