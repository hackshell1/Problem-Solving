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

ll vis[100005],sum;
vector<ll>v[100005];

struct ss
{
    ll left,right,total;
};

ll dfs(ll node)
{
    vis[node]=1;
    ll i,j,sz=v[node].size(),cnt=0;
    vector<ll>summ,summation;
    for(i=0;i<sz;i++)
    {
        ll x=v[node][i];
        ll p=0;
        if(vis[x]==-1)
        {
            p=dfs(x);
            cnt+=p;
            summ.pb(p);
        }
    }

    if(sz>1)
    {
        sz=summ.size();
        summation.pb(summ[0]);
        for(ll i=1;i<sz;i++)
            summation.pb(summation[i-1]+summ[i]);
        for(ll i=0;i<sz-1;i++)
        {
            sum+=summ[i]*(summation[sz-1]-summation[i]);
        }
    }
    summ.cl;
    return cnt+1;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,c;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n);
        for(i=1;i<n;i++)
        {
            in(a),in(b);
            v[a].pb(b);
            v[b].pb(a);
        }
        sum=0;
        mm(vis,-1);
        c=dfs(1);
        pf("Case %lld: %lld %lld\n",t,n-1,sum);
        for(i=1;i<=n;i++)
            v[i].cl;
    }
    return 0;
}

