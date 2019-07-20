#include<bits/stdc++.h>
using namespace std;
int n,t,c[4];
inline int get_num(){
	char ch;
	
	int num=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
	
	return num;
}
int main(){
	cin>>t;
	while(t--){
		n=get_num();
		int a;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++){
			a=get_num();
			c[a%3]++;
		}
		if(c[1]==c[2])printf("%d\n",c[0]+c[1]);
		else {
			int ans;
			if(c[1]<c[2])ans=c[0]+c[1]+(c[2]-c[1])/3;
			else ans=c[0]+c[2]+(c[1]-c[2])/3;
			printf("%d\n",ans);
		}
	}


	return 0;
}