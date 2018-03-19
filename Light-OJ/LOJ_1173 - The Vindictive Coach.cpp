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

ll dp_ncr[1001][1001],dp[1001][1001];

ll ncr(ll n,ll r)
{
    if(r==1)
        return n;
    if(n==r)
        return 1;
    if(dp_ncr[n][r]!=-1)
        return dp_ncr[n][r];
    return dp_ncr[n][r]=(ncr(n-1,r-1)%10056)+(ncr(n-1,r)%10056)%10056;
}

ll call(ll x,ll y)
{
    if(x==y)
        return 1;
    if(y==1)
        return x;
    if(dp[x][y]!=-1)
        return dp[x][y];
    ll p=0,i;
    for(i=1;i<=y;i++)
        p=((p%10056)+(call(y,i)%10056))%10056;

    ll r=ncr(x,y);
    if(r>=10056)
        r-=10056;
    p=p*r;
    if(p>=10056)
        p-=10056;
    return dp[x][y]=p%10056;
}

int main()
{

    ll test,n,i,j,sum,t;
    //fout;
    mm(dp_ncr,-1);
    mm(dp,-1);
    in(test);

    for(t=1;t<=test;t++)
    {
        sum=0;
        in(n);
        for(i=n;i>=1;i--)
            sum+=call(n,i);
        pf("Case %lld: %lld\n",t,sum);
    }
    return 0;
}
