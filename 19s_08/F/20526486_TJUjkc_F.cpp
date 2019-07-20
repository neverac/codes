#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
int a[100005];
int maxnum,minnum;
int ans1[100005];
int ans2[100005];

int main(){
    //cin>>n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        //cin>>a[i];
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    minnum=a[0];
    maxnum=a[n-1];
    for(int i=1;i<n-1;i++){
        if(a[i]<0){
            ans1[i]=maxnum;
            ans2[i]=a[i];
            maxnum-=a[i];
        }
        else{
            ans1[i]=minnum;
            ans2[i]=a[i];
            minnum-=a[i];
        }
    }
    cout<<maxnum-minnum<<endl;
    for(int i=1;i<n-1;i++){
        //cout<<ans1[i]<<" "<<ans2[i]<<endl;
        printf("%d %d\n",ans1[i],ans2[i]);
    }
    //cout<<maxnum<<" "<<minnum<<endl;
    printf("%d %d\n",maxnum,minnum);
    return 0;
}
