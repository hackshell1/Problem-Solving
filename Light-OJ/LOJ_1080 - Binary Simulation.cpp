#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
using namespace std;
typedef long long ll;


struct ss
{
    ll prp,off_on;
}tree[410000];

ll arr[110000];


void form(ll lo,ll hi,ll node)
{
    if(lo==hi){
        tree[node].prp=0;
        tree[node].off_on=arr[lo];
        return;
    }
    form(lo,(lo+hi)/2,node*2);
    form(1+((lo+hi)/2),hi,1+(node*2));
    tree[node].prp=0;
    return;
}

void update(ll lo,ll hi,ll node,ll x,ll y)
{
    if(hi<x || lo>y)
        return;
    if(lo>=x && hi<=y)
    {
        tree[node].prp=(tree[node].prp+1)%2;
        return;
    }
    update(lo,(lo+hi)/2,node*2,x,y);
    update(1+((lo+hi)/2),hi,1+(node*2),x,y);
    return;
}

ll qry(ll lo,ll hi,ll node,ll pos,ll carry)
{
    if(hi<pos)
        return 0;
    if(pos<lo)
        return 0;
    if(lo==pos && hi==pos)
        return (tree[node].off_on+carry)%2;
    return qry(lo,(lo+hi)/2,node*2,pos,carry+tree[node].prp)+qry(1+((lo+hi)/2),hi,(node*2)+1,pos,carry+tree[node].prp);
}

int main()
{
    ll test,t,i,n,q,a,b,x,j;

    string s;
    in(test);
    char c;
    for(t=1;t<=test;t++)
    {
        getchar();
        cin>>s;
        n=s.length();
        for(i=0;i<n;i++)
            arr[i]=s[i]-'0';
        form(0,n-1,1);;
        in(q);
        for(i=1;i<=q;i++)
        {
            getchar();
            scanf("%c",&c);
            if(c=='I')
            {
                in(a),in(b);
                update(0,n-1,1,a-1,b-1);

                for(j=1;j<=n*4;j++)
                    pf("%lld ",tree[j]);
                pf("\n");
            }
            else
            {
                in(a);
                x=qry(0,n-1,1,a-1,0);
                pf("X = %lld ans  = %lld\n",x,x%2);
            }
        }
    }
}
