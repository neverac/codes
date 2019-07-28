#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long a,b;
int mp[1005];
int main()
{
	cin>>a>>b;
	int T=1000000;
	while(T--)
	{
		if(a==0) break;
		a=a*10;
		long long t = a/b;
		mp[t] = 1;
		a-=t*b;
	}
	for(int i=0;i<=9;i++) if(mp[i]) cout<<i;
		cout<<endl;
	return 0;
}
