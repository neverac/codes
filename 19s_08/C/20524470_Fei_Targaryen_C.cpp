#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k,a,b;
    cin>>k>>a>>b;
    if(a+2>=b) cout<<k+1<<endl;
    else
    {
        long long sum=1;
        while(k>0)
        {
            if(sum>=a&&k>1)
            {
                sum+=b-a;
                k-=2;
            }
            else
            {
                sum++;
                k--;
            }
        }
        cout<<sum<<endl;
    }

}
