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
const int N=100;
int t,n,k,d;

string map[310][310];
bool vis[310][310];

string jiafa(string a,string b){
    string c(N,'0');
    int wei[N] = {0};
    for(int i=0;i<N;i++){
        wei[i]+=a[i]-'0';
    }

    for(int i=0;i<N;i++){
        wei[i]+=b[i]-'0';
        if(wei[i] >= d){
            wei[i+1]+=wei[i]/d;
            wei[i]%=d;
        }
    }
    for(int i=0;i<N;i++){
        c[i] = wei[i] + '0';
    }
    return c;
}

string opera(int n,int k){
    if(vis[n][k]){
        return map[n][k];
    }else{
        string c(N,'0');
        if(k == 0 || k == n){
            c[0] = '1';
            map[n][k] = c;
            vis[n][k] = 1;
            return c;
        }
        if(k == 1){
            int i=0;
            while (n>0)
            {
                c[i] = n%d + '0';
                i++;
                n/=d;
            }
            map[n][k] = c;
            vis[n][k] = 1;
            return c;
            
        }
        c = jiafa(opera(n-1,k-1),opera(n-1,k));
        map[n][k] = c;
        vis[n][k] = 1;
        return c;
    }

}

int main(){
    int i,j;
    scanf("%d",&t);
    while (t--){
        scanf("%d%d%d",&n,&k,&d);
        memset(vis,0,sizeof(vis));
        string a = opera(n,k);
        int p = -1;
        for(i=0;i<N;i++){
            if(a[i] != '0'){
                p = i;
            }
        }
        for(i=p;i>=0;i--){
            printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}