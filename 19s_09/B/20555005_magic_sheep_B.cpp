#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
char s[201000];
long long l,r,ans,mod=998244353;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	l=0,r=n;
	ans = n*(n+1)/2; 
	if(s[1]==s[n])
	{
		l=1;
		for(int i=2;i<=n;i++)
		{
			if(s[i]==s[1]){
				l++;
			}
			else break;
		}
		r=1;
		for(int i=n-1;i>=1;i--)
		{
			if(s[i]==s[n]){
				r++;
			}
			else break;
		}
		if(l+r>=n){
			cout<<ans%mod<<endl;
			return 0;
		}
		else {
			cout<<(l+1)*(r+1)%mod<<endl;
			return 0;
		}
	}
	else
	{
		l=1;
		for(int i=2;i<=n;i++)
		{
			if(s[i]==s[1]){
				l++;
			}
			else break;
		}
		r=1;
		for(int i=n-1;i>=1;i--)
		{
			if(s[i]==s[n]){
				r++;
			}
			else break;
		}
		cout<<l+r+1<<endl;
		return 0;
	}
	return 0;
}