#include <stdio.h>
using namespace std;
int main()
{
    int t ;scanf("%d",&t);
    while(t--){
        long long n;scanf("%lld",&n);
        long long sum1=(n*(n+1)*(2*n+1)/6+n*(n+1)/2)/2;
        long long sum2;
        if(n%2==0){
            long long k=n/2;
            sum2=k*(k+1)*(2*k+1)/3-k*(k+1)/2;
        }
        else{
            long long k=n/2;
            sum2=k*(k+1)*(2*k+1)/3-k*(k+1)/2;
            sum2+=k*(k+1);
        }
        printf("%lld\n",sum1+sum2);
    }
}
