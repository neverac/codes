#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll n, m, ans;
ll a[maxn];
int main() {
	scanf("%lld", &n);
	ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		m += a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		ans += m * a[i];
		m -= a[i];
		ans += m * a[i];
	}
	printf("%lld\n", ans);
	return 0;
}