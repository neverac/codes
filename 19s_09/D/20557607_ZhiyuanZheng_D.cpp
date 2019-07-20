#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const long long MOD = 998244353;
int n,a[maxn];
long long x[4];
string s;
int main(){
	cin>>n;
	cin>>s;
	for (int i=0;i<n;i++){
		int f;
		cin>>f;
		if (s[i]=='h') x[0]+=f;
		if (s[i]=='a') {
			x[1]+=f;
			if (x[1]>x[0]) x[1]=x[0];
		}
		if (s[i]=='r'){
			x[2]+=f;
			if (x[2]>x[1]) x[2]=x[1];
		}
		if (s[i]=='d'){
			x[3]+=f;
			if (x[3]>x[2]) x[3]=x[2]; 
		}
	}
	cout<<x[3]<<endl;
	return 0;
}

