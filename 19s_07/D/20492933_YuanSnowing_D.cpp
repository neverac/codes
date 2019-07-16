#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,cnt,s1[1050],s0[1050],l;
string s;
int main(){
	cin >> T;
	while(T --){
		cin >> s;
		l = s.length();
		cnt = 1050;
		memset(s1,0,sizeof s1);
		memset(s0,0,sizeof s0);
		if(s[0]=='1') s1[0] = 1;
		else s0[0] = 1;
		for(int i = 0;i < l;i ++){
			if(s[i] == '0'){
				s1[i] = s1[i-1];
				s0[i] = s0[i-1]+1;
			} 
			if(s[i] == '1'){
				s1[i] = s1[i-1] + 1;
				s0[i] = s0[i-1];
			}
		}
		for(int i = 0;i < l; i ++){
			cnt = min(cnt,s1[i-1]+s0[l-1]-s0[i]);
		}
		printf("%d\n",cnt);
	}
    return 0;
}