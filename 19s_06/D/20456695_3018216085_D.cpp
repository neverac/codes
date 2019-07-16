#include<bits/stdc++.h>
#define  MAX 100005
#define  MOD 1000000007
#define ll long long
using namespace std;

int main(){
    int x,y,z;
    cin>>x>>y>>z;
    int g,p,b;
    bool check=true;
    cin>>g>>p>>b;
    g-=x;
    if(g<0)check=false;
    int t=g+p;
    t-=y;
    if(t<0)check=false;
    int m=t+b;
    m-=z;
    if(m<0)check=false;
    if(check)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
