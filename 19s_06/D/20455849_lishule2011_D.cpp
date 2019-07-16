#include <iostream>
using namespace std;

int main(){
	int x,y,z,a,b,c;
	cin >> x >> y >> z>> a >> b >> c;
	if (a<x){
		puts("NO");
		return  0;
	}
	if (a-x+b<y){
		puts("NO");
		return  0;
	}
	if (a-x+b-y+c<z){
		puts("NO");
		return  0;
	}
	puts("YES");	
}