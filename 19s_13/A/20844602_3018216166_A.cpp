#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
using namespace std;
int n;
int a[maxn];
int main(){
    scanf("%d", &n);
    int len = (n + 1) / 2;
    int d = 0, x = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(a[i] > 0) d++;
        else if(a[i] < 0) x++;
    }
    if(d >= len){
        printf("1\n");
    }
    else if(x >= len){
        printf("-1\n");
    }
    else printf("0\n");
    return 0;
}
