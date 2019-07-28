#include<bits/stdc++.h>
using namespace std;
int main()
{
	int P,Q,now,i,tot[15]={0},TT=100000;
	scanf("%d %d",&P,&Q);
	while(TT--)
	{
		P*=10;
		//if(P>=Q)
		{
			now=P/Q;
			P%=Q;
			/*if(tot[now]==0)*/tot[now]++;
			//else if(now!=0)break;
		}
		if(P==0)break;
	}
	for(i=0;i<=9;i++)
	{
		if(tot[i]!=0)printf("%d",i);
	}
	return 0;
}