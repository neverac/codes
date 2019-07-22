#include <bits/stdc++.h>
using namespace std;
int city[100005];
int main(){
    int n;
    scanf("%d", &n);
    long long all = 0;
    for (size_t i = 0; i < (size_t)n; i++) {
        scanf("%d", &city[i]);
        all += city[i];
    }
    sort(city, city + n);
    long long ans = 0;
    for (size_t i = 0; i < (size_t)n; i++) {
        if((int)i != n - 1){
            ans += all * city[i] + (all - city[i]) * city[i];
            all -= city[i];
        }else{
            ans += all * city[i];
        }
    }
    printf("%lld\n", ans);
}