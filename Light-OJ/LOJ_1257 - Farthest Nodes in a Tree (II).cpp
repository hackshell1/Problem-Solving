#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<cassert>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<vector>
#include<string>
#include<bitset>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define pi acos(-1.0)
#define in(a) scanf("%lld",&a)
#define FOR(a,b,c) for(a=b;a<=c;a++)
#define ROF(a,b,c) for(a=c;a>=1;a--)
#define For(a,b,c) for(a=b;a<c;a++)
#define roF(a,b,c) for(a=c-1;a>=0;a--)
#define mm(arr,x) memset(arr,x,sizeof(arr))
#define pf printf
#define fin freopen("in.txt","r",stdin)
#define fout freopen("out.txt","w",stdout)
#define pb push_back
#define sq(x) ((x)*(x))
#define Sqrt(n) (long long)round(sqrt((double)n))
#define logg(x,y) (double)log(y)/(double)log(x)
#define cl clear()


using namespace std;
typedef long long ll;

ll parent[30005],vis[30005],n,parent_pos[30005],cost[30005],total_cost;

struct ss
{
    ll a,b;
    ss(ll x,ll y)
    {
        a=x;
        b=y;
    }
};

vector<ll>v[30005],V[30005],needed;

ll bfs(ll a)
{
    queue<ll>q;
    mm(vis,-1);
    mm(parent,-1);
    mm(parent_pos,-1);
    q.push(a);
    vis[a]=0;
    ll x,i;
    ll maxx=0,max_node=-1,sz,y;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        sz=v[x].size();
        for(i=0;i<sz;i++)
        {
            y=v[x][i];
            if(vis[y]==-1)
            {
                q.push(y);
                vis[y]=vis[x]+V[x][i];
                parent[y]=x;
                parent_pos[y]=i;
                if(vis[y]>maxx)
                {
                    maxx=vis[y];
                    max_node=y;
                }
            }
        }
    }
    total_cost=maxx;
    return max_node;
}

void dfs(ll node,ll costt)
{
    cost[node]=costt;
    ll sz=v[node].size(),i,x;
    for(i=0;i<sz;i++)
    {
        ll x=v[node][i];
        if(cost[x]==-1)
            dfs(x,V[node][i]+costt);
    }
}


int main()
{
    ll i,j,k,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    //fout;
    in(test);
    for(t=1;t<=test;t++)
    {
        pf("Case %lld:\n",t);
        in(n);
        mm(cost,-1);
        for(i=1;i<=n-1;i++)
        {
            in(a),in(b),in(c);
            v[a].pb(b);
            v[b].pb(a);
            V[a].pb(c);
            V[b].pb(c);
        }
        x=bfs(0);
        y=bfs(x);
        ll rr=y,lenth=0;
        while(rr!=-1)
        {
            needed.pb(rr);
            lenth++;
            rr=parent[rr];
        }
        rr=y;
        cost[y]=total_cost;
        ll last_cost=0;
        cost[needed[0]]=total_cost;
        for(i=1;i<lenth;i++)
        {
            x=needed[i];
            y=needed[i-1];
            cost[x]=max(total_cost-last_cost-V[x][parent_pos[y]],last_cost+V[x][parent_pos[y]]);
            last_cost+=V[x][parent_pos[y]];
        }

        while(rr!=-1)
        {
            ll sz=v[rr].size();
            if(sz>2)
            {
                for(i=0;i<sz;i++)
                {
                    x=v[rr][i];
                    if(cost[x]==-1)
                        dfs(x,V[rr][i]+cost[rr]);
                }
            }
            rr=parent[rr];
        }
        for(i=0;i<n;i++)
            pf("%lld\n",cost[i]);
        for(i=0;i<n;i++)
        {
            V[i].cl;
            v[i].cl;
        }
        needed.cl;
    }
    return 0;
}
