#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	long long  x,y;
	while (t--){
		cin >> x>> y;
		cout <<x << ' '<< x*2 << endl;
	}
}