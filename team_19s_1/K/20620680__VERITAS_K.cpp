#include <bits/stdc++.h>
#include <string.h>
#define ll long long

using namespace std ;

int main(){
    int t,cnt;
    string a;
    cin >> t;
    while(t--){
        cin >> a;
        int l=a.length();
        int pre=1;
        bool check=true;
        for(int i=0;i<l && check;i++){
            if(pre==1){
                if(a[i]=='*' || a[i]=='+') check =false;
                else if(a[i]=='0'){
                    pre=3;
                }
                else{
                    pre=2;
                    if(a[i]=='?') a[i]='1';
                }
            }
            else if(pre==2){
                if(a[i]=='*' || a[i]=='+') pre=1;
                else{
                    pre=2;
                    if(a[i]=='?') a[i]='1';
                }
            }
            else{
                if(a[i]=='*' || a[i]=='+') pre=1;
                else if(a[i]=='?'){
                    a[i]='+'; pre=1;
                }
                else check =false;
            }
        }
        if(a[l-1]=='*' || a[l-1]=='+') check=false;
        if(check) cout<< a << endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
}
