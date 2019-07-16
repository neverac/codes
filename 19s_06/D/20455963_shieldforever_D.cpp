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

int main(){
	int x,y,z,a,b,c;
	cin>>x>>y>>z;
	cin>>a>>b>>c;
	if(a<x){
		printf("NO\n"); return 0;
	}
	a-=x;
	if(a+b<y){
		printf("NO\n"); return 0;
	}
	if(a+b+c-y<z){
		printf("NO\n"); return 0;
	}
	printf("YES\n");

	return 0;
}
