#include <bits/stdc++.h>
#define maxn 500010
using namespace std;

int main(){
	char s[maxn];
	scanf("%s", s);
	int len = strlen(s);
	int l = 0, r = len - 1;
	int sz = 250;
	for(; s[l] == s[r] && l < r; l++, r--);
	bool f;
	for(int k = max(0, l - sz); k <= min(len - 1, l + sz); k++){
		f = true;
		for(int i = 0, j = len - 1; i < j; i++, j--){
			if(i == k) i++;
			else if(j == k) j--;
			if(s[i] != s[j]){
				f = false;
				break;
			}
		}
		if(f) {
			printf("%d\n", k + 1);
			return 0;
		}
	}
	for(int k = max(0, r - sz); k <= min(len - 1, r + sz); k++){
		f = true;
		for(int i = 0, j = len - 1; i < j; i++, j--){
			if(j == k) j--;
			else if(i == k) i++;
			if(s[i] != s[j]){
				f = false;
				break;
			}
		}
		if(f) {
			printf("%d\n", k + 1);
			return 0;
		}
	}
	return 0;
}
