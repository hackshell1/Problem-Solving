#include<bits/stdc++.h>
#define in(a) scanf("%d",&a)
#define pf printf
#define inf 100000000;

using namespace std;
typedef long long ll;
int n,depth[100110],sp[30][100110],sp_min[30][100110],sp_max[30][100110],vis[100110],maxx,minn;

struct ss
{
    int a,b;
};
vector<ss>v[100110];

void dfs(int root,int lvl)
{
    if(vis[root]!=-1)
        return;
    vis[root]=0;
    depth[root]=lvl;
    int siz=v[root].size(),x;
    while(siz>0)
    {
        x=v[root][siz-1].a;
        if(vis[x]!=-1){
            siz--;
            continue;
        }
        sp[0][x]=root;
        sp_min[0][x]=v[root][siz-1].b;
        sp_max[0][x]=sp_min[0][x];
        dfs(x,lvl+1);
        siz--;
    }
    return;
}

void Table()
{
    int lim=log2(n),i,j,x,y;
    for(i=1;i<=lim+1;i++)
    {
        for(j=1;j<=n;j++)
        {
            x=sp[i-1][j];
            y=sp[i-1][x];
            if(x!=-1 && y!=-1)
            {
                sp[i][j]=y;
                sp_min[i][j]=min(sp_min[i-1][j],sp_min[i-1][x]);
                sp_max[i][j]=max(sp_max[i-1][j],sp_max[i-1][x]);
            }
        }
    }
    return;
}

void LCA(int a,int b)
{
    if(depth[a]>depth[b])
        swap(a,b);
    if(a==b)
    {
        maxx=-100005;
        minn=100005;
        return;
    }
    maxx=-inf;
    minn=inf;
    int lim,i,j;
    if(depth[b]>depth[a])
    {
        lim=floor(log2(depth[b]-depth[a]));
        for(i=lim;i>=0;i--)
        {
            if(depth[sp[i][b]]>=depth[a] && sp[i][b]>0)
            {
                maxx=max(maxx,sp_max[i][b]);
                minn=min(minn,sp_min[i][b]);
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
            minn=min(minn,sp_min[i][a]);
            minn=min(minn,sp_min[i][b]);
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
    minn=min(minn,sp_min[0][a]);
    minn=min(minn,sp_min[0][b]);
    return;
}

int main()
{
    int test,t,i,j,lim,a,b,c,root,qry;
    //freopen("out.txt","w",stdout);
    in(test);
    for(t=1;t<=test;t++)
    {
        pf("Case %d:\n",t);
        in(n);

        for(i=0;i<=n;i++)
            vis[i]=-1;

        lim=log2(n);
        for(i=0;i<=lim+1;i++)
        {
            for(j=0;j<=n;j++)
            {
                sp[i][j]=-1;
                sp_min[i][j]=inf;
                sp_max[i][j]=-inf;
            }
        }
        ss s;
        for(i=1;i<=n-1;i++)
        {
            in(a),in(b),in(c);
            s.a=b;
            s.b=c;
            v[a].push_back(s);
            s.a=a;
            s.b=c;
            v[b].push_back(s);
        }

        dfs(1,0);
        Table();
        in(qry);
        for(i=1;i<=qry;i++)
        {
            in(a),in(b);
            LCA(a,b);
            pf("%d %d\n",minn,maxx);
        }
        for(i=0;i<=n;i++)
        {
            v[i].clear();
        }
    }
    return 0;
}
