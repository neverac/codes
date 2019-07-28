#include<iostream>
#include<cstring>
using namespace std;
string s;
int len;
bool flag;
int loc1,loc2;
int loc;
int main()
{
	cin>>s;
	len=s.length();
	flag=false;
	for(int i=1;i<len;i++)
	{
		if(s[i]!=s[i-1])
		{
			flag=true;
			break;
		}
	}
	if(flag==false)
	{
		cout<<1<<endl;
		return 0;
	}
	for(int i=0;i<len;i++)
	{
		if(i==len-i-1)
		{
			for(int j=len/2;j>=0;j--)
			{
				if(s[j]==s[len/2+1])
				loc=j;
				else
				break;
			}
			cout<<loc+1<<endl;
			return 0;
		}
		if(i>len-1-i)
		{
			for(int j=len/2-1;j>=0;j--)
			{
				if(s[j]==s[len/2-1])
				loc=j;
				else
				break;
			}
			cout<<loc+1<<endl;
			return 0;
		}
		if(s[i]!=s[len-1-i])
		{
			loc1=i;
			loc2=len-1-i;
			break;
		}
	}
	for(int i=loc1+1;i<len;i++)
	{
		if(i>len-i)
		break;
		if(s[i]!=s[len-i])
		{
			loc1=-1;
			break;
		}
	}
	if(loc1==-1)
	{
		loc=loc2;
		char temp=s[loc2];
		for(int i=loc2-1;i>=0;i--)
		{
			if(s[i]==temp)
			loc=i;
			else
			break;
		}
	}
	else
	{
		loc=loc1;
		char temp=s[loc1];
		for(int i=loc1-1;i>=0;i--)
		{
			if(s[i]==temp)
			loc=i;
			else
			break;
		}
	}
	cout<<loc+1<<endl;
	return 0;
}