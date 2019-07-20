#include<iostream>
using namespace std;
long long K,A,B;
long long temp;
long long ans;
int main()
{
	cin>>K>>A>>B;
	if(B<=(A+2))
	{
		ans=K+1;
	}
	else
	{
		if(K<=A)
		{
			ans=K+1;
		}
		else
		{
			temp=(K-A+1)/2;
			ans=temp*(B-A)+(K-A+1)%2+A;
		}
	}
	cout<<ans<<endl;
	return 0;
}