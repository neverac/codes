#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a,b,c,ha,hb,hc;
int main(){
    cin >> a >> b >> c;
    cin >> ha >> hb >> hc;
    if(ha<a){
        cout << "NO" << endl;
        return 0;
    }
    if(ha+hb<a+b){
        cout << "NO" << endl;
        return 0;
    }
    if(ha+hb+hc<a+b+c){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}
