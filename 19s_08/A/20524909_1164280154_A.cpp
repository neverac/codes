#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>

using namespace std;
const int MAXN = 500010;
typedef long long ll;

int main() {
	ll n;
	ll a[MAXN];
	ll b[7] = {};
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 4) { b[1]++; }
		if (a[i] == 8) {
			if (b[1] > b[2])
				b[2]++;
			else ans++;
		}
		
		if (a[i] == 15) {
			if (b[2] > b[3]) {
				b[3]++;
			}
			else ans++;
		}
		if (a[i] == 16) {
			if (b[3] > b[4]) {
				b[4]++;
			}
			else ans++;
		}
		if (a[i] == 23) {
			if (b[4] > b[5]) {
				b[5]++;
			}
			else ans++;
		}
		if (a[i] == 42) {
			if (b[5] > 0) {
				for (int i = 1; i <= 5; i++) {
					b[i]--;
				}
			}
			else ans++;
		}
	}
	for (int i = 1; i <= 5; i++) {
		ans += b[i];
	}
	cout << ans << endl;
	return 0;
}