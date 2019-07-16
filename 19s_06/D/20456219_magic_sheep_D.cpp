#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a,b,c,x,y,z;
int main()
{
	cin>>x>>y>>z;
	cin>>a>>b>>c;
	if(x>a)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else a-=x;
	if(y>a+b)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	if(y+z>a+b+c)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	return 0;
}