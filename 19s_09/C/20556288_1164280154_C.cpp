#include<iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <cmath>

using namespace std;


int main() {
	int a[190], x;
	for (int i = 1; i < 180; i++) {
		a[i] = -1;
	}
	for (int i = 3; i <= 370; i++) {
		for (int j = 1; j <= i - 2; j++) {
			if ((180 * j) % i == 0) {
				int ang = (180 * j) / i;
				if (a[ang] == -1) a[ang] = i;
			}
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int x;
		cin >> x;
		cout << a[x] << endl;
	}
	return 0;
}