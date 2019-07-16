#include<iostream>

using namespace std;

int a,b,c,x,y,z;

int main(){
    cin>>x>>y>>z>>a>>b>>c;
    int ok=1;
    a=a-x;
    if(a<0) ok=0;
    if(a+b<y) ok=0;
    if(a+b+c<y+z) ok=0;
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
