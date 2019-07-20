#include<bits/stdc++.h>
using namespace std;
int const maxn=5e5+10;
int n,a[maxn],cou[10];
inline int get_num(){
	char ch;
	
	int num=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
	
	return num;
}
int change(int x){
	if(x==4)return 1;
	if(x==8)return 2;
	if(x==15)return 3;
	if(x==16)return 4;
	if(x==23)return 5;
	return 6;
}
int w(){
	if(n<6)return n;
	int ans=0;
	memset(cou,0,sizeof(cou));
	for(int i=1;i<=n;i++){
		cou[a[i]]++;
		for(int j=1;j<a[i];j++){
			while(cou[j]<cou[a[i]]){
				cou[a[i]]--;ans++;
			}
		}
	}
	int m=cou[1];
	for(int i=2;i<=6;i++)m=min(m,cou[i]);
	for(int i=1;i<=6;i++)ans+=cou[i]-m;
	return ans;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i]=change(get_num());
	}
	int ans=w();
	printf("%d\n",ans);

	return 0;
}