#include <bits/stdc++.h>
using namespace std;
int x,y,z,a,b,c;
bool work(){
	if(a<x)return 0;
	a-=x;
	if(a+b<y)return 0;
	if(a+b+c<y+z)return 0;
	return 1;
}
int main(){
	scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
	if(work())printf("YES\n");
	else printf("NO\n");
	return 0;
}