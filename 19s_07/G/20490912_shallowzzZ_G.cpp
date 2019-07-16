#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn  = 1e3+5;

int n;
ll a[maxn][maxn];
bool check(int x){
    for(int i=1;i<=n-x+1;i++){
        for(int j=1;j<=n-x+1;j++){
            int ii=i; bool flag=true;
            for(ii;ii<i+x && flag;ii++){
                for(int kk=1;kk<x && flag;kk++){
                    if(a[ii][j+kk]!=a[ii][j+kk-1]+1){
                        flag=false;
                        break;
                    }
                }
            }
            if(!flag) continue;
            for(int kkk=1;kkk<x;kkk++){
                if(a[i+kkk][j]!=a[i+kkk-1][j]+1){
                    flag=false;
                    break;
                }
            }
            if(flag) return true;
        }
    }
    return false;
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    int r=n,l=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    cout << r << endl;
}
