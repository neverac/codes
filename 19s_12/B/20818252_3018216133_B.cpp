#include <iostream>

using namespace std;

string str;
int le;

int check(int x)
{
    if(x <0 || x >= le)return 0;
    bool is = 1;
    int ll = 0,rr = le-1;
    if(ll == x)ll++;
    if(rr == x)rr--;
    while(ll <= rr)
    {
        if(str[ll] != str[rr]){is = 0;break;}
        ll++,rr--;
        if(ll == x)ll++;
        if(rr == x)rr--;
    }
    if(is)return 1;
    else return 0;
}

int main()
{
    int l,r;
    int ans;
    bool is = 0;
    cin >> str;
    le = str.length();
    if(le%2){
        int mid = le/2+1;
        l = mid-2;
        r = mid - 1;
        while(l >= 0 && r <le)
        {
            if(str[l] != str[r]){is = 1;break;}
            l--,r++;
        }
        //cout << l << r << endl;
        if(check(l))ans = l;
        if(check(r))ans = r;
        //cout << ans <<endl;
        mid++;
        l = mid-2;
        r = mid - 1;
        while(l >= 0 && r <le)
        {
            if(str[l] != str[r]){is = 1;break;}
            l--,r++;
        }
        //cout << l << r <<endl;
        //cout << check(l) << endl;
        if(check(l))ans = min(ans,l);
        if(check(r))ans = min(ans,r);
        //cout << ans << endl;
    }else{
        int mid = le/2;
        l = r = mid-1;
        while(l >= 0 && r < le)
        {
            if(str[l] != str[r]){is = 1;break;}
            l--,r++;
        }
        if(check(l))ans = l;
        if(check(r))ans = r;
        mid++;
        l = r = mid - 1;
        is = 0;
        while(l >= 0 && r < le)
        {
            if(str[l] != str[r]){is = 1;break;}
            l--,r++;
        }
        if(check(l))ans = min(ans,l);
        if(check(r))ans = min(ans,r);
    }
    cout << ans+1 << endl;
    return 0;
}
