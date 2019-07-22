#include<bits/stdc++.h>
using namespace std;
int const maxn=110;
int n;
long long m,b[maxn];
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
		n=get_num();m=get_num();
		int a;
		for(int i=0;i<n;i++)a=get_num(),b[i]=get_num();
		sort(b,b+n);
		long long ans=0,sum;
		if(b[0]+1>m){
			printf("0\n");
		}
		else{
			ans=1;sum=b[0]+1;
		for(int i=1;i<n;i++){
			sum=sum*(b[i]+1);
			if(sum<=m)ans++;
			else break;
		}
		cout<<ans<<endl;
		}
	}
	return 0;
}