#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
#define mid (lo+hi)/2
#define lft (node*2)
#define rgt 1+lft
#define L tree[lft]
#define R tree[rgt]
#define inf 1<<30

using namespace std;
typedef long long ll;

struct ss
{
    ll element_sum,sq_sum,lazy,type;
}tree[100005*4];

ll arr[100005];

void settings(ll lo,ll hi,ll node)
{
    if(lo>hi)
        pf("Yes Yes ......\n");
    if(tree[node].lazy!=-inf && tree[node].type!=0)
    {
        if(tree[node].type==1)
        {
            tree[node].sq_sum+=(tree[node].element_sum*2*tree[node].lazy)+(hi-lo+1)*tree[node].lazy*tree[node].lazy;
            tree[node].element_sum+=(hi-lo+1)*tree[node].lazy;
        }
        else if(tree[node].type==2)
        {
            tree[node].sq_sum=(hi-lo+1)*tree[node].lazy*tree[node].lazy;
            tree[node].element_sum=(hi-lo+1)*tree[node].lazy;
        }
        if(lo!=hi)
        {
            tree[lft].lazy=tree[node].lazy;
            tree[rgt].lazy=tree[node].lazy;
            tree[lft].type=tree[node].type;
            tree[rgt].type=tree[node].type;
        }
    }
    tree[node].lazy=-inf;
    tree[node].type=0;
    return;
}


void form(ll lo,ll hi,ll node)
{
    tree[node].element_sum=0;
    tree[node].lazy=-inf;
    tree[node].sq_sum=0;
    tree[node].type=0;
    if(lo==hi)
    {
        tree[node].element_sum=arr[lo];
        tree[node].sq_sum=arr[lo]*arr[lo];
        return;
    }
    form(lo,mid,lft);
    form(mid+1,hi,rgt);
    tree[node].element_sum=tree[lft].element_sum+tree[rgt].element_sum;
    tree[node].sq_sum=tree[lft].sq_sum+tree[rgt].sq_sum;
    return;
}

void update(ll lo,ll hi,ll node,ll x,ll y,ll v,ll type)
{
    if(lo<hi)
        settings(lo,hi,node);

    if(lo>y || hi<x)
        return;
    if(lo>=x && hi<=y)
    {
        tree[node].lazy=v;
        tree[node].type=type;
        settings(lo,hi,node);
        return;
    }
    update(lo,mid,lft,x,y,v,type);
    update(mid+1,hi,rgt,x,y,v,type);
    tree[node].sq_sum=tree[lft].sq_sum+tree[rgt].sq_sum;
    tree[node].element_sum=tree[lft].element_sum+tree[rgt].element_sum;
    return;
}

ll qry(ll lo,ll hi,ll node,ll x,ll y)
{
    settings(lo,hi,node);
    if(lo>y || hi<x)
        return 0;
    if(lo>=x && hi<=y)
        return tree[node].sq_sum;
    return qry(lo,mid,lft,x,y)+qry(mid+1,hi,rgt,x,y);
}

int main()
{
    //freopen("out.txt","w",stdout);
    ll test,t,n,q,i,a,b,x,v,j;
    in(test);
    for(t=1;t<=test;t++)
    {
        pf("Case %lld:\n",t);
        in(n),in(q);
        for(i=0;i<n;i++)
            in(arr[i]);
        form(0,n-1,1);
        for(i=1;i<=q;i++)
        {
            in(x);
            if(x==1)
            {
                in(a),in(b),in(v);
                if(a>b)
                    swap(a,b);
                update(0,n-1,1,a-1,b-1,v,1);
            }
            else if(x==0)
            {
                in(a),in(b),in(v);
                if(a>b)
                    swap(a,b);
                update(0,n-1,1,a-1,b-1,v,2);
            }
            else
            {
                in(a),in(b);
                pf("%lld\n",qry(0,n-1,1,a-1,b-1));
            }
        }
    }
    return 0;
}
