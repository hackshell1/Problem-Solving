#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
#define sf scanf
#define mid (lo+hi)/2
#define lft node*2
#define rgt 1+(node*2)
#define inf 1<<30

using namespace std;
typedef long long ll;

struct ss
{
    ll maxx,minn;
}tree[510][510*4];

void form(ll i,ll lo,ll hi,ll node)
{
    ll x;
    tree[i][node].maxx=-1;
    tree[i][node].minn=inf;
    if(lo==hi)
    {
        in(x);
        tree[i][node].maxx=tree[i][node].minn=x;
        return;
    }
    form(i,lo,mid,lft);
    form(i,mid+1,hi,rgt);
    tree[i][node].maxx=max(tree[i][lft].maxx,tree[i][rgt].maxx);
    tree[i][node].minn=min(tree[i][lft].minn,tree[i][rgt].minn);
    return;
}

void update(ll i,ll lo,ll hi,ll node,ll pos,ll v)
{
    if(hi<pos || lo>pos)
        return;
    if(lo==hi)
    {
        tree[i][node].maxx=v;
        tree[i][node].minn=v;
        return;
    }
    update(i,lo,mid,lft,pos,v);
    update(i,mid+1,hi,rgt,pos,v);
    tree[i][node].maxx=max(tree[i][lft].maxx,tree[i][rgt].maxx);
    tree[i][node].minn=min(tree[i][lft].minn,tree[i][rgt].minn);
    return;
}

ss qry(ll i,ll lo,ll hi,ll node,ll x,ll y)
{
    ss m,d,e;
    m.maxx=-1;
    m.minn=inf;
    if(lo>y || hi<x)
        return m;
    if(lo>=x && hi<=y)
        return tree[i][node];
    d=qry(i,lo,mid,lft,x,y);
    e=qry(i,mid+1,hi,rgt,x,y);
    m.maxx=max(d.maxx,e.maxx);
    m.minn=min(d.minn,e.minn);
    return m;
}


int main()
{
    ll a,i,n,qr,p,q,r,s,maxx,minn,j;
    char c;
    //freopen("out.txt","w",stdout);
    while(in(n)==1)
    {
        for(i=0;i<n;i++)
            form(i,0,n-1,1);
        /*for(i=0;i<n;i++)
            pf("Max = %lld  Min = %lld\n",tree[i][1].maxx,tree[i][1].minn);*/

        in(qr);
        for(i=1;i<=qr;i++)
        {
            getchar();
            sf("%c",&c);
            if(c=='c')
            {
                in(p),in(q),in(r);
                update(p-1,0,n-1,1,q-1,r);
            }
            else
            {
                in(p),in(q),in(r),in(s);
                maxx=0;
                minn=inf;
                if(q>s)
                    swap(q,s);
                if(p>r)
                    swap(p,r);
                for(j=p;j<=r;j++)
                {
                    ss m;
                    m=qry(j-1,0,n-1,1,q-1,s-1);
                    //pf("From %lld to %lld of %lld\n",p-1,r-1,j-1);
                    maxx=max(maxx,m.maxx);
                    minn=min(minn,m.minn);
                }
                pf("%lld %lld\n",maxx,minn);
            }

            /*for(j=0;j<n;j++)
                pf("Max = %lld  Min = %lld\n",tree[j][1].maxx,tree[j][1].minn);*/
        }
    }
    return 0;
}
