#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
#define ll long long 
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}
const int maxn = 100010;
char s[maxn];
int num[30];
int main(){
	
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++) num[s[i]-'a']++;
	for(int i=0;i<26;i++){
		if(num[i]>n-num[i]+1){
			printf("INVALID\n");
			return 0;
		}
	}
	int now=n,last=-1;
	for(int i=0;i<n;i++){
		bool flag=0;
		for(int j=0;j<26;j++){
			if(j==last) continue;
			if(num[j]==now-num[j]+1){
				printf("%c",j+'a');
				num[j]--;now--,last=j;
				flag=1;
				break;
			}
		}
		//printf("%d %d\n",flag,last);
		if(flag) continue;
		for(int j=0;j<26;j++){
			if(j==last) continue;
			if(num[j]){
				printf("%c",j+'a');
				num[j]--,now--,last=j;
				break;
			}
		}
	}
	return 0;
}
  