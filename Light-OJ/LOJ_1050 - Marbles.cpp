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

ll dp[505][505];

ll call(ll red,ll blue)
{
    if(red==0 && blue==1)
        return 1;
    if(red!=0 && blue==0)
        return 0;
    if(red<0 || blue<0)
        return 0;
    if(dp[red][blue]!=-1)
        return dp[red][blue];
    ll p=0;
    p=call(red-1,blue)+call(red,blue-1);
    return dp[red][blue]=p;
}

ll dp1[505][505];

ll call1(ll red,ll blue)
{
    if(red==0 && blue==1)
        return 0;
    if(red!=0 && blue==0)
        return 0;
    if(red<0 || blue<0)
        return 1;
    if(dp1[red][blue]!=-1)
        return dp1[red][blue];
    ll p=0;
    p=call1(red-1,blue)+call(red,blue-1);
    return dp1[red][blue]=p;
}

int main()
{
    ll test,t,red,blue;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(red),in(blue);
        mm(dp,-1);
        ll p=call(red,blue);
        mm(dp1,-1);
        ll q=call1(red,blue);
        pf("P=  %lld Q = %lld\n",p,q);
    }
}
