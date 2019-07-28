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
const int MAXN=301;
int n,num;
int v[MAXN][MAXN];
int x,y;
void intial(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            v[i][j]=0;
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        int ans=0;
        intial();
        for (int i=1; i<=n*(n-1)/2; i++){
            scanf("%d%d%d",&x,&y,&num);
            if (x>y) {
                int tmp=x;
                x=y;
                y=tmp;
            }
            v[x][y]=num;
        }
        for (int i=1; i<=n; i++){
            for (int j=i+1; j<=n; j++){
                for (int k=j+1; k<=n; k++){
                int sum=v[i][j]+v[i][k]+v[j][k];
                if (sum>ans) ans=sum;
                }
                }
            }
        printf("%d\n",ans);
    }
    return 0;
}