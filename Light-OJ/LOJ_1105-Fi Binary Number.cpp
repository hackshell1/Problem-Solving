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
#define LEFT node*2
#define RIGHT (node*2)+1

using namespace std;
typedef long long ll;
typedef string S;
typedef double D;

struct ss
{
    ll zero,one,sum;
}dp[50][2];

ll call(ll pos,ll last,ll len)
{
    if(pos>=len)
        return 1;
    if(dp[pos][last].sum!=-1)
        return dp[pos][last].sum;

    ss p;
    p.sum=-1;
    p.one=0;
    p.zero=0;


    if(last==1)
    {
        p.one=0;
        p.zero=call(pos+1,0,len);
        p.sum=p.zero;
        dp[pos][last]=p;
        return dp[pos][last].sum;
    }

    p.zero+=call(pos+1,0,len);
    p.one+=call(pos+1,1,len);
    p.sum=p.one+p.zero;
    dp[pos][last]=p;
    return dp[pos][last].sum;
}

ll arr[50];

ll findd(ll x)
{
    ll i;
    for(i=0;i<=44;i++)
        if(arr[i]==x)
            return i;
    return -1;
}



void explore(ll pos,ll n,ll start)
{
    if(pos>44)
        return;
    if(arr[pos]<=n)
    {
        pf("1");
        explore(pos+1,n-arr[pos],1);
    }
    else
    {
        if(start!=0)
            pf("0");
        explore(pos+1,n,start);
    }
}

int main()
{
    ll test,t,i,n,mid,j;
    for(i=0;i<=49;i++)
    {
        for(j=0;j<2;j++)
        {
            dp[i][j].one=0;
            dp[i][j].zero=0;
            dp[i][j].sum=-1;
        }
    }
    call(0,0,44);

    /*for(i=0;i<=44;i++)
    {
        for(j=0;j<2;j++)
            pf("%3lld %3lld %3lld, ",dp[i][j].sum,dp[i][j].zero,dp[i][j].one);
        pf("\n");
    }*/

    for(i=0;i<44;i++)
        arr[i]=dp[i][0].sum;
    arr[44]=1;

    /*for(i=0;i<=44;i++)
        pf("%lld\n",arr[i]);*/

    in(test);
    //fout;
    for(t=1;t<=test;t++)
    {
        in(n);
        pf("Case %lld: ",t);
        explore(0,n,0);
        pf("\n");
    }
    return 0;

}
