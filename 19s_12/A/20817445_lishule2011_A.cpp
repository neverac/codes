#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[20];
int main(){
	int p,q;
	cin >> p >> q;
	long double b=double(p)/double (q);
	// cout << b << endl;
	memset(a,0,sizeof(a));
	p = p*10;
	int t = p;
	for (int i=0;i<q-1;i++){
		int  x= t/q;
		a[x] = 1;
		t = t % q* 10;

	}
	for (int i=0;i<=9;i++) if (a[i]) cout << i;
}