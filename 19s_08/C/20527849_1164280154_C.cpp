#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>

using namespace std;

typedef long long ll;
ll k, a, b;
ll sum;
int main() {
	scanf("%lld%lld%lld", &k, &a, &b);
	sum = 1;
	if (b - a <= 1 || k <= a - 1) { printf("%lld\n", k + 1); return 0; }
	k = k - a + sum;
    sum = a;
    sum += b*(k / 2);
	sum -= a * (k / 2);
    if (k & 1) sum++;
	printf("%lld\n", sum);
	return 0;
}