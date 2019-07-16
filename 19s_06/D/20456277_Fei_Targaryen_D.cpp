#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    int g,p,b;
    cin>>g>>p>>b;
    if(x>g) cout<<"NO"<<endl;
    else
    {
        g-=x;
        if(y>g+p) cout<<"NO"<<endl;
        else
        {
            int tot=b+p+g-y;
            if(tot<z) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}
