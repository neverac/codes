#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int x, y, z;
	int a, b, c;
	cin >> x >> y >> z;
	cin >> a >> b >> c;
	int k;
	bool f = true;
	if (x > a) f = false;
	else a = a - x;
	if (y > a + b) f = false;
	else k =a+b-y;
	if (z > k + c) f = false;
	if (f) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}