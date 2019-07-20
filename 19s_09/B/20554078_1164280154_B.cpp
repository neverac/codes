#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	string s;
	getchar();
	getline(cin, s);
	ll h = s.length();
	char top = s[0];
	char tail = s[h - 1];
	bool f = false;
	if (top == tail) f = true;
	ll count = 1;
	ll count2 = 1;
	for (int i = 1; i < h; i++) {
		if (s[i] == top) count++;
		else break;
	}
	for (int i = h - 2; i >= 0; i--) {
		if (s[i] == tail) count2++;
		else break;
	}
	ll ans = 0;
	if (f) {
		ans += (count2+1)*(count+1);
	}
	else {
		ans += count + count2+1;
	}
	cout << ans % 998244353 << endl;
	return 0;
}