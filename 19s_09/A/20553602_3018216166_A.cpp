#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int l, r;
		scanf("%d%d", &l, &r);
		for (int i = l; i <= r; i++) {
			if (i * 2 <= r) {
				printf("%d %d\n", i, i * 2);
				break;
			}
		}
	}
	return 0;
}