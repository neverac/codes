#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y,z,g,b,p;

int main(){
	cin >> x>>y>>z;
	cin >> g >> p >> b;
	if(g<x){
		cout << "NO";
	}
	else{
		g -= x;
		if(g + p < y){
			cout << "NO";
		}
		else{
			if(g+p+b>=y+z) cout <<"YES";
			else cout <<"NO";
		}
	}
    return 0;
}
