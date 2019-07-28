#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#define Rint register int
#define mem(a,b) memset(a,(b),sizeof(a))
#define Temp template<typename T>
using namespace std;

int arr[105];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    int pos=0,neg=0,zer=0;
    for(int i=1;i<=n;i++){
        if(arr[i]>0)pos++;
        else if(arr[i]<0)neg++;
        else zer++;
    }
    if(pos>=((n+1)/2))cout<<1<<endl;
    else if(neg>=((n+1)/2))cout<<-1<<endl;
    else cout<<0<<endl;
}
