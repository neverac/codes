#include<algorithm>
#include<iostream>
using namespace std;
int n;
int d;
int a[100];
int minnum;
int maxnum;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	minnum=a[0];
	maxnum=a[n-1];
	for(int i=minnum;i<=maxnum;i++)
	{
		int num=0;
		if(i==0)
		{
			continue;
		}
		for(int j=0;j<n;j++)
		{
			if(i<0)
			{
				if(a[j]<0)
				num++;
			}
			else
			{
				if(a[j]>0)
				num++;
			}
		}
		if(n/2-n/(2*1.0)==0)
		{
			if(num>=n/2)
			{
				d=i;
				break;
			}
		}
		else
		{
			if(num>=n/2+1)
			{
				d=i;
				break;
			}
		}
	}
	cout<<d<<endl;
	return 0;
}