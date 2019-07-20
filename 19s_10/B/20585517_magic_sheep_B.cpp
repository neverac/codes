#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 2e5+100;

int h,w,n,x,y;
char s1[maxn];
char s2[maxn];
int ans=0;
int L[maxn],R[maxn],U[maxn],D[maxn];
int main()
{
	cin>>h>>w>>n;
	cin>>x>>y;
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	ans=0;
	/*for(int i=1;i<=n;i++)
	{
		if(s[i]=='L') L[i]++;
		if(s[i]=='R') R[i]++;
		if(s[i]=='U') U[i]++;
		if(s[i]=='D') D[i]++;
		L[i]+=L[i-1];R[i]+=R[i-1];
		U[i]+=U[i-1];D[i]+=D[i-1];
	}*/
	for(int i=1;i<=n;i++)
	{
		if(s1[i]=='L') ans++;
		if(ans>=y){
			cout<<"NO"<<endl;
			return 0;
		}
		if(s2[i]=='R')
		{
			if(ans<0&&abs(ans-1)==w-y+1) continue;
			ans--;
		} 
	}
	ans=0;
	//cout<<"111111"<<endl;
	for(int i=1;i<=n;i++)
	{
		if(s1[i]=='U') ans++;
		if(ans>=x){
			cout<<"NO"<<endl;
			return 0;
		}
		if(s2[i]=='D')
		{
			if(ans<0&&abs(ans-1)==h-x+1) continue;
			ans--;
		} 
	}
	//cout<<"22222222222"<<endl;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s1[i]=='R') ans++;
		if(ans>=w-y+1){
			cout<<"NO"<<endl;
			return 0;
		}
		if(s2[i]=='L')
		{
			if(ans<0&&abs(ans-1)==y) continue;
			ans--;
		} 
	}
	//cout<<"333333333333333"<<endl;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s1[i]=='D') ans++;
		if(ans>=h-x+1){
			cout<<"NO"<<endl;
			return 0;
		}
		if(s2[i]=='U')
		{
			if(ans<0&&abs(ans-1)==x) continue;
			ans--;
		} 
	}
	//cout<<"4444444444444444444444444444444444444"<<endl;
	cout<<"YES"<<endl;
	return 0;
}