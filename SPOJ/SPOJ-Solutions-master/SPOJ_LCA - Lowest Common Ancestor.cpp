#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
#define pb push_back

using namespace std;
typedef long long ll;

vector<ll>v[1005];
ll n,degree[1005],depth[1005],parent[1005],sp[10][1005];

void dfs(ll root,ll lvl)
{
    depth[root]=lvl;
    ll siz=v[root].size();
    while(--siz>=0)dfs(v[root][siz],lvl+1);
    v[root].clear();
    return;
}

void st(ll root)
{
    ll lim,i,j;
    lim=log2(n)+1;
    for(i=1;i<=n;i++)
        if(i!=root)
            sp[0][i]=parent[i];
    for(i=1;i<=lim;i++)
    {
        for(j=1;j<=n;j++)
            if(sp[i-1][j]!=-1 && sp[i-1][sp[i-1][j]]!=-1)
                sp[i][j]=sp[i-1][sp[i-1][j]];
    }
    for(i=0;i<=lim;i++)
        sp[i][root]=-1;
    return;
}

ll qry(ll a,ll b)
{
    if(depth[a]>depth[b])
        swap(a,b);
    ll i,j,lim;
    //pf("Dep a = %lld   dep b = %lld\n",depth[a],depth[b]);
    if(depth[a]!=depth[b])
    {
        lim=log2(depth[b]-depth[a])+1;
        for(i=lim;i>=0;i--)
            if(sp[i][b]!=-1 && depth[sp[i][b]]>depth[a])
                b=sp[i][b];
        b=sp[0][b];
    }
    //pf("a = %lld b = %lld\b",a,b);
    if(a==b)
        return a;
    lim=log2(depth[a])+1;
    for(i=lim;i>=0;i--)
    {
        if(sp[i][a]!=-1 && sp[i][b]!=-1 && sp[i][a]!=sp[i][b])
        {
            a=sp[i][a];
            b=sp[i][b];
        }
    }
    return sp[0][a];
}


int main()
{
    ll test,t,i,j,a,how,root,q,b,maxx=0;
    //freopen("out.txt","w",stdout);
    in(test);
    for(t=1;t<=test;t++)
    {
        pf("Case %lld:\n",t);
        in(n);
        for(i=0;i<=n;i++)
            degree[i]=0;
        for(i=1;i<=n;i++){
            in(how);
            for(j=1;j<=how;j++){
                in(a);
                v[i].pb(a);
                maxx=max(maxx,i);
                maxx=max(maxx,a);
                degree[a]++;
                parent[a]=i;
            }
        }
        for(i=1;i<=n;i++)
            if(degree[i]==0)
            {
                root=i;
                break;
            }
        n=maxx;
        dfs(1,0),st(root);
        in(q);
        for(i=1;i<=q;i++)
        {
            in(a),in(b);
            pf("%lld\n",qry(a,b));
        }
        memset(sp,-1,sizeof(sp));
        memset(degree,0,sizeof(degree));
        memset(parent,0,sizeof(parent));
        memset(depth,0,sizeof(depth));
    }
    return 0;
}
