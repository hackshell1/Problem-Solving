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


#define inf 1<<30
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


using namespace std;
typedef long long ll;


struct ss
{
    ll a;
    ll b;
    ll cost;
    ss(ll x,ll y)
    {
        a=x;
        cost=y;
    }
    ss(ll x,ll y,ll z)
    {
        a=x;
        b=y;
        cost=z;
    }
};

struct comp {
    bool operator() (const ss l,ss r) {
        return l.cost<r.cost;
    }
};

bool compare(ss l,ss r)
{
    return l.cost>r.cost;
}

vector<ss>v[10005],vv[10005],V;
ll vis[10005],vis1[10005];


void dijkstra_1D(ll a,ll b,ll n)
{
    for(ll i=0;i<=n;i++)
        vis[i]=(1<<20);
    queue<ss>q;
    q.push(ss(a,0));
    vis[a]=0;

    while(q.size()>0)
    {
        a=q.front().a;
        ll c=q.front().cost;
        q.pop();
        ll sz=v[a].size();
        for(ll i=0;i<sz;i++)
        {
            ll x,y;
            x=v[a][i].a;
            y=v[a][i].cost;
            if(vis[x]>c+y)
            {
                vis[x]=c+y;
                q.push(ss(x,vis[x]));
            }
        }
    }
}

void dijkstra_1D1(ll a,ll b,ll n)
{
    for(ll i=0;i<=n;i++)
        vis1[i]=(1<<20);
    queue<ss>q;
    q.push(ss(a,0));
    vis1[a]=0;

    while(q.size()>0)
    {
        a=q.front().a;
        ll c=q.front().cost;
        q.pop();
        ll sz=vv[a].size();
        for(ll i=0;i<sz;i++)
        {
            ll x,y;
            x=vv[a][i].a;
            y=vv[a][i].cost;
            if(vis1[x]>c+y)
            {
                vis1[x]=c+y;
                q.push(ss(x,vis1[x]));
            }
        }
    }
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c,s;

    in(test);
    for(t=1;t<=test;t++)
    {
        ll tt;
        in(n),in(m),in(s),in(tt),in(p);
        for(i=1;i<=m;i++)
        {
            in(a),in(b),in(c);
            v[a].pb(ss(b,c));
            vv[b].pb(ss(a,c));
            V.pb(ss(a,b,c));
        }
        sort(V.begin(),V.begin()+m,compare);
        dijkstra_1D(s,tt,n);
        dijkstra_1D1(tt,s,n);

        pf("Case %lld: ",t);
        cnt=0;
        for(i=0;i<m;i++)
        {
            a=V[i].a;
            b=V[i].b;
            c=V[i].cost;
            if(vis[a]+vis1[b]+c<=p)
            {
                pf("%lld\n",c);
                cnt=1;
                break;
            }
        }
        if(cnt==0)
            pf("-1\n");
        for(i=0;i<=n;i++)
        {
            v[i].cl;
            vv[i].cl;
        }
        V.cl;
    }
    return 0;
}
