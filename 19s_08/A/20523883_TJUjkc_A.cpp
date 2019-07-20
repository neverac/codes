#include<iostream>
#include<map>
#include<algorithm>
#include<cmath>
#include<memory.h>
using namespace std;

int n;
int a[500005];
int ans;
map<int,int> map_;
int cnt[7];

int main(){
    memset(cnt,0,sizeof(cnt));
    cnt[0]=500005;
    map_[4]=1;
    map_[8]=2;
    map_[15]=3;
    map_[16]=4;
    map_[23]=5;
    map_[42]=6;
    ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(cnt[map_[a[i]]]<cnt[map_[a[i]]-1]){
            cnt[map_[a[i]]]++;
        }
        else{
            ans++;
        }
    }
    for(int i=1;i<=6;i++){
        ans+=cnt[i]-cnt[6];
    }
    cout<<ans<<endl;
    return 0;
}
