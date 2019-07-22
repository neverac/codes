#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <iomanip>
#include <cstring>

using namespace std;
typedef long long ll;

struct node {
	ll num;
	int order;
}a[100005],b[100005];

bool cmps(node a, node b) {
	return a.num < b.num;
}
bool cmpn(node a, node b) {
	return a.num > b.num;
}
int main(){
    ll n;
	cin >> n;
	bool issun = 1;
	bool isni = 1;
	for (int i = 1; i <= n; i++){
		cin >> a[i].num;
		b[i].num = a[i].num;
		if (a[i].num < a[i - 1].num && i>=2) issun = 0;
		if (a[i].num > a[i - 1].num && i>=2) isni = 0;
	}
	if (issun || isni) { cout << "Nothing to do here" << endl; return 0; }
	sort(a + 1, a + n + 1,cmps);
	ll count = 0;
	ll index1, index2;
	for (int i = 1; i <= n; i++) {
		if (a[i].num != b[i].num) {
			count++;
			if (count == 1) index1 = i;
			if (count == 2)index2 = i;
		}
	}
	if (count == 2) { cout << "YES" << endl; cout << index1 << " " << index2 << endl; return 0; }


	sort(a + 1, a + n + 1, cmpn);
   
	ll count1 = 0;
	ll index3, index4;
	for (int i = 1; i <= n; i++) {
		if (a[i].num != b[i].num) {
			count1++;
			if (count1 == 1) index3 = i;
			if (count1 == 2)index4 = i;
		}
	}
	if (count1 == 2) { cout << "YES" << endl; cout << index3 << " " << index4 << endl; return 0; }

	cout << "No hope" << endl;
	return 0;
}