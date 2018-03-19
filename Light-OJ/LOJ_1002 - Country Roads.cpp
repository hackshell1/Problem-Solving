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
#define inf 1<<25

using namespace std;
typedef long long ll;

struct ss
{
    ll b,c;
    ss(ll y,ll z)
    {
        b=y;
        c=z;
    }
};

bool operator<(const ss& l, const ss& r) {
  return r.c < l.c;
}

vector<ss>v[501];
ll vis[515];

ll dijkstra_1D(ll a,ll n)
{
    for(ll i=0;i<=n;i++)
        vis[i]=(1<<30);
    queue<ll>q;
    q.push(a);
    vis[a]=0;

    while(q.size()>0)
    {
        a=q.front();
        q.pop();
        ll sz=v[a].size();
        for(ll i=0;i<sz;i++)
        {
            ll x,y;
            x=v[a][i].b;
            y=v[a][i].c;
            if(vis[x]>max(vis[a],y))
            {
                vis[x]=max(vis[a],y);
                q.push(x);
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        if(vis[i]==(1<<30))
        {
            pf("Impossible\n");
            continue;
        }
        pf("%lld\n",vis[i]);
    }
    return 0;
}


int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c,pos;
    //fout;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(m);
        for(i=0;i<m;i++)
        {
            in(a),in(b),in(c);
            v[a].pb(ss(b,c));
            v[b].pb(ss(a,c));
        }
        in(x);
        pf("Case %lld:\n",t);
        x=dijkstra_1D(x,n);
        for(i=0;i<=n;i++)
            v[i].clear();
    }
    return 0;
}
