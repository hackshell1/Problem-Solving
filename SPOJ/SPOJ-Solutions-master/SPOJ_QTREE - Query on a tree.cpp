#include<bits/stdtr1c++.h>
#define in(a) scanf("%lld",&a)
#define mm(arr,x) memset(arr,x,sizeof(arr))
#define pf printf
#define fout freopen("out.txt","w",stdout)
#define pb push_back
#define cl clear()
#define mid (lo+hi)/2
#define LEFT node*2
#define RIGHT (node*2)+1

using namespace std;
typedef long long ll;

struct ss
{
    ll node,cost,pos;
    ss(ll a,ll b,ll c)
    {
        node=a;
        cost=b;
        pos=c;
    }
};

vector<ss>v[10005];

ll level[10005],parent_sparse[15][10005],maxx[10005],colour[10005],crnt_clr,arr[10005];
ll new_pos_arr[10005],current_pos,poss[10005],chain_parent[10005];
ll vertices1[10005],vertices2[10005];
ll tree[10005*4];

ll dfs(ll root,ll lvl)
{
    level[root]=lvl;
    ll sz=v[root].size(),i,j,sum=0,maxxx=-1,pos=-1,x;
    for(i=0;i<sz;i++)
    {
        x=v[root][i].node;
        ll cost=v[root][i].cost;
        ll position=v[root][i].pos;
        if(level[x]!=-1)
            continue;
        arr[x]=cost;
        vertices1[position]=root;
        vertices2[position]=x;
        ll p=dfs(x,lvl+1);
        parent_sparse[1][x]=root;
        if(p>maxxx)
        {
            pos=x;
            maxxx=p;
        }
        sum+=p;
    }
    maxx[root]=pos;
    return sum+1;
}

void dfs1(ll node,ll clrr,ll par)
{
    colour[node]=clrr;
    chain_parent[node]=par;
    poss[node]=current_pos;
    new_pos_arr[current_pos]=node;
    current_pos++;
    ll i,j,k,sz=v[node].size();
    ll max_pos=maxx[node];

    if(max_pos!=-1)
        dfs1(max_pos,clrr,par);

    for(i=0;i<sz;i++)
    {
        ll u=v[node][i].node;
        if(u==max_pos)
            continue;
        if(colour[u]!=-1)
            continue;
        crnt_clr++;
        dfs1(u,crnt_clr,u);
    }
}

void sparse_table(ll n)
{
    ll lim=log2(n)+1,i,j,x,y;
    for(i=2;i<=lim;i++)
    {
        for(j=1;j<=n;j++)
        {
            x=parent_sparse[i-1][j];
            if(x!=-1)
            {
                y=parent_sparse[i-1][x];
                if(y!=-1)
                    parent_sparse[i][j]=y;
            }
        }
    }
}

ll form(ll node,ll lo,ll hi)
{
    if(lo>hi)
        swap(lo,hi);
    if(lo==hi) return tree[node]=arr[new_pos_arr[lo]];
    return tree[node]=max(form(LEFT,lo,mid),form(RIGHT,mid+1,hi));
}

ll qry(ll node,ll lo,ll hi,ll a,ll b)
{
    if(lo>hi)
        swap(lo,hi);
    if(hi<a || lo>b) return (1<<31);
    if(lo>=a && hi<=b) return tree[node];
    return max(qry(LEFT,lo,mid,a,b),qry(RIGHT,mid+1,hi,a,b));
}

ll update(ll node,ll lo,ll hi,ll pos,ll v)
{
    if(lo>hi)
        swap(lo,hi);
    if(hi<pos || lo>pos) return tree[node];
    if(lo==hi && lo==pos) return tree[node]=v;
    return tree[node]=max(update(LEFT,lo,mid,pos,v),update(RIGHT,mid+1,hi,pos,v));
}

ll do_it(ll a,ll b,ll n)
{
    ll ans=-1,x;
    if(level[a]>level[b])
        swap(a,b);
    while(1)
    {
        if(colour[a]==colour[b])
            return max(ans,qry(1,0,n-1,poss[a],poss[b]));

        x=chain_parent[b];
        ans=max(ans,qry(1,0,n-1,poss[x],poss[b]));
        b=parent_sparse[1][x];
    }
}


ll qry_lca(ll a,ll b,ll n)
{
    if(level[a]>level[b])
        swap(a,b);
    ll lim=log2(level[b]-level[a]+1)+1,i,aa,bb,x,y,ans=-1;


    aa=a,bb=b;
    if(level[a]<level[b])
    {
        for(i=lim;i>=0;i--)
        {
            x=parent_sparse[i][bb];
            if(x!=-1 && level[x]>=level[a]+1)
                bb=x;
        }
        ans=do_it(bb,b,n);
        bb=parent_sparse[1][bb];
        b=bb;
    }
    if(a==b)
        return ans;
    lim=log2(level[a])+1;
    aa=a;
    bb=b;
    for(i=lim;i>=0;i--)
    {
        x=parent_sparse[i][a];
        y=parent_sparse[i][b];
        if(x!=-1 && x!=y)
        {
            a=x;
            b=y;
        }
    }
    ans=max(max(ans,do_it(a,aa,n)),do_it(b,bb,n));
    return ans;
}

int main()
{
    ll i,j,k,n,m,x,t,y,p,q,a,b,test=0,len,sum=0,c;
    char s[10];
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n);
        mm(arr,0);
        for(i=1;i<=n-1;i++)
        {
            in(a),in(b),in(c);
            v[a].pb(ss(b,c,i));
            v[b].pb(ss(a,c,i));
        }

        mm(level,-1);
        mm(parent_sparse,-1);
        mm(maxx,-1);
        dfs(1,0);

        current_pos=0;
        crnt_clr=1;
        mm(colour,-1);
        mm(new_pos_arr,-1);
        dfs1(1,crnt_clr,1);

        sparse_table(n);
        form(1,0,n-1);

        while(1)
        {
            scanf("%s",s);
            ll len=strlen(s);
            if(len==5)
            {
                in(a),in(b);
                x=qry_lca(a,b,n);
                pf("%lld\n",x);
            }
            else if(len==6)
            {
                in(a),in(b);
                update(1,0,n-1,poss[vertices2[a]],b);
            }
            else
                break;
        }
        for(i=0;i<=n+2;i++)
            v[i].cl;
    }
    return 0;
}
