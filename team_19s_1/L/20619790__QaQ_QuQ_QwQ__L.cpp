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
	int t;
	t=get_num();
	while(t--){
		n=get_num();
		for(int i=0;i<n;i++)a[i]=get_num();
		int ans=(int)sqrt(abs(a[0]-a[n-1]));
		cout<<ans<<endl;
	}
	return 0;
}