#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<queue>

using namespace std;
#define N 500050
char s[N];
int k1,k2,k3,k4, n; 

bool check(int l, int r){
	int i,j,k;
	for(i = l; i <= r; i++){
		if(s[i] != s[r - (i - l)])return false;
	}
	return true;
}

void solve1(){
	int flag,i,j,k = n * 2;
	
	flag = 0;
	int mid = n / 2;
	i = mid - 1, j = mid + 1;
	while(i >= 1){
		if(s[i] != s[j]){
			flag = 1;
			int p = j;
			j++;
			while(i >= 1){
				if(s[i] != s[j]) break;
				i--; j++;
			}
			if(i == 0) k = min(k, p);
			break;
		}
		i--; j++;
	}
	if(!flag) k = min(k, n);
	
	flag = 0;
	mid = n / 2 + 1;
	i = mid - 1; j = mid + 1;
	while(j <= n){
		if(s[i] != s[j]){
			flag = 1;
			int p = i;
			i--;
			while(i >= 1){
				if(s[i] != s[j]) break;
				i--; j++;
			}
			if(i == 0) k = min(k, p);
			break;
		}
		i--; j++;		
	}
	if(!flag) k = min(k, 1);
	
	printf("%d\n", k);
}
void solve2(){
	int i,j,k = n * 2;
	
	if(check(1, n)){
		k = min(k, n / 2 + 1);
	}
	
	int mid1 = n / 2, mid2 = n / 2 + 1;
	if(s[mid1] == s[mid2]){
		int flag = 0;
		i = mid1; j = mid2;
		while(i >= 1){
			if(s[i] != s[j]){
				flag = 1;
				int p = j;
				j++;
				while(i >= 1){
					if(s[i] != s[j]) break;
					i--; j++;
				}
				if(i == 0) k = min(k, p);
				break;
			}
			i--;j++;
		}
		if(!flag) k = min(k, n);
	}
	
	mid1 = n / 2 + 1; mid2 = n / 2 + 2;
	if(s[mid1] == s[mid2]){
		int flag = 0;
		i = mid1; j = mid2;
		while(j <= n){
			if(s[i] != s[j]){
				flag = 1;
				int p = i;
				i--;
				while(i >= 1){
					if(s[i] != s[j]) break;
					i--; j++;
				}
				if(i == 0) k = min(k, p);
				break;
			}
			i--;j++;
		}
		if(!flag) k = min(k, 1);
	}
	printf("%d\n", k);	
	return ;
}

int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	if(n % 2 == 0){
		solve1();
	}
	else{
		solve2();
	}
	return 0;
}
