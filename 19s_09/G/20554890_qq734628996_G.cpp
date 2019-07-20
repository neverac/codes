#include <bits/stdc++.h>
using namespace std;


int main()
{

    int T; cin>>T;
    while (T--) {
        unsigned long long n; cin>>n;
        cout<<n*(n+2)*(2*n+1)/8<<endl;
    }

    return 0;
}

