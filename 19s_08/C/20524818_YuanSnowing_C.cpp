#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k,a,b,bis,yen;
int main(){
	ios::sync_with_stdio(false);
	cin >> k >> a >> b;
	bis = 1;
	if(b-a <= 2 || k+1 < a) cout << k+1;
	else{
		while(bis < a){
			k --;
			bis ++;
		}
		if(k%2 == 0) cout << (k/2)*(b-a) +bis;
		else cout << (k/2)*(b-a) + 1 + bis;
	}
    return 0;
}
