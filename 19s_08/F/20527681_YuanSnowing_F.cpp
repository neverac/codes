#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100500],sum;
bool pos,neg,ze;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	ze = pos = neg = false;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		sum += abs(a[i]);
		if(a[i] > 0) pos = true;
		else if(a[i] < 0) neg = true;
		else ze = true;
	}
	sort(a+1,a+n+1);
	if(ze && !pos && !neg){
		cout << 0 <<endl;
		while(n > 1){
			cout << 0 << ' ' << 0 <<endl;
			n --;
		}
		return 0;
	}
	if(neg && pos || ze){
		cout << sum << endl;
		int st = 2,mm = n;
		while(a[st] <= 0){
			cout << a[n] <<' '<<a[st]<<endl;
			a[n] = a[n]-a[st];
			st ++;
			mm --;
		}
		while(mm > 2){
			cout << a[1] <<' ' <<a[n]<<endl;
			a[1] = a[1] -a[n];
			mm --;
			n --;
		}
		cout << a[st] << ' '<< a[1]<<endl;
	}
	else if(pos){
		cout <<sum-a[1]*2<<endl;
		cout << a[1] <<' '<< a[n] <<endl;
		a[1] = a[1]-a[n];
		n --;
		while(n > 2){
			cout << a[1] <<' ' <<a[n]<<endl;
			a[1] = a[1] -a[n];
			n --;
		}
		cout << a[n] << ' '<< a[1]<<endl;
	}
	else {
		int st = 1;
		cout << sum+2*a[n]<<endl;
		cout << a[n] <<' '<< a[1] <<endl;
		a[n] = a[n]-a[1];
		st ++;
		while(st<n){
			cout << a[n] <<' ' <<a[st]<<endl;
			a[n] = a[n] -a[st];
			st ++;
		}
	}
    return 0;
}
