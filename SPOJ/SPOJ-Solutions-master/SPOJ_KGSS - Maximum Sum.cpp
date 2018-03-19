#include<bits/stdc++.h>
#define pf printf
#define in(a) scanf("%lld",&a)


using namespace std;
typedef long long ll;

struct ss
{
    ll maxx1,maxx2;
}tree[410000];

ll arr[110000],aee[5];

void form(ll lo,ll hi,ll node)
{
    if(lo==hi)
    {
        tree[node].maxx1=arr[lo];
        tree[node].maxx2=0;
        return;
    }
    form(lo,(lo+hi)/2,node*2);
    form(1+((lo+hi)/2),hi,1+(node*2));
    aee[0]=tree[node*2].maxx1;
    aee[1]=tree[node*2].maxx2;
    aee[2]=tree[1+(node*2)].maxx1;
    aee[3]=tree[1+(node*2)].maxx2;
    sort(aee,aee+4);
    tree[node].maxx1=aee[3];
    tree[node].maxx2=aee[2];
    return;
}

ss qry(ll lo,ll hi,ll node,ll x,ll y)
{
    ss p,q;

    ll aee[5];

    p.maxx1=0;
    p.maxx2=0;
    q.maxx1=0;
    q.maxx2=0;

    if(lo>y || hi<x)
        return p;
    if(lo>=x && hi<=y)
        return tree[node];
    p=qry(lo,(lo+hi)/2,node*2,x,y);
    q=qry(1+((lo+hi)/2),hi,1+(node*2),x,y);

    aee[0]=p.maxx1;
    aee[1]=p.maxx2;
    aee[2]=q.maxx1;
    aee[3]=q.maxx2;
    sort(aee,aee+4);

    p.maxx1=aee[3];
    p.maxx2=aee[2];

    return p;
}

ss update(ll lo,ll hi,ll node,ll pos,ll v)
{
    ll aee[5];
    ss p,q;
    if(lo>pos || hi<pos)
        return tree[node];
    if(lo==pos && hi==pos)
    {
        tree[node].maxx1=v;
        tree[node].maxx2=0;
        return tree[node];
    }
    p=update(lo,(lo+hi)/2,node*2,pos,v);
    q=update(1+((lo+hi)/2),hi,1+(node*2),pos,v);


    aee[0]=p.maxx1;
    aee[1]=p.maxx2;
    aee[2]=q.maxx1;
    aee[3]=q.maxx2;
    sort(aee,aee+4);
    tree[node].maxx1=aee[3];
    tree[node].maxx2=aee[2];
    return tree[node];
}

int main()
{
    ll n,i,q,a,b;
    in(n);
    char c;
    for(i=0;i<n;i++)
        in(arr[i]);
    form(0,n-1,1);

    in(q);
    for(i=1;i<=q;i++)
    {
        cin>>c;
        in(a),in(b);
        if(c=='Q'){
            ss p=qry(0,n-1,1,a-1,b-1);
            pf("%lld\n",p.maxx1+p.maxx2);
        }
        else
            update(0,n-1,1,a-1,b);

        /*for(ll j=1;j<=4*n;j++)
            pf("%lld %lld    ",tree[j].maxx1,tree[j].maxx2);
        pf("\n");*/
    }
    return 0;
}
