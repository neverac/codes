#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;

char s[100010];
int main(){
	int T; cin>>T;
	while (T--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		bool flag=1;
		int t=0;
		for (int i=1; i<=n; i++){
			if (s[i]=='?'){
				if (i==1){
					s[i]='1';
					t = min(1,t*10+s[i]-'0');
					continue;
				}
				if (s[i-1]=='0'){
					if (t>0){
						s[i]='1';
						t = min(1,t*10+s[i]-'0');
					} else {
						s[i]='+';
						t = 0;
						if (i==n){
							flag=0;
							break;
						}
					}
				} else if (s[i-1]=='+' || s[i-1]=='*'){
					s[i]='1';
					t = min(1,t*10+s[i]-'0');
				} else if (s[i-1]>='1' && s[i-1]<='9'){
					s[i]='1';
					t = min(1,t*10+s[i]-'0');
				}
			} else if (s[i]=='0'){
				t = min(1,t*10+s[i]-'0');                               
				if (s[i-1]=='*' || s[i-1]=='+' || i==1){
					if (s[i+1]>='1' && s[i+1]<='9') {
						flag = 0;
						break;
					}
				}
				if (t==0 && s[i-1]=='0'){
					flag=0;
					break;
				}
			} else if (s[i]>='1' && s[i]<='9'){
				t = min(1,t*10+s[i]-'0');
				continue;
			} else if (s[i]=='+' || s[i]=='*'){
				t = 0;
				if (s[i-1]=='+' || s[i-1]=='*' || s[i+1]=='+' || s[i+1]=='*' || i==1 || i==n){
					flag=0;
					break;
				}
			}
		}
		if (flag){
			for (int i=1; i<=n; i++) printf("%c",s[i]); puts("");
		} else {
			puts("IMPOSSIBLE");
		}
	}
	return 0;
}