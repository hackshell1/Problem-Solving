#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
#define mid (lo+hi)/2
#define lft node*2
#define rgt lft+1
#define N tree[node]
#define L tree[lft]
#define R tree[rgt]

using namespace std;
typedef long long ll;

struct ss
{
    ll sum,maxx,lazy;
}tree[100000*8];

ll arr[2*100005];



ll form(ll lo,ll hi,ll node)
{
    N.sum=0;
    N.maxx=0;
    N.lazy=0;
    if(lo==hi)
        return 0;
    form(lo,mid,lft);
    form(mid+1,hi,rgt);
    return 0;
}

ll update(ll lo,ll hi,ll node,ll x,ll y)
{
    if(lo>y || hi<x){
        return 0;
    }
    if(lo>=x && hi<=y){
        N.sum+=1;
        return 1;
    }
    ll p=0,q=0;
    p=update(lo,mid,lft,x,y);
    q=update(mid+1,hi,rgt,x,y);
    N.sum+=(p|q);
    return 1;
}

int main()
{
    ll test,t,i,j,m,n,q,a,b;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(m);
        form(0,m+n-1,1);
        for(i=1;i<=n;i++)
        {
            in(a),in(b);
            a--;
            b--;
            if(a>b)
                swap(a,b);
            update(0,n+m-1,1,a,b);
        for(j=1;j<=(n+m)*3;j++)
            pf("%lld ==>> sum = %lld lazy = %lld\n",j,tree[j].sum,tree[j].lazy);
        }
    }
}
