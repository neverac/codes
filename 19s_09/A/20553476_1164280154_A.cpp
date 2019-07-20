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
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		for (int i = x; i <= y; i++) {
			if (x * 2 <= y) {
				cout << x << " " << x * 2 << endl;
			break;
			}
		}
	}
	return 0;
}