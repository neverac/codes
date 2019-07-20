#include<bits/stdc++.h>
#define  MAX 100005
#define  MOD 1000000007
#define ll long long
using namespace std;

int arr[500005];
int cnt[10];
int ha[100];
int main() {//4,8,15,16,23,42
    int n,a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        switch(a){
        case 4:{
            cnt[1]++;
            break;
        }
        case 8:{
            if(cnt[1])cnt[2]++,cnt[1]--;
            break;
        }
        case 15:{
            if(cnt[2])cnt[3]++,cnt[2]--;
            break;
        }
        case 16:{
            if(cnt[3])cnt[4]++,cnt[3]--;
            break;
        }
        case 23:{
            if(cnt[4])cnt[5]++,cnt[4]--;

            break;
        }
        case 42:{
            if(cnt[5])cnt[6]++,cnt[5]--;

            break;
        }
        default:
            break;
        }
    }
    cout<<n-6*cnt[6]<<endl;
}
