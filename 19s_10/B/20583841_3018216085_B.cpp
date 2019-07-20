#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,t,x,y;

int cnt1[4],cnt2[4];
int main(){
    string a,b;
    cin>>n>>m>>t;
    cin>>x>>y;
    cin>>a>>b;
    bool yes=true;
    for(int i=0;i<t;i++){
        if(a[i]=='R'){//出的
            cnt1[0]++;
        }else if(a[i]=='L'){
            cnt1[1]++;
        }else if(a[i]=='U'){
            cnt1[2]++;
        }else{
            cnt1[3]++;
        }
        if(y+cnt1[0]>m||y-cnt1[1]<1||x-cnt1[2]<1||x+cnt1[3]>n)yes=false;
        if(b[i]=='R'){//不出的
            cnt2[0]++;
        }else if(b[i]=='L'){
            cnt2[1]++;
        }else if(b[i]=='U'){
            cnt2[2]++;
        }else{
            cnt2[3]++;
        }
        if(a[i]!=b[i]){
        cnt2[0]=min(cnt2[0],m-y);
        cnt2[1]=min(cnt2[1],y-1);
        cnt2[2]=min(cnt2[2],x-1);
        cnt2[3]=min(cnt2[3],n-x);
        }
        if(cnt2[0]>cnt1[1])cnt2[0]-=cnt1[1],cnt1[1]=0;
        else cnt1[1]-=cnt2[0],cnt2[0]=0;
        if(cnt2[1]>cnt1[0])cnt2[1]-=cnt1[0],cnt1[0]=0;
        else cnt1[0]-=cnt2[1],cnt2[1]=0;
        if(cnt2[2]>cnt1[3])cnt2[2]-=cnt1[3],cnt1[3]=0;
        else cnt1[3]-=cnt2[2],cnt2[2]=0;
        if(cnt2[3]>cnt1[2])cnt2[3]-=cnt1[2],cnt1[2]=0;
        else cnt1[2]-=cnt2[3],cnt2[3]=0;
        if(a[i]==b[i]){
            cnt2[0]=min(cnt2[0],m-y);
        cnt2[1]=min(cnt2[1],y-1);
        cnt2[2]=min(cnt2[2],x-1);
        cnt2[3]=min(cnt2[3],n-x);
        }
    }
    if(yes)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
