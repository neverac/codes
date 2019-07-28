#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 1e5+100;

int n;
int a[maxn],z,f;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>0) z++;
		if(a[i]<0) f++;
	}
	if(z>=(n+1)/2){
		cout<<"1"<<endl;
	}
	else if(f>=(n+1)/2){
		cout<<"-1"<<endl;
	}
	else cout<<"0"<<endl;
	return 0;
}