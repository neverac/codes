#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int t;
int n;
int w[100005];

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>w[i];
        cout<<(int)sqrt(abs(w[n]-w[1]))<<endl;
    }
    return 0;
}
