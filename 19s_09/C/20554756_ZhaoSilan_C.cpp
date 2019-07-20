#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double an;
		int i;
		scanf("%lf",&an);
		bool flag=0;
		for(i=3;i<=998244353;i++)
		{
			double minl=(180.0-360.0/(1.0*i))/(1.0*i-2.0);
			double maxl=(180.0-360.0/(1.0*i));
			if(abs(an-((int)(an/minl))*minl)<1e-6&&(an<maxl||abs(an-maxl)<1e-6))
			{
//				printf("%lf %lf %lf\n",an,minl,maxl);
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",i);
		}
	}
	return 0;
}