#include<iostream>
using namespace std;
int t;
int n;
long long temp;
int num[3];
int ans;
int main()
{
	cin>>t;
	while(t--)
	{
		ans=0;
		for(int i=0;i<3;i++)
		{
			num[i]=0;
		}
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			num[temp%3]++;
		}
		ans+=num[0];
		if(num[2]>=num[1])
		{
			ans+=num[1];
			num[2]-=num[1];
			ans+=num[2]/3;
		}
		else
		{
			ans+=num[2];
			num[1]-=num[2];
			ans+=num[1]/3;
		}
		cout<<ans<<endl;
	}
	return 0;
}