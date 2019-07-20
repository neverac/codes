#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool pd;
	int du,T,s1,d,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&s1);
		//if(s1==179){printf("360\n");continue;}
		/*pd=false;
		for(d=s1;d>=1;d--)
		{
			if(s1%d==0&&180%d==0)
			{
				n=180/d;
				if(((n-2)*180)%n==0&&((n-2)*180)/n>=s1)
				{
					printf("%d\n",180/d);
					pd=true;
					break;
				}
			}
		}
		if(pd==false)printf("-1\n");*/
		
		for(n=3;n<=180;n++)
		{
			du=180/n;
			if((n*s1)%180==0&&(s1*n)%180==0&&(n-2)*180>=n*s1){printf("%d\n",n);break;}
		}
		if(n>180)printf("360\n");
	}
	return 0;
}