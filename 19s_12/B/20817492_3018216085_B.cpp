#include <bits/stdc++.h>
#define maxn 10005
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string a;
    cin>>a;int i=0,j=a.length()-1;
    for(;i<j;i++,j--){
        if(a[i]!=a[j]){
            bool ci=true,cj=true;
            for(int n=i,m=j-1;n<=m;n++,m--){
                if(a[n]!=a[m])ci=false;
            }
            for(int n=i+1,m=j;n<=m;n++,m--){
                if(a[n]!=a[m])cj=false;
            }

            if(ci==false&&cj==true){

                char t=a[i];
                while(a[i]==t)i--;
                cout<<i+2<<endl;
            }
            else if(ci==true&&cj==false){

                char t=a[j];
                while(a[j]==t)j--;
                cout<<j+2<<endl;
            }
            else {
                char t=a[i];
                while(a[i]==t)i--;
                cout<<i+2<<endl;
            }
            return 0;
        }
    }
    char t=a[i];
while(a[i]==t)i--;
   cout<<i+2<<endl;
}

