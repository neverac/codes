#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, y, z;
    int a, b, c;
    scanf("%d %d %d", &x, &y, &z);
    scanf("%d %d %d", &a, &b, &c);
    if(a >= x && a - x + b >= y && x + y + z <= a + b + c)
        printf("YES\n");
    else printf("NO\n");

}