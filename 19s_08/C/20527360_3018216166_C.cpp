#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
int main() {
	ll a, b, k;
	scanf("%lld%lld%lld", &k, &a, &b);
	ll ans1 = k + 1ll;
	ll ans = 0;
	ll d = b - a;
	if (k > a) {
		k -= (a + 1);
		ans += b;
		ll t = k / 2;
		ans += t * d + k % 2;
	}
	printf("%lld\n", max(ans, ans1));
	return 0;
}