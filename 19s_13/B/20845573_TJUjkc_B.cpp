#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int n;
int a[100005][2];

int main(){
    cin>>n;
    for(int i=1;i<=2*n;i++){
        int x;
        cin>>x;
        if(a[x][0]) a[x][1]=i;
        else{
            a[x][0]=i;
        }
        //cout<<a[x][0]<<" ## "<<a[x][1]<<endl;
    }
    //for(int i=1;i<=n;i++){
        //cout<<a[i][0]<<" # "<<a[i][1]<<endl;
    //}
    long long ans=0;
    a[0][1]=1;
    a[0][0]=1;
    for(int i=1;i<=n;i++){
        ans+=abs(a[i][0]-a[i-1][0]);
        //cout<<"@"<<ans<<endl;
        ans+=abs(a[i][1]-a[i-1][1]);
        //cout<<"@"<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
