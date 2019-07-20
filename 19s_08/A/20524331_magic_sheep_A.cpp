#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e6+100;

int T,n,ans;
int a[maxn],mp[1000];
int sum[100]={4,8,15,16,23,42};
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int id=0;
		for(int j=0;j<=5;j++)
		{
			if(a[i]==sum[j]){
				id = j;
				break;
			}
		}
		if(id==0) mp[id]++;
		else if(mp[id-1]){
			mp[id-1]--;mp[id]++;
		}
	}
	cout<<n-mp[5]*6<<endl;
	return 0;
}