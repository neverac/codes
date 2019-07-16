#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z,a,b,c,ab,abc;
	scanf("%d %d %d",&x,&y,&z);
	scanf("%d %d %d",&a,&b,&c);
	if(a>=x)
	{
		a-=x;ab=a+b;
		if(ab>=y)
		{
			ab-=y;abc=ab+c;
			if(abc>=z)printf("YES");
			else printf("NO");
		}
		else printf("NO");
	}
	else printf("NO");
	return 0;
}