#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf

using namespace std;
typedef long long ll;

vector<ll>v[100005];
ll par[100005],cost[100005],depth[100005],n,sp_LCA[30][100005],sp_max[30][100005],inf=(1<<31)-1;

void dfs(ll root,ll lvl)
{
    depth[root]=lvl;
    ll siz=v[root].size();
    for(ll i=0;i<siz;i++)
        dfs(v[root][i],lvl+1);
    v[root].clear();
    return;
}

void sp()
{
    ll lim=log2(n),i,j;
    for(i=1;i<n;i++)
    {
        sp_LCA[0][i]=par[i];
        if(cost[i]<cost[par[i]])
            sp_max[0][i]=par[i];
        else
            sp_max[0][i]=i;
    }
    sp_LCA[0][0]=-inf;
    for(i=1;i<=lim;i++)
    {
        for(j=1;j<n;j++)
        {
            if(sp_LCA[i-1][j]!=-inf && sp_LCA[i-1][sp_LCA[i-1][j]]!=-inf)
            {
                sp_LCA[i][j]=sp_LCA[i-1][sp_LCA[i-1][j]];
                if(cost[sp_max[i-1][j]]<cost[sp_max[i-1][sp_LCA[i-1][j]]])
                    sp_max[i][j]=sp_max[i-1][sp_LCA[i-1][j]];
                else
                    sp_max[i][j]=sp_max[i-1][j];
            }
        }
    }
    return;
}

ll qry_max(ll a,ll b,ll dep)
{
    ll lim=log2(dep),pos=-inf;
    for(ll i=lim;i>=0;i--)
    {
        if(sp_max[i][a]!=-inf)
        {
            if(cost[sp_max[i][a]]>=b)
                pos=sp_max[i][a];
        }
    }
    return pos;
}

ll qry_LCA(ll a,ll x)
{
    ll lim=log2(depth[a]-x),i;
    for(i=lim;i>=0;i--)
    {
        if(depth[sp_LCA[i][a]]>x)
            a=sp_LCA[i][a];
    }
    a=sp_LCA[0][a];
    return a;
}

ll src(ll a,ll b)
{
    if(a==0)
        return 0;
    if(cost[0]>=b)
        return 0;

    ll lo=0,hi=a,mid,last_hi=hi,maxx=-inf;
    while(depth[hi]>depth[lo])
    {
        if(depth[hi]-depth[lo]<=3)
        {
            if(sp_max[0][lo]!=-inf)
            {
                if(cost[sp_max[0][lo]]>=b)
                    maxx=sp_max[0][lo];
            }

            for(ll i=0;i<depth[hi]-depth[lo]+1;i++)
            {
                if(sp_LCA[0][hi]==-inf)
                    return maxx;
                if(cost[sp_max[0][hi]]>=b)
                    maxx=sp_max[0][hi];
                hi=sp_LCA[0][hi];
            }
            return maxx;
        }
        mid=(depth[lo]+depth[hi])/2;
        ll qr_lca=qry_LCA(hi,mid);
        pf("lo  = %lld Hi = %lld  mid = %lld==>> %lld\n",lo,hi,mid,qr_lca);
        ll qr_max=qry_max(qr_lca,b,depth[qr_lca]);
        if(qr_max!=-inf && cost[sp_max[][]){
            last_hi=hi;
            hi=qr_lca;
            maxx=qr_max;
        }
        else
        {
            lo=hi;
            hi=last_hi;
        }
        if(lo==hi)
        {
            pf("Lo=%lld hi = %lld\n",lo,hi);
            if(sp_max[0][lo]!=-inf)
            {
                if(maxx==-inf)
                {
                    if(cost[sp_max[0][lo]]>=b)
                        return sp_max[0][lo];
                    return maxx;
                }
                if(maxx!=-inf)
                {
                    if(sp_max[0][lo]<maxx)
                    {
                        if(cost[sp_max[0][lo]]>=b)
                            return sp_max[0][lo];
                        return maxx;
                    }
                }
            }
        }
    }
    return maxx;
}

int main()
{
    ll test,t,i,q,a,b,lim,j;
    //freopen("out.txt","w",stdout);
    in(test);
    for(t=1;t<=test;t++)
    {
        pf("Case %lld:\n",t);
        in(n),in(q);
        for(i=1;i<n;i++)
        {
            in(a),in(b);
            v[a].push_back(i);
            par[i]=a;
            cost[i]=b;
        }

        dfs(0,0);
        cost[0]=1;

        ll lim=log2(n);
        for(i=0;i<=lim+1;i++)
            for(j=0;j<n;j++)
                sp_LCA[i][j]=sp_max[i][j]=-inf;
        sp();

        for(i=1;i<=q;i++)
        {
            in(a),in(b);
            ll x=src(a,b);
            pf("%lld\n",x);
        }


        /*for(i=0;i<=lim;i++)
        {
            for(j=0;j<n;j++)
                pf("%lld %lld   ",sp_LCA[i][j],sp_max[i][j]);
            pf("\n");
        }*/
    }
    return 0;
}
