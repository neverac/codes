#include<iostream>
#include<math.h>
#include<iomanip>
#include <string>
#include <cstdio>
#include<stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
#define M 998244353
using namespace std;int stop;
ll n,m;
char arr[200010];

ll kuaisumi(ll k){
  ll ans = 1;
  ll a = 2;
  while(k>0){
    if(k&1){
      ans*=a;
      ans%=M;
    }
    a*=a;
    k/=2;
  }
  ans-=1;
  if(ans>=0){
    return ans;
  }else{
    return M-1;
  }
}

int main(){
    ll i,j;
    char ch;
    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++){
      scanf("%c",&arr[i]);
    }
    ll qian = 1,hou = n;
    for(i=2;i<=n;i++){
      if(arr[i] == arr[1]){
        qian = i;
      }else{
        break;
      }
    }

    for(i=n-1;i>=1;i--){
      if(arr[i] == arr[n]){
        hou = i;
      }else{
        break;
      }
    }
    ll ans = 0;
    if(qian <= hou){
      if(arr[1] != arr[n]){
        ans += n-hou+2;ans+=qian+1;ans-=1;ans%=M;
      }else{
          ll x = n-hou+2,y = qian-1+2;
          ans += x*y;ans%=M;
      }
    }
    printf("%lld",ans);
    return 0;
}