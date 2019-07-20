#include<iostream>
#include<math.h>
#include<iomanip>
#include <string>
#include <cstdio>
#include<stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;int stop;
#define N 200010
#define ll long long
int ang,t;

int gcd(int x,int y){
    if(x>y){swap(x,y);}
    if(y%x == 0){
        return x;
    }
    return gcd(y%x,x);
}

int main(){
    scanf("%d",&t);
    for(int j = 1;j<=t;j++){
        scanf("%d",&ang);
        if(ang == 180){
            printf("-1\n");
            continue;
        }
        if(ang == 90){
            printf("4\n");
            continue;
        }
        if(ang > 90){
            ang = 180 - ang;
            int x = gcd(ang,180);
            if(x == ang){
                printf("%d\n",180*2/x);
            }else{
                printf("%d\n",180/x);
            }
        }else{
            int x = gcd(ang,180);
            printf("%d\n",180/x);
        }
    }

    return 0;
}