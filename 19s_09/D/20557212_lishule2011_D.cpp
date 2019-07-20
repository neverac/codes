#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n;
	cin >> n;
	long long v,h=0,a=0,r=0,d=0;
	string s;
	cin >> s;
	for (int i=0;i<n;i++){
		cin >> v;
		if (s[i] == 'h') h += v;
		if (s[i] == 'a') a = h < a+v?h:a+v;
		if (s[i] == 'r') r = a < r+v?a:r+v;
		if (s[i] == 'd') d = r < d+v?r:d+v;
	}
	cout << d;
}