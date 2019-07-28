#include<iostream>
#include<cmath>
using namespace std;
int num[100001][3];
int n;
int a;
long long ans;
int main()
{
	cin>>n;
	for(int i=0;i<2*n;i++)
	{
		cin>>a;
		num[a][0]++;
		num[a][num[a][0]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			ans=num[1][1]+num[1][2];
		}
		else
		{
			ans+=min(abs(num[i][1]-num[i-1][1])+abs(num[i][2]-num[i-1][2]),abs(num[i][2]-num[i-1][1])+abs(num[i][1]-num[i-1][2]));
		}
	}
	cout<<ans<<endl;
	return 0;
}