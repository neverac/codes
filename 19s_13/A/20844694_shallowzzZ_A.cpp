#include <bits/stdc++.h>

using namespace std;
int n,x,pos,neg;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x;
        if(x>0) pos++;
        if(x<0) neg++;
    }
    if(pos>=(n+1)/2) cout << 1 << endl;
    else if(neg>=(n+1)/2) cout << -1 << endl;
    else cout << 0 << endl;
    return 0;
}
