#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int num[1003][1003];
int row[1003][1003];


int main()
{
    int n;cin>>n;
    memset(num,-1,sizeof(num));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&num[i][j]);
            if(j==0) row[i][j]=1;
            else{
                if(num[i][j]==num[i][j-1]+1) row[i][j]=row[i][j-1]+1;
                else row[i][j]=1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //if(row[i][j]<=ans) continue;
            int temp=i+1;
            int flag=1;
            int len=row[i][j];
            if(i+row[i][j]-1>=n) flag=0;
            else while(temp<i+len&&(i+row[i][j]-1<n)){
                len=min(row[temp][j],row[temp-1][j]);
                if(num[temp][j]!=num[temp-1][j]+1) flag=0;
                temp++;
            }
            if(flag) ans=max(ans,len);
            //cout<<ans;
            //cout<<flag<<" ";
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
}
