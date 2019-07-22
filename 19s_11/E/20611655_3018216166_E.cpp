#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int a[maxn];
int b[maxn];
int n;
bool cmp(int x, int y) { return x > y; }
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	int cnt = 0;
	int p1 = 0, p2 = 0;
	sort(a + 1, a + 1 + n);
	vector<int> ans1, ans2;
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) {
			ans1.push_back(i);
		}
	}
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) {
			ans2.push_back(i);
		}
	}
	if (ans1.size() == 0 || ans2.size() == 0) {
		cout << "Nothing to do here" << endl;
	}
	else if (ans2.size() == 2) {
		cout << "Yes" << endl;
		if (ans2[0] > ans2[1]) swap(ans2[0], ans2[1]);
		cout << ans2[0] << " " << ans2[1] << endl;
	}
	else if (ans1.size() == 2) {
		cout << "Yes" << endl;
		if (ans1[0] > ans1[1]) swap(ans1[0], ans1[1]);
		cout << ans1[0] << " " << ans1[1] << endl;
	}

	else {
		cout << "No hope" << endl;
	}

	return 0;
}