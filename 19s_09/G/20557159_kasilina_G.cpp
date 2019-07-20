#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n;
ll ans[1000015]={};
ll mmp[1000015]={},ca[1000015]={};
int main(){
	for(int i=1;i<=1000005;i++)
	{
		mmp[i]=mmp[i-1]+i;
		if(i>=2)
		ca[i]=i-1+ca[i-2];
	}
	for(int i=1;i<=1000005;i++)
	{
		ans[i]=ans[i-1]+mmp[i]+ca[i];
	}
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << ans[n] << endl;
	}
	return 0;
}
