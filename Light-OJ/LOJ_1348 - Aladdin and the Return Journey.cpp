#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define mm(arr,x) memset(arr,x,sizeof(arr))
#define pf printf
#define fin freopen("in.txt","r",stdin)
#define fout freopen("out.txt","w",stdout)
#define pb push_back
#define cl clear()
#define ps push
#define mid (lo+hi)/2
#define LEFT node*2
#define RIGHT (node*2)+1
#define nwln pf("\n")

using namespace std;
typedef long long ll;

ll arr[30005];
vector<ll>v[30050];

ll level[30500],maxx[30505],cnt,chain_number[30505],chain_parent[30505];
ll pos_in_new_arr[30505],poss[30505],current_pos;
ll parent_sparse[20][30505];
ll tree[30505*4];

ll dfs(ll root,ll lvl)
{
    level[root]=lvl;
    ll pos=-1,i,j,sz,p=-1,sum=0,maxxx=-1;
    sz=v[root].size();
    if(sz==0) return 1;
    for(i=0;i<sz;i++)
    {
        ll u=v[root][i];
        if(level[u]==-1)
        {
            parent_sparse[1][u]=root;
            p=dfs(u,lvl+1);
            if(p>maxxx)
            {
                maxxx=p;
                pos=u;
            }
            sum+=p;
        }
    }
    maxx[root]=pos;
    return sum+1;
}

void dfs1(ll parentt,ll node,ll numbering)
{
    chain_number[node]=numbering;
    chain_parent[node]=parentt;
    ll maxxx=maxx[node];
    pos_in_new_arr[node]=current_pos;
    poss[current_pos]=node;
    current_pos++;

    if(maxxx==-1)
        return;
    dfs1(parentt,maxxx,numbering);
    ll sz=v[node].size();
    for(ll i=0;i<sz;i++)
    {
        ll u=v[node][i];
        if(u==maxxx)
            continue;
        if(chain_number[u]==-1)
            dfs1(u,u,++cnt);
    }
    return;
}

void sparse_table(ll n)
{
    ll lim=log2(n)+1,i,j,x,y;
    for(i=2;i<=lim;i++)
    for(j=0;j<n;j++)
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

ll form(ll node,ll lo,ll hi)
{
    if(lo==hi) return tree[node]=arr[poss[lo]];
    return tree[node]=form(LEFT,lo,mid)+form(RIGHT,mid+1,hi);
}

ll qry(ll node,ll lo,ll hi,ll a,ll b)
{
    if(hi<a || b<lo) return 0;
    if(lo>=a && hi<=b) return tree[node];
    return qry(LEFT,lo,mid,a,b)+qry(RIGHT,mid+1,hi,a,b);
}

ll update(ll node,ll lo,ll hi,ll pos,ll v)
{
    if(hi<pos || pos<lo) return tree[node];
    if(lo==hi && lo==pos) return tree[node]=v;
    return tree[node]=update(LEFT,lo,mid,pos,v)+update(RIGHT,mid+1,hi,pos,v);
}

ll do_it(ll a,ll b,ll n)
{
    ll sum=0;
    if(level[a]>level[b])
        swap(a,b);
    while(1)
    {
        if(chain_number[a]==chain_number[b])
            return sum+=qry(1,0,n-1,pos_in_new_arr[a],pos_in_new_arr[b]);

        ll chain_par=chain_parent[b];
        sum+=qry(1,0,n-1,pos_in_new_arr[chain_par],pos_in_new_arr[b]);
        b=parent_sparse[1][chain_par];
    }
}

ll qry_lca(ll a,ll b,ll n)
{
    ll lim,i,j,aa=a,bb=b,sum=0,x,y;
    lim=log2(level[b]-level[a])+1;
    for(i=lim;i>=0;i--)
    {
        x=parent_sparse[i][bb];
        if(x!=-1 && level[x]>=level[a])
            bb=x;
    }
    sum+=do_it(bb,b,n);
    if(a==bb)
        return sum;
    sum-=arr[bb];
    b=bb;
    aa=a,bb=b;
    lim=log2(level[a])+1;
    for(i=lim;i>=0;i--)
    {
        x=parent_sparse[i][aa];
        y=parent_sparse[i][bb];
        if(x!=y && x!=-1)
        {
            aa=x;
            bb=y;
        }
    }
    sum+=do_it(aa,a,n)+do_it(bb,b,n);
    aa=parent_sparse[1][aa];
    sum+=arr[aa];
    return sum;
}

int main()
{
    ll i,j,k,n,m,x,t,y,p,q,a,b,test=0,c,qr;
    //fout;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n);
        for(i=0;i<n;i++)
            in(arr[i]);
        for(i=1;i<n;i++)
        {
            in(a),in(b);
            v[a].pb(b);
            v[b].pb(a);
        }
        mm(level,-1);
        mm(maxx,-1);
        mm(chain_number,-1);
        mm(parent_sparse,-1);
        mm(chain_parent,-1);

        dfs(0,0);
        cnt=1;
        current_pos=0;
        dfs1(0,0,cnt);

        sparse_table(n);
        form(1,0,n-1);

        in(qr);
        pf("Case %lld:\n",t);
        for(i=1;i<=qr;i++)
        {
            in(c),in(a),in(b);
            if(c==0)
            {
                if(level[a]>level[b])
                    swap(a,b);
                x=qry_lca(a,b,n);
                pf("%lld\n",x);
            }
            else
            {
                arr[a]=b;
                update(1,0,n-1,pos_in_new_arr[a],b);
            }
        }
        for(i=0;i<n+3;i++)
            v[i].cl;
    }
    return 0;
}
