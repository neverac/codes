#include<bits/stdc++.h>
#define  MAX 100005
#define  MOD 1000000007
#define ll long long
using namespace std;

int gra[1005][1005];
bool vis[1005][1005];
int n;
bool check(int x,int y,int k){
    if(x>n||y>n)return false;
    for(int i=1;i<=k;i++){
        if(gra[x][y-i]+1!=gra[x][y-i+1]){
            return false;
        }
    }
    for(int i=1;i<=k;i++){
        if(gra[x-i][y]+1!=gra[x-i+1][y]){
            return false;
        }
    }
    return true;
}
int main(){

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        scanf("%d",&gra[i][j]);
        }
    }
    int ma=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i][j])continue;
            int cnt=1;
            int k=1;
            for(;k<=n;k++){
                if(check(i+k,j+k,k))cnt++;
                else break;
            }
            for(int x=i;x<=i+k-1;x++){
                for(int y=j;y<=j+k-1;y++)
                    vis[x][y]=true;
            }
            ma=max(ma,cnt);
        }
    }
    cout<<ma<<endl;
}
