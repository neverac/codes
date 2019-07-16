#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int x,y,z;
    cin>>x>>y>>z;
    int sum=x;
    int flag=1;
    if(sum-a>=0) sum-=a;
    else flag=0;
    sum+=y;
    //cout<<sum<<endl;
    if(sum-b>=0) sum=sum+z-b;
    else flag=0;
    //cout<<sum<<endl;
    if(sum-c<0) flag=0;
    if(flag) cout<<"YES";
    else cout<<"NO";
    return 0;
}
