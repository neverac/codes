#include<bits/stdc++.h>
using namespace std;

#include<cstdio>
#include<cstring>
#define MAXN 500005
#define MAXL 2000005
#define ll long long
ll prime[MAXN];
ll check[MAXL],top,ans;
struct node{ll num,c;}cnt[1005];

map<ll,ll>mmp;
void dfs(ll x){
   // if(x>r) return ;
   //cout<<"in"<<endl;
    for(ll i=1;i<=top;i++){
        if(!mmp.count(x*cnt[i].num)) mmp[x*cnt[i].num]=0;
        if(cnt[i].c){
            cnt[i].c--;
            ans++;
            if(!mmp[x*cnt[i].num]){
                //cout << x*cnt[i].num << " ";
                mmp[x*cnt[i].num]=1;
                dfs(x*cnt[i].num);
            }
            cnt[i].c++;
        }
    }
}

int main() {
    ll tot = 0,test,n;
    memset(check, 0, sizeof(check));
    for (ll i = 2; i < MAXL; ++i)
    {
        if (!check[i])
        {
            prime[tot++] = i;
        }
        for (ll j = 0; j < tot; ++j)
        {
            if (i * prime[j] > MAXL)break;
                check[i*prime[j]] = 1;
            if (i % prime[j] == 0)break;
        }
    }
    //for(ll i=0;i<=100;i++)cout<<prime[i]<<endl;
    cin>>test;
    while(test--){

        cin>>n;
        bool pr=true;
        top=0;
        memset(cnt,0,sizeof(cnt));
        mmp.clear();
        for(ll i=0;prime[i]<=sqrt(n);i++){
            if(n%prime[i]==0){
                ll num=0;
                while(n%prime[i]==0)n/=prime[i],num++;
                pr=false;
                cnt[++top].c=num;
                cnt[top].num=prime[i];
            }
        }
        if(n!=1)cnt[++top].num=n,cnt[top].c=1;
        //for(ll i=1;i<=top;i++)cout<<cnt[i].c<<" "<<cnt[i].num<<endl;
        if(pr){
            cout<<1<<endl;continue;
        }
        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
