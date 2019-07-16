#include <iostream>

using namespace std;

int main()
{
    int x,y,z,a,b,c;
    cin>>x>>y>>z;
    cin>>a>>b>>c;
    if(x>a||y>a+b-x||z>a+b+c-x-y) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
