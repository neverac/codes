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
ll P,Q,k;
int tong[10];
int main(){
    scanf("%d%d",&P,&Q);
    for (int i=1; i<=Q; i++){
        if (P ==0) break;
        P*=10;
        k=P/Q;
        tong[k]=1;
        P=P%Q;
    }
    for (int i=0; i<=9; i++){
        if (tong[i]==1) printf("%d",i);
    }
    printf("\n");
    return 0;
}