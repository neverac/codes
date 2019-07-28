#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int len=s.length();
    int ans=0;
    int flag=1;
    while(ans<len/2){
        //cout<<s[ans]<<s[len-ans-2]<<endl;
        if(s[ans]==s[len-ans-1]){
            ans++;
            continue;
        }
        if(ans==len/2){
            int i=ans;
            //cout<<i<<abccendl;
            while(i>=0){
                if(s[i]==s[i-1]) i--;
                else break;
            }
            cout<<i+1<<endl;
            flag=0;
            break;
        }
        if(s[ans+1]==s[len-ans-1]){
            int i=ans;
            //cout<<i<<endl;
            while(i>=0){
                if(s[i]==s[i-1]) i--;
                else break;
            }
            cout<<i+1<<endl;
            flag=0;
            break;
        }
        
        if(s[ans]==s[len-ans-2]){
            //cout<<1<<endl;
            cout<<len-ans<<endl;
            flag=0;
            break;
        }
    }
    //cout<<flag<<endl;
    if(ans==len/2&&flag){
        //if(len%2){
            int i=len/2;
            //cout<<i<<endl;
            while(i>=0){
                if(s[i]==s[i-1]) i--;
                else break;
            }
            cout<<i+1<<endl;
        //}
        //else cout<<1<<endl;
    }
    return 0;
}