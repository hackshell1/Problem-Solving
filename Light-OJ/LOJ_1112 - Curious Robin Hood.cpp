#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
using namespace std;
typedef long long ll;



ll arr[110000],aee[410000];

ll form(ll lo,ll hi,ll node)
{
    ll x,y;
    if(lo==hi)
        return aee[node]=arr[hi];
    return aee[node]=form(lo,(lo+hi)/2,node*2)+form(1+((lo+hi)/2),hi,1+(node*2));
}

ll qry(ll lo,ll hi,ll node,ll i,ll j)
{
    if(hi<i || lo>j)
        return 0;
    if(lo>=i && hi<=j)
        return aee[node];
    if(lo==hi)
        return 0;
    return qry(lo,(lo+hi)/2,node*2,i,j)+qry(1+((lo+hi)/2),hi,1+(node*2),i,j);
}

ll update(ll lo,ll hi,ll node,ll i,ll make)
{
    ll x,y;
    if(hi<i)
        return aee[node];
    if(lo>i)
        return aee[node];
    if(lo==hi)
        return aee[node]+=make;
    return aee[node]=update(lo,(lo+hi)/2,node*2,i,make)+update(1+(lo+hi)/2,hi,1+(node*2),i,make);
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test,len,sum=0,how,r;
    in(test);
    for(t=1;t<=test;t++)
    {
        pf("Case %lld:\n",t);
        in(n),in(how);
        for(i=0;i<n;i++)
            in(arr[i]);


        x=form(0,n-1,1);
        for(i=0;i<how;i++)
        {
            in(p);
            if(p==1)
            {
                in(q);
                x=qry(0,n-1,1,q,q);
                y=update(0,n-1,1,q,-x);
                pf("%lld\n",x);
            }
            else if(p==2)
            {
                in(q),in(r);
                x=update(0,n-1,1,q,r);
                //pf("%lld\n",x);
            }
            else
            {
                in(q),in(r);
                x=qry(0,n-1,1,q,r);
                pf("%lld\n",x);
            }
        }
    }
    return 0;
}


