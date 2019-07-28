#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
string s;
int p,q;
bool flag;
vector<int>v;
bool num[10];
int main()
{
	cin>>p>>q;
	s+="0.";
	flag=false;
	vector<int>::iterator it;
	for(int i=0;i<10;i++)
	{
		num[i]=false;
	}
	while(1)
	{
		p*=10;
		for(it=v.begin();it!=v.end();it++)
		{
			if(p==*it)
			{
				flag=true;
				break;
			}
		}
		if(flag)
		break;
		v.push_back(p);
		if(p<q)
		{
			s+='0';
			num[0]=true;
		}
		else
		{
			int temp=p/q;
			s+=(char)(temp+48);
			num[temp]=true;
			p%=q;
		}
	}
	for(int i=0;i<10;i++)
	{
		if(num[i])
		cout<<i;
	}
	cout<<endl;
	return 0;
}