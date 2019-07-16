#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char s[100005];
char dy[30];
int cnt[30];
int main()
{
	scanf("%s",s+1);
	
	int len=strlen(s+1);
//	printf("%d\n",len);
	sort(s+1,s+len+1);
	
	int tmp=0;
//	puts(s+1);
	for(int i=1;i<=len;i++)
	{
//		printf("%d \n",s[i]);
		if(s[i]==s[i-1])
		cnt[tmp]++;
		else
		{
			tmp++;
			cnt[tmp]=1;
			dy[tmp]=s[i];
		}
	}
	
//	for(int i=1;i<=tmp;i++)
//	printf("%d\n",cnt[i]);
//	
	int num=len;
	bool flag=0;
	for(int i=1;i<=tmp;i++)
	{
		if(2*cnt[i]>num+1)
		{
			flag=1;
			break;
		}
	}
	
	if(flag)
	{
		printf("INVALID\n");
		return 0;
	}
	
	int j,pre=0;
	
	for(int i=1;i<=len;i++)
	{
		flag=0;
		for(j=1;j<=tmp;j++)
		{
//			printf("%d %d\n",cnt[j],num);
			if(2*cnt[j]==num+1)
			{
				
			  flag=1;
			  break;
			}
		}
		
		if(flag)
		{
		   printf("%c",dy[j]);
		   pre=j;
		   cnt[j]--;
		   num--;
		}
		else
		{
			for(j=1;j<=tmp;j++)
			{
				if(cnt[j]&&pre!=j)
				break;
			}
			printf("%c",dy[j]);
		    pre=j;
		    cnt[j]--;
		    num--;
		}
	}
	
	return 0;
}