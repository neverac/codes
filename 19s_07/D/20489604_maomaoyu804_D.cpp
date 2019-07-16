#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int num[1005];
int main()
{
    int n;cin>>n;
    while(n--){
        string s;cin>>s;
        int len=s.length();
        for(int i=1;i<=len;i++){
            if(s[i-1]=='1') num[i]=num[i-1]+1;
            else num[i]=num[i-1];
        }
        //for(int i=1;i<=len;i++) cout<<num[i]<<endl;
        int ans=2000;
        for(int i=0;i<=len;i++){
            ans=min(ans,num[i]+len-i-num[len]+num[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
