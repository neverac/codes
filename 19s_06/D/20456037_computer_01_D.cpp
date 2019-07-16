#include<iostream>

using namespace std;

int x, y, z;
int a, b, c;

int main()
{
    cin>>x>>y>>z;
    cin>>a>>b>>c;

    if(a < x)
    {
        cout<<"NO"<<endl;
    }

    else
    {
        if(a - x + b < y)
            cout<<"NO"<<endl;

        else
        {
            if(a + b + c - x - y < z)
                cout<<"NO"<<endl;

            else
                cout<<"YES"<<endl;
        }
    }

    return 0;
}
