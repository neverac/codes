#include<bits/stdc++.h>
using namespace std;
int const maxn=1005;
int n,dis1[maxn],dis0[maxn];
string s;
int main(){
	
	cin>>n;
	while(n--){
		memset(dis1,0,sizeof(dis1));
		memset(dis0,0,sizeof(dis0));
		
		cin>>s;
		
		int len=s.length();
		if(len==1)printf("0\n");
		else {
		
		if(s[0]=='1')dis1[0]++;
		for(int i=1;i<len;i++){
			if(s[i]=='1')dis1[i]=dis1[i-1]+1;
			else dis1[i]=dis1[i-1];
		}
		dis0[len]=0;
		for(int i=len-1;i>=0;i--){
			if(s[i]=='0')dis0[i]=dis0[i+1]+1;
			else dis0[i]=dis0[i+1];
		}
		int m=maxn;
		//0for(int i=0;i<len;i++)printf("%d %d\n",dis1[i],dis0[i]);
		m=min(m,dis0[1]);
		m=min(m,dis1[len-2]);

		for(int i=1;i<len-1;i++){
			if(s[i]=='1')m=min(m,dis1[i-1]+dis0[i]);
			else  m=min(m,dis1[i]+dis0[i+1]);
		}
		printf("%d\n",m);
		}

	}

	return 0;
}