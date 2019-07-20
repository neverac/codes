#include <bits/stdc++.h>
using namespace std;
int main(){
    long long k, a, b;
    scanf("%lld %lld %lld", &k, &a, &b);
    long long bis = 1;
    for (int i = 0; i < k; i++) {
        if(b - a > 2){
            if(bis >= a && k - i >= 2){
                bis += (b - a);
                i++;
            }else bis++;
        }else{
            bis++;
        }
    }
    printf("%lld\n", bis);
}