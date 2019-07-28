#include <iostream>
#include <cstdio>
using namespace std;
int vis[11];

int main()
{
    int p,q;
    cin>>p>>q;
    for(int i=0;i<=1000000;i++){
        p*=10;
        vis[p/q]=1;
        p-=q*(p/q);
    }
    for(int i=0;i<10;i++){
        if(vis[i]) cout<<i;
    }
    return 0;
}