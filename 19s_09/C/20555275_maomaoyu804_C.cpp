#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--){
        int ang;cin>>ang;
        int n=3;
        int flag=1;
        while(n<=998244353){
            if((ang*n)%180==0&&(n-2)*180>=ang*n)
                {cout<<n<<endl;flag=0;break;}
            n++;
        }
        if(flag) cout<<-1<<endl;
    }
    return 0;
}
