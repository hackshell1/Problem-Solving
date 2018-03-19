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
    ll p,q,w;
};

ll dp[101][10001],n;
ss arr[101];

ll call(ll pos,ll ww)
{
    if(pos==n)
        return 0;
    if(ww==0)
        return 0;
    if(dp[pos][ww]!=-1)
        return dp[pos][ww];
    ll p=0;

    if(ww-arr[pos].w>=0)
        p=call(pos,ww-arr[pos].w)+arr[pos].p;
    p=max(call(pos+1,ww),p);
    return dp[pos][ww]=p;
}

int main()
{
    ll test,i,p,W,a,b,c;
    in(test);
    mm(dp,-1);
    for(ll t=1;t<=test;t++)
    {
        in(n),in(W);
        for(i=0;i<n;i++)
        {
            in(a),in(b),in(c);
            arr[i].p=a;
            arr[i].q=b;
            arr[i].w=c;
            W=W-(c*b);
        }
        if(W<0)
            pf("Case %lld: Impossible\n",t);
        else
        {
            mm(dp,-1);
            pf("Case %lld: %lld\n",t,call(0,W));
        }
    }
    return 0;
}
