#include<bits/stdc++.h>
using namespace std;
int const maxn=1e5+10;
int n,a[maxn];
inline int get_num(){
	char ch;
	int num=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
	return num;
}
int main(){
	n=get_num();
	long long sum=0,ans=0;
	for(int i=0;i<n;i++){
		a[i]=get_num();
		sum+=a[i];
	}
	sort(a,a+n);
	ans+=a[0]*sum;
	for(int i=1;i<n;i++){
		sum-=a[i-1];
		ans+=(a[i-1]+a[i])*sum;
	}
	cout<<ans<<endl;
	return 0;
}