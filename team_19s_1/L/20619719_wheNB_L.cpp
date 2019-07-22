#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int t;
int main()
{
    cin >> t;
    while(t--)
    {
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++)
    	{
    		scanf("%d",&a[i]);
		}
		printf("%d\n",(int)sqrt(abs(a[n]-a[1])));
	}
    return 0;
}
