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
#define ps push
#define inf 1<<30


using namespace std;
typedef long long ll;


struct ss
{
    ll node;
    ll cost;
    bool taken;
    ss(ll x,ll y,bool z)
    {
        node=x;
        cost=y;
        taken=z;
    }
};

vector<ss>v[5005];

bool operator<(const ss& l, const ss& r) {
  return r.cost < l.cost;
}

ll vis[5005][3];

void sett(ll node,ll cost)
{
    if(vis[node][1]>cost && vis[node][1]>cost)
    {
        vis[node][2]=vis[node][1];
        vis[node][1]=cost;
        return;
    }
    if(vis[node][2]>cost && vis[node][1]<cost)
    {
        vis[node][2]=cost;
        return;
    }
}

ll dijkstra(ll a,ll b)
{
    ll i,j,k;
    for(i=0;i<=b;i++)
    {
        vis[i][1]=inf;
        vis[i][2]=inf;
    }
    priority_queue<ss>q;
    q.push(ss(a,0,false));
    vis[a][1]=inf;
    vis[a][1]=inf;
    while(!q.empty())
    {
        ll x=q.top().node;
        ll y=q.top().cost;
        bool z=q.top().taken;
        q.pop();

        ll sz=v[x].size();
        ll minn=inf;
        for(i=0;i<sz;i++)
            minn=min(minn,v[x][i].cost);

        for(i=0;i<sz;i++)
        {
            ll cost=y+v[x][i].cost;
            ll node=v[x][i].node;
            ll costt=cost+(2*minn);

            if(z==false)
            {
                if(vis[node][1]>cost || vis[node][2]>cost)
                {
                    sett(node,cost);
                    q.push(ss(node,cost,false));
                }
                if(vis[node][1]>costt || vis[node][2]>costt)
                {
                    sett(node,costt);
                    q.push(ss(node,costt,true));
                }
            }
            else
            {
                if(vis[node][1]>cost || vis[node][2]>cost)
                {
                    sett(node,cost);
                    q.push(ss(node,cost,false));
                }
            }
        }

    }
    return max(vis[b][1],vis[b][2]);
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;

    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(m);
        for(i=1;i<=m;i++)
        {
            in(a),in(b),in(c);
            v[a].pb(ss(b,c,false));
            v[b].pb(ss(a,c,false));
        }
        x=dijkstra(1,n);
        pf("Case %lld: %lld\n",t,x);
        for(i=0;i<=n;i++)
            v[i].cl;
    }
    return 0;
}
