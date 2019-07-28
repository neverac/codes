#include<iostream>
using namespace std;
int a[107];int n,z,f;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i){cin>>a[i];
	if(a[i]>0)++z;
	if(a[i]<0)++f;}
	int k=(n+1)/2;
	if(z>=k)cout<<"1";
	else if(f>=k)cout<<"-1";
	else cout<<"0";
	return 0;
}