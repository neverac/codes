#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

long long n,m,k,a[200005],b[200005];
long long ans;
map<long long,long long> need;

/*bool need(long long num,long long l,long long r){
    long long mid=(l+r)/2;
    if(num==b[mid]){
        if(mid+1<n){
            while(b[mid+1]==b[mid]){
                mid++;
                if(mid+1>=n) break;
            }
        }
        if(mid>=n-m*k) return true;
        else return false;
    }
    else if(num<b[mid]){
        return need(num,l,mid);
    }
    else{
        return need(num,mid+1,r);
    }
}*/

int main(){
    ans=0;
    cin>>n>>m>>k;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    for(long long i=n-1;i>=n-m*k;i--){
        ans+=b[i];
    }
    cout<<ans<<endl;
    for(long long i=0;i<n;i++){
        need[b[i]]=0;
    }
    for(long long i=n-1;i>=n-m*k;i--){
        need[b[i]]=need[b[i]]+1;
    }
    long long cnt=0;
    long long cnt2=1;
    for(long long i=0;i<n;i++){
        //if(need(a[i],0,n-1)) cnt++;
        if(need[a[i]]>0){
            cnt++;
            need[a[i]]=need[a[i]]-1;
        }
        if(cnt>=m){
            cnt=0;
            cout<<i+1<<endl;
            cnt2++;
        }
        if(cnt2>=k){
            break;
        }
    }
    return 0;
}
