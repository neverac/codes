#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <cmath>
#include<stdio.h>
#include <map>
//#define lowbit(i) (i&(-i))
//#define  ll long long
using namespace std;
struct node{
    long long num;
    long long cnt;
}factor[1000];
long long cnt = 0;
long long calculate(long long n,long long p){
    long long ans = 0;
    while(n){
        ans += (n / p);
        n /= p;
    }
    return ans;
}
long long pp[1000];
int main(){
    long long n;
    long long b;
    cin >> n >> b;
    for(int i = 2;i <= sqrt(1.0*b);i++){
        if(b % i == 0){
            factor[cnt].num = i;
            factor[cnt].cnt = 0;
            while(b % i == 0){
                factor[cnt].cnt++;
                b /= i;
            }
            cnt++;
        }
    }
    if(b > 1){
        factor[cnt].num = b;
        factor[cnt++].cnt = 1;
    }
    long long ans = 1000000000000000001;
    //cout << cnt << endl;
    for(int i = 0;i < cnt;i++){
        pp[i] = calculate(n,factor[i].num);
        if(pp[i] == 0){
            ans = 0;
            break;
        }
        else{
            long long temp = pp[i] / factor[i].cnt;
            ans = min(ans,temp);
        }
    }
    cout << ans << endl;
    return 0;
}