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
    ll node,cost;
    ss(ll a,ll b)
    {
        node=a;
        cost=b;
    }
};

bool sss[505];
ll dp[505][505],vis[505],n,t;
vector<ss>v[505];

ll call(ll pos,ll last)
{
    //pf("pos = %lld last = %lld\n",pos,last);
    if(pos==n)
    {
        dp[pos][last]=0;
        return 0;
    }
    if(dp[pos][last]!=-1)
        return dp[pos][last];
    ll i,sz,x,p=-1e10;
    sz=v[pos].size();
    for(i=0;i<sz;i++)
    {
        x=v[pos][i].node;
        if(x!=last)
            p=max(p,call(x,pos)+(sss[x]==true?1:0));
    }
    return dp[pos][last]=p;
}

ll findd(ll pos,ll last,ll x,ll sum)
{
    if(pos==n)
        return 0;
    ll sz,i,minn=1e10;
    sz=v[pos].size();
    for(i=0;i<sz;i++)
    {
        ll a=v[pos][i].node;
        if(a!=last && dp[a][pos]>=0 && dp[a][pos]==x || dp[a][pos]==x-1)
            minn=min(minn,findd(a,pos,dp[a][pos],sum+v[pos][i].cost)+v[pos][i].cost);
    }
    return minn;
}

int main()
{
    ll i,test,m,s,a,b,c,p,q;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(m),in(s);
        memset(sss,false,sizeof sss);
        for(i=0;i<s;i++)
        {
            in(a);
            a++;
            sss[a]=true;
        }
        for(i=1;i<=m;i++)
        {
            in(a),in(b),in(c);
            a++;
            b++;
            v[a].pb(ss(b,c));
        }
        mm(dp,-1);
        p=call(1,0)+(sss[1]==true?1:0);
        /*for(i=1;i<=n;i++)
        {
            for(ll j=0;j<=n;j++)
                pf("%3lld ",dp[i][j]);
            pf("\n");
        }*/
        mm(vis,-1);
        q=findd(1,0,p-(sss[1]==true?1:0),0);
        if(p<0)
            pf("Case %lld: Impossible\n",t);
        else
            pf("Case %lld: %lld %lld\n",t,p,q);

        for(i=1;i<=n;i++)
            v[i].cl;
    }
    return 0;
}
/*
2
4 4 4
0 1 2 3
0 1 10
1 3 30
0 2 30
2 3 5
4 4 4
0 1 2 3
0 1 10
3 1 30
0 2 30
3 2 5
*/
