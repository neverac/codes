#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int k,a,b; 
	scanf("%lld%lld%lld",&k,&a,&b);
	long long int ans=0;
	if(k>=a+1)
	{
			long long int t=k;
			if(b>a)
			{
				k-=a+1;
				ans=b;
				ans+=(k/2)*(b-a);
				ans+=k%2;
				printf("%lld\n",max(ans,t+1));
			}
			else
			printf("%lld\n",t+1);
	}
	else
	printf("%lld\n",k+1);
	return 0;
}