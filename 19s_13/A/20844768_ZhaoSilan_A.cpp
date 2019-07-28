#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int n,i,x,p=0,o=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x>0)
		p++;
		else
		if(x<0)
		o++;
	}
	if(p>=n/2+n%2)
	printf("%d\n",1);
	else
	if(o>=n/2+n%2)
	printf("%d\n",-1);
	else
	printf("0\n");
	return 0;
 } 