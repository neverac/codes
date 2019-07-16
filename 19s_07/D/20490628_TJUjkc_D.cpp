#include<iostream>
#include<algorithm>
#include<cmath>
#include<memory.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int len=s.length();
        int ans=1005;
        for(int i=0;i<len;i++){
            if(s.at(i)=='1'){
                int cnt=0;
                for(int j=0;j<i;j++){
                    if(s.at(j)=='1') cnt++;
                }
                for(int j=i+1;j<len;j++){
                    if(s.at(j)=='0') cnt++;
                }
                ans=min(ans,cnt);
            }
            if(s.at(i)=='0'){
                int cnt=0;
                for(int j=0;j<i;j++){
                    if(s.at(j)=='1') cnt++;
                }
                for(int j=i+1;j<len;j++){
                    if(s.at(j)=='0') cnt++;
                }
                ans=min(ans,cnt);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


