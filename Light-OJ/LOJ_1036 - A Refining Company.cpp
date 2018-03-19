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

ll arr1[505][505],arr2[505][505],sum1[505][505],sum2[505][505],n,m,dp[505][505];

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

ll call(ll x,ll y)
{
    if(x<0 || y<0)
        return 0;
    if(dp[x][y]!=-1)
        return dp[x][y];

    ll p=-100000000000000;
    p=max(p,call(x-1,y)+sum1[x][y],call(x-1,y),call(x,y-1),call(x,y-1)+sum2[x][y],call(x-1,y-1));
    return dp[x][y]=p;
}

int main()
{
    ll test,t,i,j,p;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                in(arr1[i][j]);

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                in(arr2[i][j]);

        for(i=0;i<n;i++){
            sum1[i][0]=arr1[i][0];
            for(j=1;j<m;j++)
                sum1[i][j]=sum1[i][j-1]+arr1[i][j];
        }

        for(j=0;j<m;j++){
            sum2[0][j]=arr2[0][j];
            for(i=1;i<n;i++)
                sum2[i][j]=sum2[i-1][j]+arr2[i][j];
        }

        mm(dp,-1);
        p=call(n-1,m-1);
        pf("Case %lld: %lld\n",t,p);
    }
    return 0;
}
