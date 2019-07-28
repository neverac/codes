#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <algorithm>

const int maxn = 1100000 ;
int prime[90000] ;
int c ;
bool number[maxn+5];
void isprime()
{
    int i,j;
    c=0;
    memset(number,true,sizeof(number));
    for(i=2;i<=maxn;i++)
    {
        if(number[i])
            prime[c++]=i;
        for(j=0;j<c&&prime[j]*i<=maxn;j++)
        {
            number[prime[j]*i]=false;
            if(i%prime[j]==0)
                break;
        }
    }
}
int bala1[10] ;
int bala2[10] ;
using namespace std;
int main()
{
    isprime() ;
    int t ;
    cin >> t ;
    while(t--){
        long long m ;
        cin >> m ;
        long long temp = m ;
        int q = -1 ;
        memset(bala1,0,sizeof(bala1)) ;
        memset(bala2,0,sizeof(bala2)) ;
        for(int i = 0 ; i < c ; i++) {
            if (temp==1) break ;
            if(temp%prime[i]==0) {
                bala1[++q] = prime[i] ;
                while(temp%prime[i]==0) {
                    temp/= prime[i] ;
                    bala2[q] ++ ;
                }
            }
        }
        if (temp!=1) {
            bala1[++q] = temp ;
            bala2[q] = 1 ;
        }
        long long ans = 0;
        long long cnts = 1;
        for (int i = 0 ; i <= q ; i++ ){
            ans = ans * (bala2[i] + 1) + cnts * bala2[i];
            cnts *= bala2[i] + 1;
        }
        cout << ans << endl;
    }
    return 0;
}