#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 2e5 + 5;
typedef struct {
	int num;
	int origin;
	int issuan = 0;
}point;
bool cmp1(point x, point y) {
	return x.num < y.num;
}
bool cmp2(point x, point y) {
	return x.origin < y.origin;
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	point a[MAXN];
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num;
		a[i].origin = i;
	}
	sort(a + 1, a + n + 1,cmp1);
	long long  sum = 0;
	for (int i = n; i > n - m * k; i--) {
		sum += a[i].num;
		a[i].issuan = 1;
	}
	sort(a + 1, a + n + 1, cmp2);
	cout << sum << endl;
	int count = 0;
	int count_k = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].issuan == 1) {
			count++;
			if (m == count) {
				cout << i << " ";
				count = 0;
				count_k++;
			}
			
		}
		if (count_k == k - 1) break;
	}
	return 0;
}