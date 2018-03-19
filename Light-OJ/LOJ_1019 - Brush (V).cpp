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
        b=y,c=z;
    }
};

struct comp {
    bool operator() (const ss l,ss r) {
        return l.c<r.c;
    }
};

bool operator<(ss l, ss r) {return l.c < r.c ? true : false;}

vector<ss>v[501];
ll vis[501];

ll dijkstra_1D(ll a,ll b,ll n)
{
    for(ll i=0;i<=n;i++)
        vis[i]=(1<<20);
    queue<ss>q;
    q.push(ss(a,0));
    vis[a]=0;

    //pf("a = %lld\n",a);
    while(q.size()>0)
    {
        a=q.front().b;
        ll c=q.front().c;
        //pf("A = %lld C = %lld\n",a,c);
        q.pop();
        ll sz=v[a].size();
        //pf("Siz = %lld..........\n",sz);
        for(ll i=0;i<sz;i++)
        {
            ll x,y;
            x=v[a][i].b;
            y=v[a][i].c;
            //system("pause");
            //pf("X = %lld\n",x);
            //pf("Now vis[x] = %lld and c+y = %lld\n",vis[x],c+y);
            if(vis[x]>c+y)
            {
                vis[x]=c+y;
                q.push(ss(x,vis[x]));
            }
        }
        //pf("%lld size\n",q.size());
    }
    return vis[b];
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
        x=dijkstra_1D(1,n,n);
        pf("Case %lld: ",t);
        if(x!=(1<<20))
            pf("%lld\n",x);
        else
            pf("Impossible\n");
        for(i=1;i<=n;i++)
            v[i].clear();
    }
    return 0;
}
