#include <bits/stdc++.h>
#include <string.h>
#define ll long long

using namespace std ;

ll A[105];
ll M[205][205];
ll hang[25];
ll lie[25];
int main(){
    ll t,L,big,sum,m,x1,x2,y1,y2,ans;
    cin>>t;
    while(t--){
        cin>>L;
        ll cursor=0,big=0,sum=0;
        for(ll i=0;i<L;i++){
            cin>>A[i];sum+=A[i];
        }
        if(L%2==0){
            big=1LL*4 * L * sum ;
        }else {
            big=L*sum;
        }
        if(L%2==0)L*=2;//!!!!!!!!!!!!!!
        for (ll i = 0;i<2*L+5 ; ++i) {
        for (ll j = 0; j <= i; ++j) {
            M[j][i - j] = A[cursor];
            if(L%2==0)cursor = (cursor + 1) % (L/2);
            else cursor = (cursor + 1) % L;
            }
        }
        memset(hang,0,sizeof(hang));
        memset(lie,0,sizeof(lie));
        for(ll i=0;i<L;i++){//求行列和
            for(ll j=0;j<L;j++){
                //cout<<M[i][j]<<" \n"[j==L-1];
                hang[i]+=M[i][j];
                lie[j]+=M[i][j];
            }
        }
        //cout<<"matrix"<<M[2][2]<<endl;
        cin>>m;
        for(ll i=1;i<=m;i++){
            ans=0;
            cin>>x1>>y1>>x2>>y2;
            ll m1=(x2-x1+1)/L;
            ll m2=(y2-y1+1)/L;
            ll n1=(x2-x1+1)%L;
            ll n2=(y2-y1+1)%L;
            ans+=(m1*m2)*big;
            for(ll j=0;j<n1;j++){//行多余几个行
                ll ym= (x1+m1*L+j ) % L ;
                ans+=hang[ym]*m2;
                for(ll k=0;k<n2;k++){
                    ans+=M[ym][(y1+m2*L+k)%L];
                }
            }
            for(ll j=0;j<n2;j++){
                ll ym=(y1+m2*L+j) % L;
                ans+=lie[ym]*m1;
            }
            cout<<ans<<endl;
        }

    }
}
