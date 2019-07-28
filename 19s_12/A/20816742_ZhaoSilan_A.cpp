#include<stdio.h>
#include<iostream>
using namespace std;
bool vis[100];
int main()
{
	int p,q;
	scanf("%d%d",&p,&q);
	for(int i=0;i<100000;i++)
	{
		vis[p*10/q]=1;
		p=p*10%q;
	}
	
	for(int i=0;i<10;i++)
	{
		if(vis[i])
		printf("%d",i);
	}
	return 0;
}