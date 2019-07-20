#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; scanf("%d",&t);
    while(t--) {
        int ang; scanf("%d",&ang);
        if(ang==180) {
            puts("-1");
            continue;
        }
        if(ang==179) {
            puts("360");
            continue;
        }
        int ans=-1;
        for(int i=3;i<=180;i++) {
            if(ang*i%180==0&&ang<=(180-(360/i))) {
                ans=i;
                break;
            }
        }
        printf("%d\n",ans);
    }
}
