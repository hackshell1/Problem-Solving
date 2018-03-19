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
#define rep(i,a,b,c) for(i=a;i<=b;i+=c)
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
#define mod 1000000007
#define mid (lo+hi)/2
#define LEFT node*2
#define RIGHT (node*2)+1


using namespace std;
typedef long long ll;
typedef string S;
typedef double D;

struct ss
{
    ll dgr,indx;
    bool vstd;
    ss(ll x,ll a,bool y)
    {
        indx=x;
        dgr=a;
        vstd=y;
    }
};

bool operator<(const ss& l, const ss& r)
{
    if(r.dgr==l.dgr)
        return r.vstd<l.vstd;
    return r.dgr < l.dgr;
}

priority_queue<ss>q;
ll degree[1005],done[1005][1005];
bool vis[1005];
vector<ll>v[1005];

void do_minus(ll n)
{
    ll sz=v[n].size(),i;
    for(i=0;i<sz;i++)
    {
        ll x=v[n][i];
        if(done[n][x]==0){
            q.push(ss(x,--degree[x],false));
            done[n][x]=1;
        }
    }
}


ll call(ll n)
{
    ll a,b,c,dgr,indx,cnt=0;
    while(!q.empty())
    {
        indx=q.top().indx;
        dgr=q.top().dgr;
        q.pop();
        if(vis[indx]==true)
            continue;
        cnt++;
        ll sz=v[indx].size();
        vis[indx]=true;
        for(ll i=0;i<sz;i++)
        {
            ll x=v[indx][i];
            do_minus(x);
            vis[x]=true;
        }
    }
    return cnt;
}

int main()
{
    ll test,t,i,j,m,a,b,n,p;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(m);
        memset(vis,false, sizeof vis);
        memset(degree,0,sizeof degree);
        for(i=0;i<m;i++)
        {
            in(a),in(b);
            v[a].pb(b);
            v[b].pb(a);
            degree[a]++;
            degree[b]++;
        }

        for(i=1;i<=n;i++)
            q.push(ss(i,degree[i],false));
        mm(done,0);

        p=call(n);
        pf("Case %lld: %lld\n",t,p);
        for(i=0;i<=n;i++)
            v[i].cl;
    }
    return 0;

}
