#include<iostream>

using namespace std;

int cnt1,cnt2,n;

int main(){
    cin>>n;
    cnt1=0;
    cnt2=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x>0) cnt1++;
        if(x<0) cnt2++;
    }
    if(cnt1>=(n+1)/2) cout<<1<<endl;
    else if(cnt2>=(n+1)/2) cout<<-1<<endl;
    else cout<<0<<endl;
    return 0;
}
