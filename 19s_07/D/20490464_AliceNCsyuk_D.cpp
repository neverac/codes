#include<iostream>
#include<cstring>
using namespace std;
string s;
int T;
int cnt0[1001];
int num0;
int ans;
int loc;
int count;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>s;
		loc=s.size()+1;
		num0=0;
		count=0;
		ans=10000;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='1')
			{
				loc=i;
				break;
			}
		}
		if(loc==s.size()+1)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=s.size()-1;i>=loc;i--)
		{
			cnt0[i]=0;
			if(s[i]=='0')
			{
				num0++;
				cnt0[i]=num0;
			}
			else
			{
				cnt0[i]=num0;
			}
		}
		for(int i=loc;i<s.size();i++)
		{
			if(s[i]=='0')
			{
				continue;
			}
			else
			{
				int temp=count+cnt0[i];
				ans=min(ans,temp);
				count++;
			}
		}
		cout<<min(ans,count)<<endl;
	}
	return 0;
}