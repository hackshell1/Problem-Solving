#include<bits/stdc++.h>
#define in(a) scanf("%d",&a)
#define pf printf
#define inf 100005

using namespace std;
typedef int ll;

struct ss
{
    ll a,b,c;
}aee[100100];

bool compare(ss l,ss r)
{
    return l.c<r.c;
}

vector<ss>v[100100];
ll n,N,dsu[100100],vis[100100],depth[100100],sp[30][100100],sp_max[30][100100];

ll find(ll a)
{
    if(dsu[a]==a)
        return a;
    return dsu[a]=find(dsu[a]);
}

ll disjoint(ll a,ll b)
{
    ll x,y;
    x=find(a);
    y=find(b);
    if(x==y)
        return 0;
    else{
        dsu[x]=dsu[y];
        return 1;
    }
}

void kruskal()
{
    ll cnt,i,x,y,p,j;
    cnt=0;
    i=0;
    while(cnt<n-1)
    {
        x=aee[i].a;
        y=aee[i].b;
        p=disjoint(x,y);

        /*pf("X = %d Y = %d and Dsu Returned %d and I = %d\n",x,y,p,i);
        for(j=1;j<=n;j++)
            pf("%d ",dsu[j]);
        pf("\n");*/

        if(p==1)
        {
            ss s;
            s.a=aee[i].b;
            s.b=aee[i].c;
            v[x].push_back(s);
            s.a=aee[i].a;
            s.b=aee[i].c;
            v[y].push_back(s);
            cnt++;
        }
        i++;
        if(i>=N)
            break;
    }
    return;
}

void dfs(ll root,ll lvl)
{
    if(vis[root]>=0)
        return;
    vis[root]=1;
    depth[root]=lvl;
    ll siz=v[root].size();
    while(siz!=0)
    {
        ll nxt_root=v[root][siz-1].a;
        if(vis[nxt_root]>-1){
            siz--;
            continue;
        }
        sp[0][nxt_root]=root;
        sp_max[0][nxt_root]=v[root][siz-1].b;
        dfs(nxt_root,lvl+1);
        siz--;
    }
    return;
}

void table()
{
    ll lim=log2(n),i,j,x,y;
    for(i=1;i<=lim;i++)
    {
        for(j=1;j<=n;j++)
        {
            x=sp[i-1][j];
            y=sp[i-1][x];
            if(x!=-1 && y!=-1)
            {
                sp[i][j]=y;
                sp_max[i][j]=max(sp_max[i-1][j],sp_max[i-1][x]);
            }
        }
    }
    return;
}
ll maxx;
void LCA(int a,int b)
{
    if(depth[a]>depth[b])
        swap(a,b);
    if(a==b)
    {
        maxx=-100005;
        return;
    }
    maxx=-inf;
    int lim,i,j;
    if(depth[b]>depth[a])
    {
        lim=floor(log2(depth[b]-depth[a]))+1;
        for(i=lim;i>=0;i--)
        {
            if(depth[sp[i][b]]>=depth[a] && sp[i][b]>0)
            {
                maxx=max(maxx,sp_max[i][b]);
                b=sp[i][b];
                if(depth[b]==depth[a])
                    break;
            }
        }
    }
    if(a==b)
        return;
    lim=floor(log2(depth[a]))+1;
    for(i=lim;i>=0;i--)
    {
        if(sp[i][a]!=sp[i][b] && sp[i][a]>0 && sp[i][b]>0)
        {
            maxx=max(maxx,sp_max[i][a]);
            maxx=max(maxx,sp_max[i][b]);
            a=sp[i][a];
            b=sp[i][b];
        }
    }
    if(a==b)
        return;
    maxx=max(maxx,sp_max[0][a]);
    maxx=max(maxx,sp_max[0][b]);
    return;
}
int main()
{
    ll test,t,i,j,a,b,c,qry;
    //freopen("out.txt","w",stdout);
    in(test);
    for(t=1;t<=test;t++)
    {
        pf("Case %d:\n",t);
        in(n),in(N);
        for(i=0;i<N;i++)
        {
            in(a),in(b),in(c);
            aee[i].a=a;
            aee[i].b=b;
            aee[i].c=c;
        }
        sort(aee,aee+N,compare);
        for(i=0;i<=n;i++)
            dsu[i]=i;
        kruskal();



        /*for(i=1;i<=n;i++)
        {
            for(j=0;j<v[i].size();j++)
            {
                pf("%d ==>> %d %d\n",i,v[i][j].a,v[i][j].b);
            }
        }
        pf("\n");*/


        for(i=0;i<=n+50;i++)
            vis[i]=-1;
        ll lim=log2(n);
        for(i=0;i<=lim;i++)
        {
            for(j=0;j<=n;j++)
            {
                depth[j]=0;
                sp[i][j]=-1;
                sp_max[i][j]=-inf;
            }
        }
        dfs(1,0);
        table();
        /*for(i=0;i<=lim;i++)
        {
            for(j=1;j<=n;j++)
                pf("%d ",sp_max[i][j]);
            pf("\n");
        }*/
        in(qry);
        for(i=0;i<qry;i++)
        {
            in(a),in(b);
            LCA(a,b);
            pf("%d\n",maxx);
        }
        for(i=0;i<=n;i++)
            v[i].clear();
    }
    return 0;
}
