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
ll a,b;
ll k;

int main(){
    ll i,j;
    scanf("%lld %lld %lld",&k,&a,&b);
    ll get1 = 1,k1 = k;
    if(k1>=a-1+2 && b>a){
      k1-=(a-1);get1 = a;
      ll remain = k1>>1;
      get1 += remain * (b-a);
      get1+=k1&1;
      printf("%lld",max(get1,1+k));
    }else{
      printf("%lld\n",1+k);
      return 0;
    }
    return 0;
}