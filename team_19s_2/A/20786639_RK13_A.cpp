#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <algorithm>

using namespace std;
int arr[1005] ;
int no[1005] ;
int main()
{
    int n ;
    while (scanf("%d",&n)) {
        if (n==0) break ;
        int d ;
        scanf("%d",&d) ;
        memset(no,0,sizeof(no)) ;
        int flog = 1 ;
        int s = 0 ;
        for (int i = 1 ; i<= n ; i++) {
            scanf("%d",&arr[i]) ;
        }
        for (int i = 2 ; i<= n ; i++) {
            if (s==1) {
                if (no[0]+1==i) {
                    int temp = abs(arr[i]-arr[i-2]) ;
                    if (temp>2*d) {
                        printf("N\n") ;
                        flog = 0 ;
                        break ;
                    }
                }
                else{
                    int temp = abs(arr[i]-arr[i-1]) ;
                    if (temp>d) {
                        printf("N\n") ;
                        flog = 0 ;
                        break ;
                    }
                }
            }
            else {
                int temp = abs(arr[i]-arr[i-1]) ;
                if (temp>d) no[s++] = i ;
            }
        }
        if (flog) printf("Y\n") ;
    }
    return 0;
}
