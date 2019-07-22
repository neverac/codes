#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#define SIZE 1010

using namespace std;

int n;
int dad[SIZE];
int sure[SIZE];
int status[SIZE];
int an[SIZE];
int num[5];
string name[SIZE];
int father(int x)
{
    if(dad[x]==x)
        return x;
    return dad[x]=father(dad[x]);
}
bool connect(int a,int b)
{
    int x=father(a);
    int y=father(b);
    dad[x]=y;
    sure[y]+=sure[x];
    sure[x]=0;
    return sure[y]<5;
}

bool cmp(int a,int b)
{
    if(sure[dad[a]]!=sure[dad[b]])
        return sure[dad[a]]>sure[dad[b]];
    return dad[a]<dad[b];
}
int main()
{
    int m,i;
    int p1,p2;
    string player1,player2;
    string action,pos;
    bool legal=true;
    map<string,int> mp;
    cin >> n;
    for(i=1;i<=n;i++)
        dad[i]=i;
    for(i=1;i<=n;i++)
        status[i]=3;
    for(i=1;i<=n;i++)
        sure[i]=1;
    for(i=1;i<=n;i++)
        an[i]=i;
    for(i=1;i<=n;i++)
    {
        cin >> name[i];
        mp[name[i]]=i;
    }
    cin >> m;
    while(m--)
    {
        cin >> player1 >> action >> player2;
        p1=mp[player1];
    //    cout << "action=" << action << endl;
        if(action[0]=='H')
        {
            cin >> name[0] >> pos;
            p2=mp[player2];
            if(status[p1]<2)
            {
                legal=false;
                break;
            }
            if(pos[0]=='H')
                status[p2]-=2;
            else
                status[p2]--;
            status[p2]=max(0,status[p2]);
        }
        else if(action[0]=='R')
        {
            p2=mp[player2];
            if(status[p1]<2 || status[p2]!=1)
            {
                legal=false;
                break;
            }
            status[p2]=2;
            bool can=connect(p1,p2);
            if(!can)
            {
                legal=false;
                break;
            }
        }
        else
        {
            if(status[p1]<2)
            {
                legal=false;
                break;
            }
            else
                status[p1]=3;
        }

    }
    if(legal)
    {
        for(i=1;i<=n;i++)
            father(i);
        sort(an+1,an+n+1,cmp);
        num[0]=n;
        for(i=1;i<=n;i++)
        {
  //          cout << name[an[i]] << " " << " dad:" << dad[an[i]] << " sure:" << sure[an[i]] << endl;
            num[sure[an[i]]]++;
        }
   //     putchar('\n');
        num[1]-=num[3];
        num[1]-=num[2]%2;
        legal=(num[1]>=0);
    }
    if(legal)
    {
        puts("CORRECT");
        int cnt=n;
        int nnum=4;
        i=1;
        for(int j=n>>2;j>0;j--)
        {
            if(sure[dad[an[i]]]==4)
            {
                cout << name[an[i]] << " "
                     << name[an[i+1]] << " "
                     << name[an[i+2]] << " "
                     << name[an[i+3]] << endl;
                i+=4;
            }
            else if(sure[dad[an[i]]]==3)
            {
                cout << name[an[i]] << " "
                     << name[an[i+1]] << " "
                     << name[an[i+2]] << " "
                     << name[an[cnt]] << endl;
                cnt--;
                i+=3;
            }
            else if(sure[dad[an[i]]]==2)
            {
                cout << name[an[i]] << " "
                     << name[an[i+1]] << " ";
                i+=2;
                if(sure[dad[an[i]]]==2)
                {
                    cout << name[an[i]] << " "
                         << name[an[i+1]] << endl;
                    i+=2;
                }
                else
                {
                    cout << name[an[cnt]] << " "
                         << name[an[cnt-1]] <<endl;
                         cnt-=2;
                }
            }
            else
            {
                cout << name[an[i]] << " "
                     << name[an[i+1]] << " "
                     << name[an[i+2]] << " "
                     << name[an[i+3]] << endl;
                i+=4;
            }
        }
    }
    else
        puts("FAKE");
    return 0;
}