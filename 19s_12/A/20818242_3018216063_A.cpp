#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p,q;
    int a[2000000]={};
    int vis[2000000]={};
    cin>>p>>q;
    p*=10;
    while(true)
    {


        a[p/q]++;



        if(p%q==0||vis[p%q]==1) break;
        vis[p%q]=1;
        p=p%q*10;
    }
    for(int i=0;i<10;i++)
	{
		if(a[i]>0)
		cout<<i;
	}
    return 0;
}