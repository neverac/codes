#include<iostream>
using namespace std;
int n;
int temp;
int ans;
int num[6];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(temp==4)
		{
			num[0]++;
		}
		else if(temp==8)
		{
			if(num[1]<num[0])
			num[1]++;
		}
		else if(temp==15)
		{
			if(num[2]<num[1])
			num[2]++;
		}
		else if(temp==16)
		{
			if(num[3]<num[2])
			num[3]++;
		}
		else if(temp==23)
		{
			if(num[4]<num[3])
			num[4]++;
		}
		else
		{
			if(num[5]<num[4])
			num[5]++;
		}
	}
	ans=n-num[5]*6;
	cout<<ans<<endl;
	return 0;
}