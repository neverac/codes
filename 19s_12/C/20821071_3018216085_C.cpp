#include <bits/stdc++.h>
#define maxn 10005
#define ll long long
using namespace std;

bool vis[100005];
struct node{int block,num;bool operator<(node b){return num<b.num;}}arr[200005];
int pos[100005];
int ctt[100005];
int main(){
    ios::sync_with_stdio(false);
    int n,m,tot=0;;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        arr[tot].block=i;
        cin>>arr[tot].num;
        tot++;
    }
    sort(arr,arr+tot);
    //for(int i=0;i<tot;i++)cout<<arr[i].block<<endl;
    int cnt=0,maa=INT_MAX;
    int be=0,en=0;
    for(int i=0;i<tot;i++){
        ctt[arr[i].block]++;
        if(ctt[arr[i].block]==1){
            pos[arr[i].block]=i;
            vis[i]=1;
            cnt++;
        }
        else{
            vis[pos[arr[i].block]]=0;
            pos[arr[i].block]=i;
            vis[i]=1;
        }
        int t=be;
        while(!vis[t])t++;
        be=t;en=i;
        if(cnt==n)maa=min(maa,arr[en].num-arr[be].num);
    }
    cout<<maa<<endl;
}

