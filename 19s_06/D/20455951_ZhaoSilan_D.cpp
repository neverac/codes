#include<stdio.h>
#include<iostream>
using namespace std;
int x,y,z,a,b,c;
int main()
{
	scanf("%d%d%d",&x,&y,&z);
	scanf("%d%d%d",&a,&b,&c);
	bool flag=1;
	if(a-x<0)
	flag=0;
	else
	a-=x;
	
	int s=a+b;
	if(s-y<0)
	flag=0;
	else
	s-=y;
	
	if(s+c-z<0)
	flag=0;
	
	if(flag)
	printf("YES\n");
	else
	printf("NO\n");
	return 0;
}