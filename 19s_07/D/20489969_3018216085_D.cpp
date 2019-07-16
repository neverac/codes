#include<bits/stdc++.h>
#define  MAX 100005
#define  MOD 1000000007
#define ll long long
using namespace std;

int cy[1005];

int main(){
    int n;
    string a;
    cin>>n;
    while(n--){
        int cnt=0,pos=0;
        memset(cy,0,sizeof(cy));
        cin>>a;
        char bef='0';
        for(int i=0;i<a.length();i++){
           if(a[i]==bef){
                cnt++;
           }
           else{
                cy[pos++]=cnt;
                cnt=1;
                bef=a[i];
           }
        }
        cy[pos++]=cnt;
        int ans=0,ma=0,index=0,now=0;
        for(int i=0;i<pos;i++){
            if(i%2==0){
                now+=cy[i];
                if(now>ma){
                    index=i;
                    ma=now;
                }
            }else{
                now-=cy[i];
            }
        }
        //for(int i=0;i<pos;i++)cout<<cy[i]<<" ";cout<<endl<<endl;;
        //for(int i=0;i<pos;i++)cout<<s[i]<<" ";cout<<endl;
        //cout<<index<<endl;
        for(int i=0;i<=index;i++){
            if(i%2==1)ans+=cy[i];
        }
        for(int i=index+1;i<pos;i++){
            if(i%2==0)ans+=cy[i];
        }
        cout<<ans<<endl;
    }
}