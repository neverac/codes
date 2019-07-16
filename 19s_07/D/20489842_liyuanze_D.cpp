#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;scanf("%d",&t);
    while(t--) {
        char in[1005]; scanf("%s",in);
        int len=strlen(in);
        int one=0,zero=0;
        for(int i=0;i<len;i++) {
            if(in[i]=='1') one++;
        }
        if(one==len) {
            puts("0");
            continue;
        }
        int Min=0x3f3f3f3f;
        for(int i=len-1;i>=0;i--) {
            if(in[i]=='0') {
                Min=min(Min,one+zero);
                zero++;
            }
            else {
                one--;
            }
        }
        Min=min(zero,Min);
        printf("%d\n",Min);
    }
}
