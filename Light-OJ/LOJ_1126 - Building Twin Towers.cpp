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

ll max(ll a,ll b,ll c)
{
    return max(max(a,b),c);
}

ll max(ll a,ll b,ll c,ll d)
{
    return max(max(a,b,c),d);
}

ll max(ll a,ll b,ll c,ll d,ll e)
{
    return max(max(a,b,c,d),e);
}

ll max(ll a,ll b,ll c,ll d,ll e,ll f)
{
    return max(max(a,b,c,d,e),f);
}

ll arr[51],dp[500001][2],n,t,vis[500001][2];

bool viss[51];

ll call(ll pos,ll need,ll yes_not,ll t)
{
    if(pos>=n)
    {
        if(need==0)
            return 0;
        return -1e8;
    }
    if(vis[need][yes_not]==t)
        return dp[need][yes_not];
    ll p=-1e8,mainVal,val;
    if(yes_not==1)
        mainVal=need-500000;
    else
        mainVal=need;
    p=max(p,call(pos+1,mainVal+arr[pos]<0?mainVal+arr[pos]+500000:mainVal+arr[pos],mainVal+arr[pos]<0?1:0,t)+arr[pos],call(pos+1,mainVal-arr[pos]<0?mainVal+500000-arr[pos]:mainVal-arr[pos],mainVal-arr[pos]<0?1:0,t),call(pos+1,need,yes_not,t));
    vis[need][yes_not]=t;
    return dp[need][yes_not]=p;
}

int main()
{
    ll test,i,p,cnt,sum;
    in(test);
    //fout;
    mm(vis,-1);
    for(t=1;t<=test;t++)
    {
        in(n);
        for(i=0;i<n;i++)
            in(arr[i]);
        p=call(0,0,0,t);
        pf("Case %lld: %lld\n",t,p);
    }
}
