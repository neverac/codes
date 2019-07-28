#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,coufu,couzh,couz,a[105];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0)couz++;
		else if(a[i]>0)couzh++;
		else coufu++;
	}
	int z=ceil(n*1.0/2);
	if(couzh>=z)printf("1\n");
	else if(coufu>=z)printf("-1\n");
	else printf("0\n");
	return 0;

}