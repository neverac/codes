#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;
typedef long long ll;
const int MAXN=1005;
int n,d;
int a[MAXN];
int main(){
    while (scanf("%d",&n) && n!=0){
        bool f=true;
        int count=0;
        scanf("%d",&d);
        for (int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }
        for (int i=2; i<=n-1; i++){
            if (abs(a[i]-a[i-1])>d) {
            if (abs(a[i+1]-a[i-1])<2*d && count==0){
                count++;
                i++;
            }
            else f=false;
            }
        }
        if (f) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}