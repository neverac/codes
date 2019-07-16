#include<iostream>
using namespace std;
int x,y,z;
int a,b,c;
int main()
{
	cin>>x>>y>>z;
	cin>>a>>b>>c;
	a-=x;
	if(a<0)
	cout<<"NO"<<endl;
	else
	{
		int temp=a+b;
		temp-=y;
		if(temp<0)
		cout<<"NO"<<endl;
		else
		{
			int last=temp+c;
			last-=z;
			if(last<0)
			cout<<"NO"<<endl;
			else
			cout<<"YES"<<endl;
		}
	}
	return 0;
}