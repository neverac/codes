#include <iostream>
#include <cstring>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,a[400];
	cin >> n;
	memset(a,0,sizeof(a));

	for (int i=3;i<=400;i++)
		for (int j=1;j<=i-2;j++){
			if ((180*j)%i!=0) continue;
			int ang = (180*j)/i;
			if (!a[ang]) a[ang] = i;
		}
	//for (int i=1;i<=180;i++)cout << a[i] << endl;
	while(n--){
		int x;
		cin >> x;
		if (a[x]) cout << a[x] <<endl;else cout << -1<<endl;
	}
}