#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[105];
int b[10];
int main(){
    cin >> t;
    while(t--)
    {
    	memset(b,0,sizeof(b));
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++)
    	{
    		scanf("%d",&a[i]);
    		a[i]%=3;
    		b[a[i]]++;
		}
		long long ans=0;
		ans+=b[0];
		if(b[1]==b[2])
		ans+=b[1];
		else if(b[1]>b[2])
		{
			ans+=b[2];
			b[1]-=b[2];
			ans+=b[1]/3;
		}
		else
		{
			ans+=b[1];
			b[2]-=b[1];
			ans+=b[2]/3;
		}
		cout << ans << endl;
	}
    return 0;
}