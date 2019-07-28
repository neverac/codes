#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
char s[500005];
int op;
int head[500005];
int main()
{
	scanf("%s",&s);
	int l=strlen(s);
	head[0]=1;
	for(int i=1;i<l;i++)
	{
		if(s[i]==s[i-1])
		{
			head[i]=head[i-1];
		}
		else head[i]=i+1;
	}
	int i=0,j=l-1;
	while(i<j)
	{
		if(s[i]==s[j])
		{
			i++;j--;
		}
		else 
		{
			break;
		}
	}
	if(i==j)
	{
		cout << head[i] << endl;
	}
	else if(s[i+1]=s[j])
	{
		cout << head[i] << endl;
	}
	else 
	{
		cout << j+1 << endl;
	}
    return 0;
}/////