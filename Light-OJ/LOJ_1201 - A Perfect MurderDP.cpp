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

vector<ll>v[1005];
ll vis[1005],dp[1005][1005];

ll call(ll curr,ll par)
{
    if(dp[curr][par]!=-1)
        return dp[curr][par];
    ll p=1,i,sz=v[curr].size();
    if(vis[curr]==1)
        p=0;
    vis[curr]=1;
    for(i=0;i<sz;i++)
    {
        ll x=v[curr][i];
        if(vis[x]==0 && x!=par){
            if(par[])
            p+=call(x,curr);
        }
    }
    dp[curr][par]=p;
}

int main()
{
    ll test,t,i,n,m,a,b,p;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(m);
        for(i=0;i<m;i++)
        {
            in(a),in(b);
            v[a].pb(b);
            v[b].pb(a);
        }
        mm(dp,-1);
        p=-1;
        for(i=1;i<=n;i++){
            mm(vis,0);
            p=max(call(i,0),p);
        }
        pf("Case %lld: %lld\n",t,p);
    }
}
