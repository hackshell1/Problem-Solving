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

ll arr[1010],prime[1010];
vector<ll>factors[1010];

ll siv(ll n)
{
    ll i,j,sq;
    sq=sqrt(1005);
    mm(arr,0);
    for(i=4;i<1005;i+=2)
        arr[i]=1;

    for(i=3;i<=sq;i+=2)
        if(arr[i]==0)
            for(j=i*2;j<1005;j+=i)
                arr[j]=1;
    ll cnt=0;

    for(i=2;i<=1000;i++)
        if(arr[i]==0)
            prime[cnt++]=i;
    return cnt;
}

void factor_find(ll n,ll x)
{
    ll i,j;
    for(i=0;i<x;i++)
    {
        if(prime[i]>=n)
            return;
        if(n%prime[i]==0)
            factors[n].pb(prime[i]);
    }
    return;
}

ll bfs(ll a,ll b)
{
    if(a==b)
        return 0;
    ll vis[1005];
    mm(vis,-1);
    queue<ll>q;
    q.push(a);
    vis[a]=0;
    while(!q.empty())
    {
        ll x=q.front();
        q.pop();
        ll sz=factors[x].size();
        for(ll i=0;i<sz;i++)
        {
            ll y=x+factors[x][i];
            if(y<=b && vis[y]==-1)
            {
                q.push(y);
                vis[y]=vis[x]+1;
                if(b==y)
                    return vis[y];
            }
        }
    }
    return -1;
}

int main()
{
    ll test,x,t,i,j,a,b;
    x=siv(1003);
    for(i=4;i<=1005;i++)
        factor_find(i,x);
    //fout;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(a),in(b);
        ll x=bfs(a,b);
        pf("Case %lld: ",t);
        pf("%lld\n",x);
    }
    return 0;
}
