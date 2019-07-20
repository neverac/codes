#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; scanf("%d",&t);
    while(t--) {
        int fish[3];
        int in[100];
        int n;scanf("%d",&n);
        memset(fish,0,sizeof(fish));
        for(int i=0;i<n;i++) {
            scanf("%d",in+i);
            fish[in[i]%3]++;
        }
        int ans=0;
        ans+=fish[0];
        if(fish[1]>=fish[2]) {
            ans+=fish[2];
            ans+=(fish[1]-fish[2])/3;
        }
        else {
            ans+=fish[1];
            ans+=(fish[2]-fish[1])/3;
        }
        printf("%d\n",ans);
    }
}
