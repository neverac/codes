#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int arr[100005];
int arru[100005];
int arrd[100005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arru[i]=arrd[i]=arr[i];
    }
    sort(arru+1,arru+1+n);
    sort(arrd+1,arrd+1+n,cmp);
    //for(int i=1;i<=n;i++)cout<<arrd[i]<<endl;
    int cnt1=0,cnt2=0,index1,index2;
    for(int i=1;i<=n;i++){
        if(arr[i]!=arru[i]){
            cnt1++;if(cnt1==1)index1=i;
        }
        if(arr[i]!=arrd[i]){
            cnt2++;
            if(cnt2==1)index2=i;
        }
    }
    if(cnt1==0||cnt2==0){
        cout<<"Nothing to do here"<<endl;
        return 0;
    }
    if(cnt1>2&&cnt2>2){
        cout<<"No hope"<<endl;
        return 0;
    }
    if(cnt1<=2){
        int j=index1+1;
        while(arr[j]==arru[j]&&j<=n)j++;
        cout<<"YES"<<endl;
        cout<<index1<<" "<<min(j,n)<<endl;
    }else{
        int j=index2+1;
        while(arr[j]==arrd[j]&&j<=n)j++;
        cout<<"YES"<<endl;
        cout<<index2<<" "<<min(j,n)<<endl;
    }

}