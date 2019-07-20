#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char s[200005];
int main(){
	cin >> n;
	scanf("%s",&s);
	ll left=1;ll right=1;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]!=s[i+1])
		break;
		left++;
	}
	for(int i=strlen(s)-1;i>=0;i--)
	{
		if(s[i]!=s[i-1]) break;
		right++;
	}
	if(s[0]==s[strlen(s)-1])
	printf("%lld\n",((left+1)*(right+1))%998244353);
	else
	printf("%lld\n",(left+right+1)%998244353);
	return 0;
}
