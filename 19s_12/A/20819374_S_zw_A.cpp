#include<iostream>
#include<math.h>
#include<iomanip>
#include <string>
#include <cstdio>
#include<stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
#define N 1000010
using namespace std;int stop;
bool xiaoshu[11];
bool yushu[N];
int r,t;
int main(){
    int i,j,k,yu,xiao;
    scanf("%d%d",&r,&t);
    yu = r%t,xiao = r;
    while (!yushu[yu] && yu != 0)
    {
        yushu[yu] = 1;
        xiao*=10;
        yu = xiao%t;
        xiaoshu[xiao/t] = 1;
        xiao = yu;
    }
    for(i=0;i<=9;i++){
        if(xiaoshu[i]){
            printf("%d",i);
        }
    }
    printf("\n");
    return 0;
}