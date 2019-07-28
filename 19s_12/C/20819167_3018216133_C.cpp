#include <iostream>
#include <algorithm>

using namespace std;

struct node{
    int kuai,num;
}shu[200005];
int tot;

bool is[200005];
int cntk[200005];

int cmp(node a,node b)
{
    return a.num < b.num;
}

int main()
{
    int n,m;
    int ans = 100000000;
    cin >> n >> m;
    for(int i =   1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            cin >> shu[tot].num;
              shu[tot++].kuai = i;
        }
    }
    sort(shu,shu+tot,cmp);
    int l,r;
    l = r = 0;
    int cnt = 0;
    while(r < tot)
    {
        while(r < tot && cnt < n)
        {
            if(!cntk[shu[r].kuai])cnt++;
            cntk[shu[r].kuai]++;
            r++;
        }
        if(cnt < n)break;
        while(l < r-1 && cnt >= n)
        {
            cntk[shu[l].kuai]--;
            if(!cntk[shu[l].kuai])cnt--;
            l++;
        }
        //cout << l << "       " << r <<endl;
        //cout << shu[r-1].num << " " << shu[l-1].num << endl;
        ans = min(ans,shu[r-1].num - shu[l-1].num);
    }
    cout << ans << endl;
    return 0;
}
