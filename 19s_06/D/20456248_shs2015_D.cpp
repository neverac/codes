#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	int x,y,z,a,b,c;
	scanf("%d%d%d",&x,&y,&z);
	scanf("%d%d%d",&a,&b,&c);
	if(a < x){
		printf("NO");
		return 0;
	}
	a -= x;
	if(a + b < y){
		printf("NO");
		return 0;
	}
	a -= y;
	if(a + b + c < z){
		printf("NO");
		return 0;
	}
	printf("YES");
	return 0;
}