#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;

int n;
int a[1005][1005];
int b[1005][1005];
int sumx[1005][1005];
int sumy[1005][1005];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    memset(b,0,sizeof(b));
    memset(sumx,0,sizeof(sumx));
    memset(sumy,0,sizeof(sumy));
    int ans=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1) b[i][j]=1;
            else if(i==1){
                if(a[i][j]==a[i][j-1]+1) b[i][j]=1;
            }
            else if(j==1){
                if(a[i][j]==a[i-1][j]+1) b[i][j]=1;
            }
            else{
                if(a[i][j]==a[i-1][j]+1||a[i][j]==a[i][j-1]+1) b[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==1) sumx[i][j]=1;
            else{
                sumx[i][j]=sumx[i][j-1]+b[i][j];
            }
            if(i==1) sumy[i][j]=1;
            else{
                sumy[i][j]=sumy[i-1][j]+b[i][j];
            }
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }*/
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<sumx[i][j]<<" ";
        }
        cout<<endl;
    }*/
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<sumy[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int k;
            for(k=1;k<min(n-i,n-j);k++){
                if(sumy[i+k][j+k]-sumy[i-1][j+k]!=k+1||sumx[i+k][j+k]-sumx[i+k][j-1]!=k+1) break;
            }
            ans=max(ans,k);
        }
    }
    cout<<ans<<endl;
    return 0;
}
