#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	int n;

	while (t--){
		cin >> n;
		int x;
		int t1 = 0,t2 = 0,t3 = 0;
		for (int i=1;i<=n;i++) {
			cin >> x;
			if (x%3 == 0) t3++;
			if (x%3 == 1) t1++;
			if (x%3 == 2) t2++;

		}	
		if (t1<t2){
				int t=t1;t1=t2;t2=t;
			}
			t3+=t2 +(t1-t2)/3;
			cout << t3 << endl;
	}
}