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
#define cl clear()


using namespace std;
typedef long long ll;

vector<ll>V,v[105];
ll vis[105];

ll bfs1(ll a)
{
    queue<ll>q;
    ll x,y,i,sz,maxx=-1;
    mm(vis,-1);
    q.push(a);
    vis[a]=0;
    while(!q.empty())
    {
        ll cnt=0;
        x=q.front();
        q.pop();
        sz=v[x].size();
        for(i=0;i<sz;i++)
        {
            y=v[x][i];
            if(vis[y]==-1)
            {
                q.push(y);
                vis[y]=vis[x]+1;
                maxx=max(maxx,vis[y]);
                cnt++;
            }
        }
        if(cnt==0)
            V.pb(x);
    }
    return maxx;
}

ll bfs2(ll a,ll b)
{
    queue<ll>q;
    ll x,y,i,sz,viss[105],maxx=-1;
    mm(viss,-1);
    q.push(a);
    viss[a]=0;
    while(!q.empty())
    {
        ll cnt=0;
        x=q.front();
        q.pop();
        sz=v[x].size();
        for(i=0;i<sz;i++)
        {
            y=v[x][i];
            if(viss[y]==-1)
            {
                q.push(y);
                viss[y]=viss[x]+1;
                if(y==b)
                    return viss[y];
            }
        }
    }
    return 0;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,r;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(r);
        sum=0;
        for(i=0;i<r;i++)
        {
            in(a),in(b);
            v[a].pb(b);
            v[b].pb(a);
        }
        in(a),in(b);
        ll time=bfs1(a);
        ll sz=V.size();
        sum=0;
        for(i=0;i<sz;i++)
        {
            if(V[i]!=b)
            {
                x=bfs2(V[i],b);
                if(x-(time-vis[V[i]])>0)
                    sum=max(x-(time-vis[V[i]]),sum);
            }
        }
        sum+=time;
        for(i=0;i<n;i++)
            v[i].cl;
        V.cl;
        pf("Case %lld: %lld\n",t,sum<=0?0:sum);
    }
    return 0;
}
