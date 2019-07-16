#include <bits/stdc++.h>
#define ll long long

using namespace std;
int x, y, z, a, b, c;
int main() {
	scanf("%d%d%d", &x, &y, &z);
	scanf("%d%d%d", &a, &b, &c);// g p b
	if (a < x) {
		printf("NO\n"); return 0;
	}
	else {
		if (a + b - x >= y && a + b + c - x - y >= z) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}