#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
	string s;
	cin>>n;
	while (n--){
		cin>>s;
		bool flag=true;
		if (s[0]=='+'||s[0]=='*') flag=false;
		if (s[0]=='?') s[0]='1';
		if (s[0]=='0'&&s[1]!='+'&&s[1]!='*'&&s[1]!='?') flag=false;
		int pos=0;
		for (int i=1;i<s.size()-1;i++){
			if (!flag) break;
			if (s[i]=='+'||s[i]=='*'){
				if (s[i-1]=='+'||s[i-1]=='*') {
					flag=false;
					break;
				}
				if (pos==0) pos=i;else {
					if (s[pos+1]=='0'&&s[i-1]=='0'&&pos+2!=i) {
						flag=false;
						break;
					}
					pos=i;
				}
			}
			if (s[i]=='0'&&(s[i-1]=='+'||s[i-1]=='*')&&(s[i+1]!='+'&&s[i+1]!='*'&&s[i+1]!='?')) {
				flag=false;
				break;
			} 
			if (s[i]=='?'){
				if (pos!=0){
					if (pos+2==i&&s[pos+1]=='0') {
						s[i]='+';pos=i;
					}else s[i]='1';
				}else {
					if (s[0]=='0'&&i==1) s[i]='+',pos=i;
						else s[i]='1';	
				}
			}
		}
		if (s[s.size()-1]=='+'||s[s.size()-1]=='*') flag=false;
		if (s[s.size()-1]=='?'&&pos!=0&&pos+2==s.size()-1&&s[pos+1]=='0') flag=false;
		if (s[s.size()-1]=='?'&&pos==0&&s[0]=='0') flag=false;
		if (flag&&s[s.size()-1]=='?') s[s.size()-1]='1';
		if (flag) cout<<s<<endl;else cout<<"IMPOSSIBLE"<<endl;		
	}
	return 0;
}

