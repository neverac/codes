#include <iostream>
using namespace std;
#define ll long long
#define mod 1000000007
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn  = 5e6+5;

int t,cnt,ans,index,maxx;
string str;
int main(){
    cin >> t;
    while(t--){
        cin >> str;
        int l=str.length();
        index=-1;maxx=0;cnt=0;ans=0;;
        for(int i=0;i<l;i++){
            if(str[i]=='0') cnt++;
            else cnt--;
            if(cnt>maxx){
                maxx=cnt;
                index=i;
            }
        }
        for(int k=0;k<=index;k++){
            if(str[k]=='1') ans++;
        }
        for(int j=index+1;j<l;j++){
            if(str[j]=='0') ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
