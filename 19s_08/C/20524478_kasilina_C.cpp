#include <bits/stdc++.h>
using namespace std;
int k,a,b;

int main(){
    cin >> k >> a >> b;
    long long ans=1;
    int l=0;
    if(a>=b-2)
    {
    	cout << ans+k << endl;
	}
	else
	{
		k-=a-1;
		ans=a;
		if(k%2==0)
		{
			ans+=(long long)(b-a)*k/2;
		}
		else
		{
			ans+=(long long)(b-a)*(k-1)/2;
			ans++;
		}
		cout << ans << endl;
	}
    return 0;
}
