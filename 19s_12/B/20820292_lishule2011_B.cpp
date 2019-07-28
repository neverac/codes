#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#define maxn 500100
using namespace std;
char s[maxn];
int main(){
	scanf("%s",s);
	int len = strlen(s);
	int i=0,j=len-1;
	while (i<j){
		if (s[i]!=s[j]) break;
		i++,j--;
	}
	if (i == j){
		while (s[i-1] == s[i]) i--;
		cout << i+1;
		return 0;
	}
	if (s[i+1] == s[j]) {
		while (s[i-1] == s[i]) i--;
		cout << i+1;
		return 0;
	}else{
		while (s[j-1] == s[j]) j --;
		cout << j+1;
		return 0;
	}
} 