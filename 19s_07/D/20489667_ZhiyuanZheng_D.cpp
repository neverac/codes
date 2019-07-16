#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	int T;
	cin>>T;
	while (T--){
		cin>>s;
		int x=99999999;
		for (int i=0;i<=s.size();i++){
			int y1=0,y0=0;
			for (int j=0;j<i;j++) {
				if (s[j]=='1') y1++;
			}
			for (int j=i;j<s.size();j++) {
				if (s[j]!='1') y0++;
			}
			x=min(x,y1+y0);
			//cout<<x<<endl;
		}
		cout<<x<<endl;
	}
	return 0;
}

