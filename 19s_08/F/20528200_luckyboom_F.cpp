#include<bits/stdc++.h>
using namespace std;
int const maxn=1e5+10;
int n,t,c[4],a[maxn];
stack<int>s;
inline int get_num(){
	char ch;
	bool flag=false;
	int num=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')flag=true;ch=getchar();}
	while(ch>='0'&&ch<='9'){num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
	if(flag)return -1*num;
	return num;
}
void work(){
	int sum=0,z;

	if(a[1]>=0){
		sum=-a[1];
		for(int i=2;i<=n;i++)sum+=a[i];
			cout<<sum<<endl;
		z=a[1];
		for(int i=n-1;i>1;i--){
			printf("%d %d\n",z,a[i]);
			z-=a[i];
		}
		printf("%d %d\n",a[n],z);
		return ;
	}
	sum=a[n]-a[1];
	for(int i=2;i<n;i++)sum+= a[i]>=0?a[i]:-a[i];
	cout<<sum<<endl;
	z=a[1];
	int i;
	for(i=n-1;i>1;i--){
			if(a[i]<0)break;
			printf("%d %d\n",z,a[i]);
			z-=a[i];
	}
	printf("%d %d\n",a[n],z);
	z=a[n]-z;
	for(;i>1;i--){
		printf("%d %d\n",z,a[i]);
		z-=a[i];
	}
}
int main(){
	n=get_num();
	for(int i=1;i<=n;i++)a[i]=get_num();
	sort(a+1,a+n+1);
	work();
	return 0;
}