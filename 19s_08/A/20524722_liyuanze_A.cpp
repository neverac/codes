#include<bits/stdc++.h>
using namespace std;
int in[500005];
int st[6]={4,8,15,16,23,42};
int use[500005];
int d[6];
int mod[6];
int main() {
    int n; scanf("%d",&n);
    memset(d,0,sizeof(d));
    for(int i=0;i<n;i++) {
        scanf("%d",in+i);
        int temp=-1;
        for(int j=0;j<6;j++) {
            if(in[i]==st[j]) {
                temp=j;
            }
        }
        if(temp==-1) continue;
        if(temp==0) {d[0]++;}
        else {
            if(d[temp-1]!=0) {
                d[temp-1]--;
                d[temp]++;
            }
        }
    }
    printf("%d",n-d[5]*6);
}
