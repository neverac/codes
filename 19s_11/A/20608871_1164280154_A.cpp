#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;
typedef long long ll;
int a[100005];
int main(){
	int n;
	cin >> n;
	ll ans = 0;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= n; i++) {
		ans += sum * a[i];
		sum -= a[i];
		ans += sum * a[i];
	}
	cout << ans << endl;
	return 0;
}