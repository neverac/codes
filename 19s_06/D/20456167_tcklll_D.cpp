#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#define sf(n) scanf("%d",&n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define ll long long
#define MAXL 1000000
#define eps 1e-6
#define MAXV 10005
#define INF 1000000005
#define mod 1000000007
using namespace std;
int main(){
    int x,y,z,a,b,c;scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
    if(x<=a){
        a-=x;
        if(y<=a+b&&z<=a+b+c-y){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}
/*
1000000000000000000 1000000000000
*/
