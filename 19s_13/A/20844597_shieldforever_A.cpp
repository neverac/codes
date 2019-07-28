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

#define N 110
int a[N], n; 

int main(){
	int i,j,k;
	cin>>n;
	
	int t1 = 0, t2 = 0;
	for(i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] > 0) t1++;
		if(a[i] < 0) t2++;
	}
	if(n % 2 == 1) n = n / 2 + 1;
	else n = n / 2;
	if(t1 < n && t2 < n){
		printf("0\n");
	}
	else {
		if(t1 >= n) printf("1\n");
		else printf("-1\n");
	}
	return 0;
}
