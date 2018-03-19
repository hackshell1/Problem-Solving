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
#define inf 1<<20

using namespace std;
typedef long long ll;

struct ss
{
    ll a;
    ll cost;
    ll type;
    ll taken;
    ss(ll x,ll y,ll take,ll z)
    {
        a=x;
        cost=y;
        taken=take;
        type=z;
    }
};

bool operator<(const ss& l, const ss& r) {
  return r.cost < l.cost;
}


vector<ss>v[10005];
vector<ss>V;
ll vis[10005][15];

void dijkstra(ll a,ll b,ll d)
{
    ll i,j,k,minn=inf+1;

    for(i=0;i<=b+1;i++)
        for(j=0;j<=12;j++)
            vis[i][j]=inf;
    priority_queue<ss>q;

    vis[a][0]=0;
    q.push(ss(a,0,0,0));

    while(!q.empty())
    {
        ll x=q.top().a;
        ll y=q.top().cost;
        ll taken=q.top().taken;
        q.pop();
        ll sz=v[x].size();
        for(i=0;i<sz;i++)
        {
            ll xx=v[x][i].a;
            ll yy=v[x][i].cost+y;
            ll typee=v[x][i].type+taken;

            if(typee<=d && typee<=10)
            {
                if(vis[xx][typee]>yy)
                {
                    vis[xx][typee]=yy;
                    q.push(ss(xx,yy,typee,0));
                }
            }
        }
    }

    for(i=0;i<=10;i++)
        minn=min(minn,vis[b][i]);
    if(minn==inf || minn==inf+1)
        pf("Impossible\n");
    else
        pf("%lld\n",minn);
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c,d;
    //fout;
    in(test);
    for(t=1;t<=test;t++)
    {
        pf("Case %lld: ",t);
        in(n),in(m),in(k),in(d);
        for(i=0;i<m;i++)
        {
            in(a),in(b),in(c);
            v[a].pb(ss(b,c,0,0));
        }
        for(i=0;i<k;i++)
        {
            in(a),in(b),in(c);
            v[a].pb(ss(b,c,0,1));
        }
        dijkstra(0,n-1,d);
        V.cl;
        for(i=0;i<n;i++)
            v[i].cl;
    }
    return 0;
}

