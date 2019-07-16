#include<iostream>
#include<math.h>
#include<iomanip>
#include <string>
#include <cstdio>
#include<stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;int stop;
int n;
int a,d,m;
int green,puper,black;

int main(){
	scanf("%d%d%d",&a,&d,&m);
	getchar();
	scanf("%d%d%d",&green,&puper,&black);
	if(green >= a){
		green -=a;
	}else{
		printf("NO\n");
		return 0;
	}
	if(green + puper >= d){
		if(green >=d){
			green-=d;
		}else{
			puper -=(d-green);
			green = 0;
		}
	}else{
		printf("NO\n");
		return 0;
	}
	if(puper + green + black >= m){
		printf("Yes\n");
	}else{
		printf("NO\n");
	}
  return 0;
}