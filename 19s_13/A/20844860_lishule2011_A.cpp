#include <iostream>
using namespace std;

int main(){
	long long pos=0,neg=0;
	int n,a[110]; 
	cin >> n;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		if (a[i]>0) pos++;
		if (a[i]<0) neg++;
	}

	int need;
	if (n%2 == 0) need = n/2;else need = n/2+1;
	if (pos>=need) cout << 1;
	else if(neg>=need) cout << -1;
	else cout << 0;
}