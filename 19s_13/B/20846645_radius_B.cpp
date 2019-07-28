#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 2e5+5 ;
struct node {
    int s , l ;
} ;
node arr[maxn] ;
bool cmp (node a , node b ){
    return a.s < b.s ;
}
int main()
{
    int n ;
    cin >> n ;
    for (int i = 0 ; i <2*n;i++){
        cin >> arr[i].s ;
        arr[i].l = i+1;
    } 
    long long ans = 0 ;
    int now1 = 1 ; 
    int now2 = 1 ;
    sort (arr,arr+n*2,cmp) ;
    for (int i = 0 ; i<2*n ; i+=2) {
        int temp1 = arr[i].l ;
        int temp2 = arr[i+1].l ;
        int a1 = abs(now1-temp1) ;
        int a2 = abs(now2-temp2) ;
        int sum1 = a1 + a2 ;
        int b1 = abs(now2-temp1) ;
        int b2 = abs(now1-temp2) ;
        int sum2 = b1 + b2 ;
        if (sum1<sum2){
            ans += sum1 ;
            now1 = temp1 ;
            now2 = temp2 ;
        } 
        else {
            ans += sum2 ;            
            now1 = temp2 ;
            now2 = temp1 ;
        }
    }
    cout << ans << endl ;
    return 0 ;
}