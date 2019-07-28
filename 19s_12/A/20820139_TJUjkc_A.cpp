#include<iostream>

using namespace std;

long long p,q;
int cnt=0;
int ans[10];

int main(){
    cin>>p>>q;
    int t=1000;
    while(t--)
    {
        if(p==0) break;
        p=p*10;
        int a=p/q;
        //cout<<p<<q<<p%q<<endl;
        p=p%q;

        ans[a]=1;
        //cout<<p<<" "<<a<<endl;
    }
    for(int i=0;i<10;i++){
        if(ans[i]>0) cout<<i;
    }
    cout<<endl;
    return 0;
}
