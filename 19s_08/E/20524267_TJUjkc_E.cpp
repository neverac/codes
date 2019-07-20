#include<iostream>
#include<memory.h>
#include<algorithm>
#include<cmath>
using namespace std;

int ans;
int cnt[3];
int a;
int t;
int n;

int main(){
    cin>>t;
    while(t--){
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            cnt[a%3]++;
        }
        ans=0;
        ans+=cnt[0];
        int num=min(cnt[1],cnt[2]);
        ans+=num;
        cnt[1]-=num;
        cnt[2]-=num;
        ans+=(cnt[1]/3)+(cnt[2]/3);
        cout<<ans<<endl;
    }
    return 0;
}
