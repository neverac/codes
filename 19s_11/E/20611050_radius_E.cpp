#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    int x , l;
};
bool cmp1(node a , node b){
    if (a.x!=b.x) return a.x < b.x ;
    else return a.l < b.l ;
}
bool cmp2(node a , node b){
    if (a.x!=b.x) return a.x > b.x ;
    else return a.l < b.l ;
}
const int maxn = 1e5+10 ;
node arr[maxn] ;
int be[maxn] ;
int main()
{
    int n , temp;
    cin >> n ;
    node q ;
    for (int i =1 ; i<= n ; i++) {
        cin >> be[i] ;
        q.x = be[i] ;
        q.l = i ;
        arr[i] = q ;
    }
    if (n<=2) cout << "Nothing to do here" << endl ;
    else {
        if (n==3) {
            if (arr[1].x >= arr[2].x && arr[2].x >= arr[3].x)
            {
                cout << "Nothing to do here" << endl ;
                return 0 ;
            }
        }
        sort(arr+1,arr+n+1,cmp1) ;
        int ba = 0 ;
        int l=0 , r=0 ;
        for (int i = 1 ; i <= n ; i++){
            if (be[i]==arr[i].x) ba++ ;
            else {
                if (l==0) l = i ;
                else r = i ;
            }
        }
        if (ba==n){
            cout << "Nothing to do here" << endl ;
            return 0 ;
        }
        else if (ba==n-2) {
            cout << "Yes" << endl ;
            cout << l << " " << r << endl ;
            return 0 ;
        }

        sort(arr+1,arr+n+1,cmp2) ;
        ba = 0 ;
        l=0 , r=0 ;
        for (int i = 1 ; i <= n ; i++){
            if (be[i]==arr[i].x) ba++ ;
            else {
                if (l==0) l = i ;
                else r = i ;
            }
        }
        if (ba==n){
            cout << "Nothing to do here" << endl ;
            return 0 ;
        }
        else if (ba==n-2){
            cout << "Yes" << endl ;
            cout << l << " " << r << endl ;
            return 0 ;
        }
        cout << "No hope" << endl ;
    }
    return 0;
}
