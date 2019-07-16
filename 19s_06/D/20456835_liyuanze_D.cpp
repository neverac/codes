#include<bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,d,e,f;scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    if(d<a){
        puts("NO");
        return 0;
    }
    d-=a;
    if(d+e<b) {
        puts("NO");
        return 0;
    }
    if(d+e+f<b+c) {
        puts("NO");
        return 0;
    }
    puts("YES");
}
