#include <iostream>
using namespace std;

int main(){
	long long k,a,b;
	cin >> k >> a >> b;
	long long ans = k+1;
	if (k>=a+1)
	ans=max(ans,b+(b-a)*((k-a-1)/2)+(k-a-1)%2);
	cout << ans;
}