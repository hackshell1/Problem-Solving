#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
#define lft node*2
#define rgt 1+lft
#define mid (lo+hi)/2
#define inf 1<<30

using namespace std;
typedef long long ll;

ll arr[50005];

struct ss
{
    ll lft_sum,mid_sum,rgt_sum,tot_sum;
}tree[50005*4];

ss maxxx(ss l,ss r)
{
    ss x;
    x.lft_sum=max(l.lft_sum,r.lft_sum+l.tot_sum);
    x.mid_sum=max(max(l.mid_sum,r.mid_sum),l.rgt_sum+r.lft_sum);
    x.rgt_sum=max(r.rgt_sum,l.rgt_sum+r.tot_sum);
    x.tot_sum=l.tot_sum+r.tot_sum;
    return x;
}

void form(ll lo,ll hi,ll node)
{
    tree[node].lft_sum=tree[node].mid_sum=tree[node].rgt_sum=tree[node].tot_sum=-inf;
    if(lo==hi)
    {
        tree[node].lft_sum=tree[node].mid_sum=tree[node].rgt_sum=tree[node].tot_sum=arr[lo];
        return;
    }
    form(lo,mid,lft);
    form(mid+1,hi,rgt);
    tree[node]=maxxx(tree[lft],tree[rgt]);
    return;
}

ss qry(ll lo,ll hi,ll node,ll X,ll Y)
{
    ss l,r,x;
    r.lft_sum=r.mid_sum=r.rgt_sum=r.tot_sum=-inf;
    if(lo>Y || hi<X)
        return r;
    if(lo>=X && hi<=Y)
        return tree[node];
    l=qry(lo,mid,lft,X,Y);
    r=qry(mid+1,hi,rgt,X,Y);
    return x=maxxx(l,r);
}

ss update(ll lo,ll hi,ll node,ll x,ll v)
{
    ss p,q;
    if(lo>x || hi<x)
        return tree[node];
    if(lo==hi)
    {
        tree[node].lft_sum=tree[node].mid_sum=tree[node].rgt_sum=tree[node].tot_sum=v;
        return tree[node];
    }
    p=update(lo,mid,lft,x,v);
    q=update(mid+1,hi,rgt,x,v);
    return tree[node]=maxxx(p,q);
}

int main()
{
    ll n,maxx=0,i,qr,a,b,x;
    in(n);
    for(i=0;i<n;i++)
        in(arr[i]);
    form(0,n-1,1);
    in(qr);
    for(i=1;i<=qr;i++)
    {
        in(x);
        if(x==1)
        {
            in(a),in(b);
            if(a>b)
                swap(a,b);
            ss p;
            p=qry(0,n-1,1,a-1,b-1);
            maxx=max(max(max(p.lft_sum,p.mid_sum),p.rgt_sum),p.tot_sum);
            pf("%lld\n",maxx);
        }
        else
        {
            in(a),in(b);
            update(0,n-1,1,a-1,b);
        }
   }
   return 0;
}

