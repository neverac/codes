#include <bits/stdc++.h>
using namespace std;
int n;
int x=0,y=0;
int a[105]; 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>0) x++;
		else if(a[i]<0) y++;
	}
	if(x*2>=n) printf("1\n");
	else if(y*2>=n) printf("-1\n");
	else printf("0\n");
    return 0;
}