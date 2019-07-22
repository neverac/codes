#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define LL long long
using namespace std;

const int maxn = 1e6+100;

LL k,s;
LL pri[maxn],tot;
bool vis[maxn];
void get_pri()
{
	for(int i=2;i<=1e6;i++)
	{
		if(!vis[i])
		{
			pri[++tot]=i;
			int cnt = 1;
			while(i*cnt<=1e6)
			{
				vis[i*cnt]=true;
				cnt++;
			}
		}
	}
}

LL Sqrt(LL x)
{
	LL l=1,r=1e9+100;
	while(l<=r)
	{
		LL mid = (l+r)>>1;
		if(mid*mid==x){
			return mid;
		}
		if(mid*mid>x) r=mid-1;
		if(mid*mid<x) l=mid+1;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>k;
	if(!k){
		cout<<"1"<<endl;
		return 0;
	}
	get_pri();
	LL res=1;
	for(int i=1;i<=tot;i++)
	{
		int cnt=0;
		while(k%pri[i]==0)
		{
			k/=pri[i];
			cnt++;
			if(cnt%2==0&&cnt) res*=pri[i];
		}
	}
	if(k!=1)
	{
		if(Sqrt(k)) res*=Sqrt(k);
	}
	cout<<res/2+1<<endl;
	return 0;
}