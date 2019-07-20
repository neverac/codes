#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int l, r;
        scanf("%d %d", &l, &r);
        if(l == 1){
            printf("%d %d\n", 1, 2);
            continue;
        }else{
            printf("%d %d\n", l, 2*l);
            continue;
        }

    }

}