#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>

using namespace std;

typedef long long ll;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[105] = {};
		int b[3] = {};
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] % 3 != 0) { b[a[i] % 3]++; }
			else ans++;
		}
		if (b[1] > b[2]) {
			ans += b[2];
			b[1] -= b[2];
			ans += b[1] / 3;
		}
		else {
			ans += b[1];
			b[2] -= b[1];
			ans += b[2] / 3;
		}
		cout << ans << endl;
	}
	return 0;
}