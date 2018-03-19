#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[100002];

struct ss
{
    ll prpgn,sum;
}tree[400005];


ll form(ll node,ll st,ll ed)
{
    if(st==ed)
    {
        tree[node].prpgn=0;
        return tree[node].sum=arr[st];
    }
    ll mid,left,right;

    mid=(st+ed)/2;
    left=node*2;
    right=node*2+1;

    tree[node].prpgn=0;

    return tree[node].sum=form(left,st,mid)+form(right,mid+1,ed);
}

ll update(ll node,ll st,ll ed,ll x,ll y,ll v)
{
    if(st>y || ed<x)
        return tree[node].sum;
    if(st>=x && ed<=y)
    {
        tree[node].prpgn+=v;
        return tree[node].sum+=(ed-st+1)*v;
    }

    ll mid,left,right;

    mid=(st+ed)/2;
    left=node*2;
    right=node*2+1;

    return tree[node].sum=update(left,st,mid,x,y,v)+update(right,mid+1,ed,x,y,v)+(ed-st+1)*tree[node].prpgn;
}

ll qry(ll node,ll st,ll ed,ll x,ll y,ll prp)
{
    if(st>y || ed<x)
        return 0;
    if(st>=x && ed<=y)
        return tree[node].sum+(ed-st+1)*prp;
    ll mid,left,right;
    mid=(st+ed)/2;
    left=node*2;
    right=node*2+1;
    return qry(left,st,mid,x,y,prp+tree[node].prpgn)+qry(right,mid+1,ed,x,y,prp+tree[node].prpgn);
}

int main()
{
    ll a,t,test,qr,x,y,v,i,j,n,q;

    scanf("%lld",&test);
    for(t=1;t<=test;t++)
    {
        printf("Case %lld:\n",t);
        scanf("%lld%lld",&n,&q);
        for(i=0;i<=n;i++)
            arr[i]=0;
        form(1,0,n-1);
        for(i=0;i<q;i++){
            scanf("%lld",&qr);
            if(qr==0)
            {
                scanf("%lld%lld%lld",&x,&y,&v);
                update(1,0,n-1,x,y,v);
            }
            else
            {
                scanf("%lld%lld",&x,&y);
                printf("%lld\n",qry(1,0,n-1,x,y,0));
            }
        }
    }
    return 0;
}
