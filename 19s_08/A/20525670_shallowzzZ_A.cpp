#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 0x3f3f3f3f;

int n,x,cnt[10],minn;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x;
        if(x==4)  cnt[1]++;
        if(x==8  && cnt[2]<cnt[1])  cnt[2]++;
        if(x==15 && cnt[3]<cnt[2]) cnt[3]++;
        if(x==16 && cnt[4]<cnt[3]) cnt[4]++;
        if(x==23 && cnt[5]<cnt[4]) cnt[5]++;
        if(x==42 && cnt[6]<cnt[5]) cnt[6]++;
    }
    minn=inf;
    for(int i=1;i<=6;i++) minn=min(cnt[i],minn);
    cout << n-6*minn << endl;
    return 0;
}
