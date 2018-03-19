#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf

using namespace std;
typedef long long ll;

struct ss
{
    ll sum,prp;
}tree[410000];

void form(ll lo,ll hi,ll node)
{
    tree[node].prp=-1;
    tree[node].sum=0;
    if(lo==hi)
        return;
    form(lo,(lo+hi)/2,node*2),form(1+((lo+hi)/2),hi,1+(node*2));
    return;
}

ll update(ll lo,ll hi,ll node,ll x,ll y,ll v)
{

    if(tree[node].prp>-1)
    {
        if(lo!=hi){
            tree[node*2].prp=tree[node].prp;
            tree[1+(node*2)].prp=tree[node].prp;
        }
        tree[node].sum=tree[node].prp*(hi-lo+1);
        tree[node].prp=-1;
    }
    if(hi<x || lo>y)
        return tree[node].sum;
    if(lo>=x && hi<=y)
    {
        if(lo!=hi)
        {
            tree[node].prp=-1;
            tree[node*2].prp=v;
            tree[1+(node*2)].prp=v;
        }
        tree[node].prp=-1;
        return tree[node].sum=(hi-lo+1)*v;
    }
    return tree[node].sum=update(lo,(lo+hi)/2,node*2,x,y,v)+update(1+((lo+hi)/2),hi,1+(node*2),x,y,v);
}

ll qry(ll lo,ll hi,ll node,ll x,ll y)
{

    if(tree[node].prp>-1)
    {
        if(lo!=hi){
            tree[node*2].prp=tree[node].prp;
            tree[1+(node*2)].prp=tree[node].prp;
        }
        ll mid=(lo+hi)/2;
        //tree[node*2].sum=tree[node*2].prp*(mid-lo+1);
        //tree[1+(node*2)].sum=tree[1+(node*2)].prp*(hi-mid+1+1);
        tree[node].sum=tree[node].prp*(hi-lo+1);
        tree[node].prp=-1;
    }

    if(hi<x || lo>y)
        return 0;
    if(lo>=x && hi<=y)
    {
        return tree[node].sum;
    }
    return qry(lo,(lo+hi)/2,node*2,x,y)+qry(1+((lo+hi)/2),hi,1+(node*2),x,y);
}


int main()
{
    ll x,y,z,t,test,n,q,i,a,j;
    //freopen("out.txt","w",stdout);
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(q);
        pf("Case %lld:\n",t);
        form(0,n-1,1);
        for(i=1;i<=q;i++)
        {
            in(a);
            if(a==1)
            {
                in(x),in(y),in(z);
                if(x>y)
                    swap(x,y);
                x=update(0,n-1,1,x,y,z);
                //pf("Update ans = %lld\n",x);
            }
            else
            {
                in(x),in(y);
                if(x>y)
                    swap(x,y);
                z=qry(0,n-1,1,x,y);
                ll gc=__gcd(z,abs(y-x+1));

                if(gc==abs(y-x+1))
                    pf("%lld\n",z/gc);
                else
                    pf("%lld/%lld\n",z/gc,abs(y-x+1)/gc);

                //pf("Qry ==>>%lld\n",z);
            }
            /*pf("Now=====================================>>\n\n");
            for(j=1;j<=n*4;j++)
                pf("%lld = > s = %lld p = %lld\n",j,tree[j].sum,tree[j].prp);
            pf("\n\n");*/
        }
    }
    return 0;
}
