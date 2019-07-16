#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;
int main(){
	int n;
	cin >>n;
	for (int i=1;i<=n;i++){
		string s;
		cin >> s;
		int ans = INF;
		int l=s.length();
		for (int i=0;i<=l;i++) {
			int sum = 0;
			for (int j=0;j<i;j++) if (s[j] == '1') sum++;
			for (int j=i;j<l;j++) if (s[j] == '0') sum++;
			ans=min(ans,sum);
		}
		cout << ans << endl;
	}
}