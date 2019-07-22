#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
char a[1005],b[1005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a+1);
		int tmp=1;
		bool flag=0;
		int len=strlen(a+1);
		for(int i=1;a[i];i++)
		{
			if(a[i]=='?')
			{
			   if(tmp==2)//死亡状态 
			   {
			   	b[i]='+';
			   	tmp=1;
			   }
			   else
			   {
			   	b[i]='1';
			   	tmp=0;
			   }
		    }
			else
			if(a[i]=='*'||a[i]=='+')
			{
				if(tmp==1)
				{
					flag=1;
					break;
				}
				tmp=1;
				b[i]=a[i];
		    }
		    else
		    {
		    	if(a[i]=='0')
		    	{
		    		if(tmp==1&&a[i+1]>=48&&a[i+1]<=57)
		    		{
		    			flag=1;
		    			break;
					}
					else
					if(tmp==1&&a[i+1]=='?') 
					{
						b[i]=a[i];
						tmp=2;
				    }
				    else
				    {
				    	tmp=0;
				    	b[i]=a[i];
					}
				}
				else
				{
					tmp=0;
					b[i]=a[i];
				}
			}
		}
		if(tmp==1)
		flag=1;
		
		b[len+1]=0;
		
		if(flag)
		{
			printf("IMPOSSIBLE\n");
		}
		else
		{
			printf("%s\n",b+1);
		}
	}
	return 0;
}