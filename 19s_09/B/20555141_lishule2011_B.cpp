#include <iostream>
#define MOD 998244353
using namespace std;

int main(){
	int n,l;
	cin >> n;
	string s;
	cin >> s;
	l = s.length();
	int i=0,a=1,b=1;
	while (s[i] == s[i+1]) i++,a++;
	int j = l-1;
	while (s[j] == s[j-1]) j--,b++;
	i++;
	long long ans = 0;
	if (s[0] == s[l-1]) 
		ans = 1LL*(a+1)*(b+1)%MOD;
	else 
		ans = (a+b+1) % MOD;
	cout << ans;
}