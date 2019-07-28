#include <bits/stdc++.h>

using namespace std;

struct node{
    int u,v;
}edge[105];
struct A{
    int dian,num;
}nu[105];
bool vis[210];

int cmp(A a,A b)
{
    return a.num > b.num;
}

int main()
{
    int m,n,e,ans;
    while(cin >> m)
    {
        if(!m)break;
        cin >> n >> e;
        ans = 0;
        memset(vis,0,sizeof(vis));
        for(int i = 0;i < 105;i++)
            nu[i].dian = nu[i].num = 0;
        //mp.clear();
        for(int i = 0;i < e;i++)
        {
            cin >> edge[i].u >> edge[i].v;
            edge[i].v += m;
            nu[edge[i].u].num++;
            nu[edge[i].u].dian = edge[i].u;
            nu[edge[i].v].num++;
            nu[edge[i].v].dian = edge[i].v;
        }
        sort(nu,nu+m+n,cmp);
        bool is = 1;
        while(1)
        {
            if(nu[0].num == 0)break;
            is = 0;
            for(int i = 0;i < e;i++)
            {
                if(!vis[i]&&(edge[i].u == nu[0].dian || edge[i].v == nu[0].dian)){
                    vis[i] = 1;
                    is = 1;
                    for(int j = 1;j < m+n;j++)
                    {
                        if(edge[i].u == nu[j].dian || edge[i].v == nu[j].dian)
                            nu[j].num--;
                    }
                }
            }
            if(is){
            //    cout << "dian:" << nu[j].dian << endl;
                nu[0].num = 0;
                ans++;
            }
            sort(nu,nu+m+n,cmp);
        }
        cout << ans << endl;
    }
    return 0;
}
