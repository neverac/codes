#include<bits/stdc++.h>
using namespace std;
int const maxn=1e5+10;
int n,a[maxn],b[maxn];
inline int get_num(){
	char ch;
	bool flag=false;
	int num=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
	return num;
}
bool cmp(int x,int y){
	return x>y;
}
void work(){
	bool flag=0,flag2=0;
	sort(b,b+n);
	int ans=0,ans2=0,z[5],z2[5];
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			z[++ans]=i;
			if(ans>=3){
				flag=true;break;
			}
		}
	}
	sort(b,b+n,cmp);
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			z2[++ans2]=i;
			if(ans2>=3){
				flag2=true;break;
			}
		}
	}
	if(flag&&flag2){
		printf("No hope\n");
		return ;
	}
	if(ans==0||ans2==0){
		printf("Nothing to do here\n");
		return ;
	}
	if(!flag){
		printf("Yes\n%d %d\n",z[1]+1,z[2]+1);
		return ;
	}
	printf("Yes\n%d %d\n",z2[1]+1,z2[2]+1);
		return ;
}
int main(){
	n=get_num();
	for(int i=0;i<n;i++){
		a[i]=get_num();b[i]=a[i];
	}
	work();
	return 0;
}