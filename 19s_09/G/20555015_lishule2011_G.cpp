#include <iostream>
using namespace std;
const int maxn=1e6+10;
long long a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	int n;
	a[1]=1,a[2]=5,a[3]=13;
	for (long long i=4;i<maxn;i++) {
		a[i] = 1LL*(a[i-1] + i*(i+1)/2);
		int x = i-1;//cout << "ss";
		a[i]+=x%2?1LL*(x+1)*(x+1)/4:1LL*(x+2)*x/4;
		//  a[i] = (a[i-1] + i*(i+1)/2);
		// int x = i-1;//cout << "ss";
		// a[i]+=x%2?(x+1)*(x+1)/4:(x+2)*x/4;
	}

	while (t--){
		cin >> n;
		cout << a[n]<<endl;
	}
}