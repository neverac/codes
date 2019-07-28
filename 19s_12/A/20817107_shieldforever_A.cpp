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
int t[10];
int main(){
	int p,q;
	cin>>p>>q;
	int i,j,k;
	p *= 10;
	for(i = 1; i <= 10000;i++){
		if(p == 0)break;
		t[p / q]++;
		p = (p % q) * 10;
	}
	for(i = 0; i < 10; i++){
		if(t[i] > 0)printf("%d", i);
	}
	return 0;
}
