#include <cstdio>
#include <cstring>
#include <algorithm>
#define SIZE 100100
using namespace std;

struct st
{
    int l,r;
    int num;
}tree[SIZE<<2];
struct st2
{
    int from,to,val;
}rec[SIZE];
int n,q;
int cnt=0;
void build(int l,int r,int i)
{
    tree[i].l=l;
    tree[i].r=r;
    if(l==r)
    {
        tree[i].num=0;
    }
    else
    {
        int mid=(l+r)/2;
        build(l,mid,i+i);
        build(mid+1,r,i+i+1);
        tree[i].num=tree[i+i].num&tree[i+i+1].num;
    }
}
void update(int l,int r,int val,int i)
{
 //   printf("l=%d r=%d val=%d i=%d\n",l,r,val,i);
    if(tree[i].l==l && tree[i].r==r)
    {
        tree[i].num|=val;
        return;
    }
    int mid=(tree[i].l+tree[i].r)/2;
    if(l<=mid)
    {
        update(l,min(r,mid),val,i+i);
    }
    if(r>mid)
    {
        update(max(l,mid+1),r,val,i+i+1);
    }
}
int query(int l,int r,int i)
{
  //  printf("l=%d r=%d i=%d val=%d\n",l,r,i,tree[i].num);

    if(tree[i].l==l && tree[i].r==r)
        return tree[i].num;
    int mid=(tree[i].l+tree[i].r)/2;
    if(r<=mid)
        return query(l,r,i+i);
    else if(l>mid)
        return query(l,r,i+i+1);
    else
        return query(l,mid,i+i)&query(mid+1,r,i+i+1);;
}
void solve(int i,int val)
{
    tree[i].num|=val;
    if(tree[i].r==tree[i].l)
    {
        cnt++;
        if(cnt==n)
            printf("%d\n",tree[i].num);
        else
            printf("%d ",tree[i].num);
        return;
    }
    solve(i+i,tree[i].num);
    solve(i+i+1,tree[i].num);
}
int main()
{
    int i;
    scanf("%d%d",&n,&q);
    build(1,n,1);
   // printf("yes\n");
    for(i=0;i<q;i++)
    {
        scanf("%d%d%d",&rec[i].from,&rec[i].to,&rec[i].val);
        update(rec[i].from,rec[i].to,rec[i].val,1);
    }
    bool can=true;
    for(i=0;i<q;i++)
    {
        int tmp=query(rec[i].from,rec[i].to,1);
   //     printf("tmp=%d\n",tmp);
        if(tmp!=rec[i].val)
        {
            can=false;
            break;
        }
    }
    if(can)
    {
        puts("YES");
        solve(1,0);
    }
    else
        puts("NO");
    return 0;
}
