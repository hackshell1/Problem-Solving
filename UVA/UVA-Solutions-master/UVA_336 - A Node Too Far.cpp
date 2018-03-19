#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
#define pb push_back

using namespace std;
typedef long long ll;

vector<ll>v,vv[10000];

ll findd(ll a,ll type)
{
    ll siz=v.size(),i,j;
    for(i=0;i<siz;i++)
        if(v[i]==a)
            return i;
    if(type==1)
    {
        v.push_back(a);
        return siz;
    }
    return -1;
}

ll bfs(ll a,ll b)
{
    ll cnt=1,vis[10005],siz=v.size(),lvl=0,i;
    for(i=0;i<=siz;i++)
        vis[i]=-1;

    queue<ll>q;

    q.push(a);
    vis[a]=0;

    while(q.size()>0)
    {
        ll u=q.front();
        q.pop();
        siz=vv[u].size();
        for(i=0;i<siz;i++)
        {
            ll V=vv[u][i];
            if(vis[V]==-1 && vis[u]<b)
            {
                q.push(V);
                vis[V]=vis[u]+1;
                cnt++;
            }
        }
    }
    siz=q.size();
    for(i=0;i<siz;i++)
        q.pop();
    return cnt;
}


int main()
{
    ll casee=0,test,t,i,j,a,b,x;
    //freopen("out.txt","w",stdout);
    while(in(test))
    {
        if(test==0)
            return 0;
        for(t=0;t<test;t++)
        {
            in(a);
            in(b);
            a=findd(a,1);
            b=findd(b,1);
            vv[a].pb(b);
            vv[b].pb(a);
        }
        ll s=v.size();
        while(in(a),in(b))
        {
            if(a==0 && b==0)
                break;
            ll A=a;
            a=findd(a,2);
            pf("Case %lld: ",++casee);
            if(a==-1)
                pf("0 nodes not reachable from node %lld with TTL = %lld.\n",A,b);
            else
            {
                x=bfs(a,b);
                pf("%lld nodes not reachable from node %lld with TTL = %lld.\n",s-x,A,b);
            }
        }
        ll siz=v.size();
        for(i=0;i<siz;i++)
            vv[i].clear();
        v.clear();
    }
    return 0;
}
