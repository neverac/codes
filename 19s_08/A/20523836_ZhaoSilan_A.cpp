#include<stdio.h>
#include<iostream>
using namespace std;
int num[10];
int main()
{
	int n,i,pos,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x==4)
		pos=1;
		else
		if(x==8)
		pos=2;
		else
		if(x==15)
		pos=3;
		else
		if(x==16)
		pos=4;
		else
		if(x==23)
		pos=5;
		else
		pos=6;
		if(pos==1)
		num[1]++;
		else
		if(num[pos-1]>num[pos])
		num[pos]++;
	}
	
	printf("%d\n",n-num[6]*6);
	return 0;
 } 