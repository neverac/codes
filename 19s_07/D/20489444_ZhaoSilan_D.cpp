#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
char s[1005];
int d0[1005],d1[1005];
int main()
{
	int n;
	scanf("%d\n",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%s",s+1); 
		int len=strlen(s+1);
		
		for(int j=1;j<=len;j++)
		{
			if(s[j]-48==0)
			d0[j]=d0[j-1]+1,d1[j]=d1[j-1];
			else 
			d0[j]=d0[j-1],d1[j]=d1[j-1]+1;
		}
		
		int ans=2147483647;
		for(int j=1;j<=len+1;j++)
		{
			ans=min(ans,d1[j-1]+d0[len]-d0[j-1]);
		}
		
		printf("%d\n",ans);
	}
	return 0;
}