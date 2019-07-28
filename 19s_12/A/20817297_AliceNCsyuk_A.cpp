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
int p,q;
int main(){
    int i,j,k,yu,xiao;
    scanf("%d%d",&p,&q);
    yu = p%q,xiao = p;
    while (!yushu[yu] && yu != 0)
    {
        yushu[yu] = 1;
        xiao*=10;
        yu = xiao%q;
        xiaoshu[xiao/q] = 1;
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