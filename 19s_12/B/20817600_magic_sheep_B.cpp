#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 5e5+100;

char s[maxn];
unsigned long long has1[maxn],has2[maxn],bs=131,base[maxn];
int main()
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		has1[i] = has1[i-1]*bs+s[i];
	}
	for(int i=n;i>=1;i--)
	{
		has2[i] = has2[i+1]*bs+s[i];
	}
	base[0] = 1;
	for(int i=1;i<=n;i++) base[i] = base[i-1]*131;
	for(int i=1;i<=n;i++)
	{
		unsigned long long hs1 = has1[n]- has1[i]*base[n-i] + has1[i-1]*base[n-i];
		unsigned long long hs2 = has2[1] -has2[i]*base[i-1] + has2[i+1]*base[i-1];
		if(hs1==hs2){
			printf("%d\n", i);
			return 0;
		} 
	}

	return 0;
}