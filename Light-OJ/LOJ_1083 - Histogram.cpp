#include<bits/stdc++.h>
#define pf printf
#define in(a) scanf("%lld",&a)
using namespace std;
typedef long long ll;
ll sp[15][31000],arr[31000];
ll form(ll n)
{
    ll i,j,lim=log2(n);
    for(i=1;i<=lim;i++)
        for(j=0;j<=n-(1<<i);j++)
            sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1<<(i-1))]);
}
ll qry(ll a,ll b)
{
    if(a>b)
        swap(a,b);
    ll i,j,lim=log2(b-a+1);
    return min(sp[lim][a],sp[lim][b-(1<<lim)+1]);
}

ll bsrc1(ll lo,ll hi,ll a)
{
    ll x=hi,maxx=1,mid,cnt=0,p,i;
    while(lo<hi)
    {
        if(hi-lo<=3)
        {
            for(i=hi;i>=lo;i--)
            {
                if(sp[0][i]>=a)
                    maxx=max(maxx,x-i+1);
                else
                    return maxx;
            }
        }
        mid=(lo+hi)/2;
        p=qry(mid,hi);
        if(p>=a)
        {
            hi=mid-1;
            maxx=max(maxx,x-mid+1);
        }
        else
            lo=mid;
    }
    return maxx;
}

ll bsrc2(ll lo,ll hi,ll a)
{
    ll x=lo,maxx=1,mid,cnt=0,p,i;
    while(lo<hi)
    {
        if(hi-lo<=3)
        {
            for(i=lo;i<=hi;i++)
            {
                if(sp[0][i]>=a)
                    maxx=max(maxx,i-x+1);
                else
                    return maxx;
            }
        }
        mid=(lo+hi)/2;
        p=qry(x,mid);
        if(p>=a)
        {
            maxx=max(maxx,mid-x+1);
            lo=mid+1;
        }
        else
            hi=mid;
    }
    return maxx;
}


int main()
{
    ll test,t,n,i,lim,j,a,b,x,maxx,p,q;
    in(test);
    for(t=1;t<=test;t++)
    {
        maxx=0;
        in(n),lim=log2(n);

        for(i=0;i<n;i++)
            in(sp[0][i]);
        form(n);

        for(i=0;i<n;i++)
        {
            p=bsrc1(0,i,sp[0][i]);
            q=bsrc2(i,n-1,sp[0][i]);
            //pf("%lld <== %lld => %lld\n",p,sp[0][i],q);

            maxx=max(maxx,(p+q-1)*sp[0][i]);
        }
        pf("Case %lld: %lld\n",t,maxx);
    }
    return 0;
}
