#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    int l,r;

    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        if(l*2<=r) cout<<l<<" "<<2*l<<endl;
    }
    return 0;
}
