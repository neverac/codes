#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void work(){
	int ang;
	scanf("%d",&ang);
	if(ang == 179){
		printf("%d\n",360);
		return;
	}
	else if(ang == 180)printf("-1\n");
	else{
		for(int i = 3;i <= 180;i++){
			double now = 1.*180/i;
			for(int j = 1;j <= i-2;j++){
				if(now * j == 1.*ang){
					printf("%d\n",i);
					return;
				}
			}
		}
		printf("-1\n");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}