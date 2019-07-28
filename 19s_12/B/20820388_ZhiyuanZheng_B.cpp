#include <bits/stdc++.h>
using namespace std;
string s;
int mi=1e6;
void find(int l,int r){
	if (l>r) return ; 
	bool ok=true;
	int i=l+1,j=r;
	while (i<j){
		if (s[i]==s[j]) i++,j--;
		else {
			ok=false;
			break;
		}
	}
	if (ok) {
		mi=min(mi,l+1);
	}
	i=l;j=r-1;
	ok=true;
	while (i<j){
		if (s[i]==s[j]) i++,j--;
		else {
			ok=false;
			break;
		}
	}
	if (ok){
		mi=min(mi,r+1);
	}
	if (s[l]==s[r]) find(l+1,r-1);
	
}
int main(){
	cin>>s;
	find(0,s.size()-1);	
	cout<<mi<<endl;
	return 0;
}