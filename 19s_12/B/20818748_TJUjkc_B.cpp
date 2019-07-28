#include<iostream>

using namespace std;

string s;

int main(){
    cin>>s;
    int ans=-1;
    int cnt;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s.at(i)!=s.at(len-1-i)){
            ans=0;
            if(i+1<len-1-i){
            for(int j=i;j<len;j++){
                if(j+1>=len-1-j) break;
                if(s.at(j+1)!=s.at(len-1-j)){
                    ans=1;
                    break;
                }
            }
            }
            if(ans==0){
                for(int j=i;j>=0;j--){
                    if(j==0){
                        cout<<1<<endl;
                        return 0;
                    }
                    if(s.at(j)!=s.at(j-1)){
                        cout<<j+1<<endl;
                        return 0;
                    }
                }
            }
            else{
                for(int j=len-1-i;j>=0;j--){
                    if(j==0){
                        cout<<1<<endl;
                        return 0;
                    }
                    if(s.at(j)!=s.at(j-1)){
                        cout<<j+1<<endl;
                        return 0;
                    }
                }
            }
            cout<<ans+1<<endl;
            return 0;
        }
    }
    if(ans==-1){
        for(int i=len/2;i>=0;i--){
            if(i==0){
                cout<<1<<endl;
                return 0;
            }
            if(s.at(i)!=s.at(i-1)){
                cout<<i+1<<endl;
                return 0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
