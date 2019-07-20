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
	int T;
	cin>>T;
	while(T--){
		int ang;
		cin>>ang;
		int a = ang, b = 180;
		for(int i = 2; i <= a; i++){
			while(a % i == 0 && b % i == 0){
				a /= i;
				b /= i;
			}
		}
		if(b - a == 1){
			b *= 2;
			a *= 2;
		}
		printf("%d\n", b);
	}
	return 0;
}
