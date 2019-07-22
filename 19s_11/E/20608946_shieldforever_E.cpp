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

#define N 100010
int a[N], b[N], c[N], t[N];
int n;
int main(){
	int i,j,k;
	cin>>n;
	for(i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		t[i] = a[i];
	}
	sort(t + 1, t + 1 + n);
	int flag = 1;
	int t1 = 0, t2 = 0;
	for(i = 1; i <= n; i++){
		if(a[i] != t[i]){
			b[++t1] = i;
		}
		if(a[i] != t[n - i + 1]){
			c[++t2] = i;
		}
	}
	//cout<<t1<<' '<<t2<<endl;
	if(t1 == 0 || t2 == 0){
		printf("Nothing to do here\n");
	}
	else{
		if(t1 > 2 && t2 > 2){
			printf("No hope\n");
		}
		else{
			printf("Yes\n");
			if(t1 <= 2) printf("%d %d\n", b[1], b[2]);
			else printf("%d %d\n", c[1], c[2]);
		}
	}
	return 0;
}
