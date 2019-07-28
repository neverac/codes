#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#define LL long long
using namespace std;

const int maxn = 3e5+100;

int n;
LL a[maxn],z,f;
map<LL,LL> mp1,mp2;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(LL i=1;i<=2*n;i++) cin>>a[i];
	for(LL i=1;i<=2*n;i++)
	{
		if(!mp1[a[i]]){
			mp1[a[i]] = i;
		}
		else mp2[a[i]]= i;
	}
	LL pos1 = 1,pos2 = 1;
	LL ans=0,res=0;
	for(LL i=1;i<=n;i++)	
	{
		LL x = mp1[i],y = mp2[i];
		//cout<<pos1<<" "<<pos2<<" "<<x<<" "<<y<<endl;
		LL T1 = abs(pos1-x)+abs(pos2-y);
		LL T2 = abs(pos1-y)+abs(pos2-x);
		ans += min(T1,T2);
		//cout<<T1<<" "<<T2<<endl;
		pos1=x;pos2=y;
	}
	cout<<ans<<endl;
	return 0;
}
/*
2
2 2 1 1
 */