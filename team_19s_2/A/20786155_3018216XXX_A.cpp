#include<bits/stdc++.h>
using namespace std;
int a[10004];
int main()
{
    int n,d;
    while(cin>>n&&n)
    {
        cin>>d;
        for(int i=0;i<n;i++) cin>>a[i];
        int flag=1;
        int semi=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]-a[i-1]>d)
            {
                if(a[i+1]-a[i-1]>2*d)
                {
                    flag=0;
                    break;
                }
                semi++;
            }
        }
        if(!flag) cout<<"N"<<endl;
        else
        {
            if(semi>1) cout<<"N"<<endl;
            else cout<<"Y"<<endl;
        }
    }
}
