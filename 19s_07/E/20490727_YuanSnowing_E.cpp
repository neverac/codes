#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool fl ;
int a[30];
char s[100200];
int ans[100200];
int main(){
	scanf("%s",s);
	int l = strlen(s),sum=strlen(s);
	for(int i = 0;i < l;i ++){
		a[s[i]-'a'] ++;
	}
	int k = 0,j;
	ans[k] = -1;
	for(int i = 0;i < l;i ++){
		fl = false;
		for(j = 0;j < 26;j ++){
			if(a[j]*2 > sum && j != ans[k]){
				ans[++k] = j;
				a[j] --;
				sum --;
				fl = true;
				break;
			}
		}
		if(j == 26){
			for(int j = 0;j < 26;j ++){
				if(a[j] != 0 && j!=ans[k]){
					ans[++k] = j;
					a[j] --;
					sum --;
					fl = true;
					break;
				}
			}
		}
		if(!fl){
			cout <<"INVALID"<<endl;
			return 0;
		}
	}
	for(int i = 1;i <=l;i ++){
		printf("%c",(char)('a'+ans[i]));
	}
    return 0;
}
