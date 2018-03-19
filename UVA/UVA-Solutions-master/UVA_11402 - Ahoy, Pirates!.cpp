#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
#define sf scanf
#define mid (lo+hi)/2
#define lft node*2
#define rgt 1+lft

using namespace std;
typedef long long ll;

struct ss
{
    ll prp,sum;
}tree[4000000];

string s1,s2;

void form(ll lo,ll hi,ll node)
{
    tree[node].prp=-1;
    tree[node].sum=0;
    if(lo==hi)
    {
        if(s2[lo]=='1')
            tree[node].sum=1;
        return;
    }
    form(lo,mid,lft);
    form(mid+1,hi,rgt);
    tree[node].sum=tree[lft].sum+tree[rgt].sum;
    return;
}


ll update(ll lo,ll hi,ll node,ll x,ll y,ll p)
{
    if(tree[node].prp!=-1)
    {
        if(tree[node].prp==2)
            tree[node].sum=(hi-lo+1)-tree[node].sum;
        else
            tree[node].sum=(hi-lo+1)*tree[node].prp;

        if(lo!=hi)
        {
            if(tree[node].prp==2)
            {
                if(tree[lft].prp==1)
                    tree[lft].prp=0;
                else if(tree[lft].prp==0)
                    tree[lft].prp=1;
                else if(tree[lft].prp==2)
                    tree[lft].prp=-1;
                else if(tree[lft].prp==-1)
                    tree[lft].prp=2;

                if(tree[rgt].prp==1)
                    tree[rgt].prp=0;
                else if(tree[rgt].prp==0)
                    tree[rgt].prp=1;
                else if(tree[rgt].prp==2)
                    tree[rgt].prp=-1;
                else if(tree[rgt].prp==-1)
                    tree[rgt].prp=2;
            }
            else
                tree[lft].prp=tree[rgt].prp=tree[node].prp;
        }
        tree[node].prp=-1;
    }
    if(lo>y || hi<x)
        return tree[node].sum;
    if(lo>=x && hi<=y)
    {
        tree[node].prp=-1;
        if(p==0 || p==1)
            tree[node].sum=(hi-lo+1)*p;
        else
            tree[node].sum=(hi-lo+1-tree[node].sum);
       if(lo!=hi)
       {
            if(p==2)
            {
                if(tree[lft].prp==1)
                    tree[lft].prp=0;
                else if(tree[lft].prp==0)
                    tree[lft].prp=1;
                else if(tree[lft].prp==2)
                    tree[lft].prp=-1;
                else if(tree[lft].prp=-1)
                    tree[lft].prp=2;

                if(tree[rgt].prp==1)
                    tree[rgt].prp=0;
                else if(tree[rgt].prp==0)
                    tree[rgt].prp=1;
                else if(tree[rgt].prp==2)
                    tree[rgt].prp=-1;
                else if(tree[rgt].prp=-1)
                    tree[rgt].prp=2;
            }
            else
                tree[lft].prp=tree[rgt].prp=p;
       }
        return tree[node].sum;
    }
    return tree[node].sum=update(lo,mid,lft,x,y,p)+update(1+mid,hi,rgt,x,y,p);
}

ll qry(ll lo,ll hi,ll node,ll x,ll y)
{
    if(tree[node].prp!=-1)
    {
        if(tree[node].prp==0)
            tree[node].sum=0;
        else if(tree[node].prp==1)
            tree[node].sum=(hi-lo+1)*tree[node].prp;
        else if(tree[node].prp==2)
            tree[node].sum=(hi-lo+1)-tree[node].sum;

        if(lo!=hi)
        {
            if(tree[node].prp==2)
            {
                if(tree[lft].prp==1)
                    tree[lft].prp=0;
                else if(tree[lft].prp==0)
                    tree[lft].prp=1;
                else if(tree[lft].prp==2)
                    tree[lft].prp=-1;
                else if(tree[lft].prp==-1)
                    tree[lft].prp=2;

                if(tree[rgt].prp==1)
                    tree[rgt].prp=0;
                else if(tree[rgt].prp==0)
                    tree[rgt].prp=1;
                else if(tree[rgt].prp==2)
                    tree[rgt].prp=-1;
                else if(tree[rgt].prp==-1)
                    tree[rgt].prp=2;
            }
            else
                tree[lft].prp=tree[rgt].prp=tree[node].prp;
        }
        tree[node].prp=-1;
    }
    if(lo>y || hi<x)
        return 0;
    if(lo>=x && hi<=y)
        return tree[node].sum;
    return qry(lo,mid,lft,x,y)+qry(1+mid,hi,rgt,x,y);
}

int main()
{
    ll test,t,i,j,a,x,n,q,b,qs=0;
    char c;
    //freopen("out.txt","w",stdout);
    in(test);
    for(t=1;t<=test;t++)
    {
        qs=0;
        pf("Case %lld:\n",t);
        in(x);
        for(i=1;i<=x;i++)
        {
            in(a);
            cin>>s1;
            for(j=1;j<=a;j++)
                s2+=s1;
        }
        n=s2.length();
        form(0,n-1,1);
        //pf("After form %lld\n",tree[1].sum);
        in(q);
        for(i=1;i<=q;i++)
        {
            getchar();
            sf("%c%lld%lld",&c,&a,&b);
            if(c=='F')
                update(0,n-1,1,a,b,1);
            else if(c=='E')
                update(0,n-1,1,a,b,0);
            else if(c=='I')
                update(0,n-1,1,a,b,2);
            else
            {
                qs++;
                x=qry(0,n-1,1,a,b);
                pf("Q%lld: %lld\n",qs,x);
            }
            //pf("Now ans = %lld\n",tree[1].sum);
        }
        s1.clear();
        s2.clear();
        s1="\0";
        s2="\0";
    }
    return 0;
}
