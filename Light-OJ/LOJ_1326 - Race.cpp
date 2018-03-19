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
typedef char C;

ll dp1[1005][1005],dp2[1005];

ll ncr(ll x,ll y)
{
    if(x==y)
        return 1;
    if(y==1)
        return x;
    if(dp1[x][y]!=-1)
        return dp1[x][y];
    return dp1[x][y]=((ncr(x-1,y-1)%10056)+(ncr(x-1,y)%10056))%10056;
}

ll call2(ll x)
{
    if(x<=1)
        return 1;
    if(dp2[x]!=-1)
        return dp2[x];
    ll i,p=0;
    for(i=1;i<=x;i++)
    {
        p=((p%10056)+(ncr(x,i)*call2(x-i))%10056)%10056;
        p=p%10056;
    }
    return dp2[x]=p%10056;
}

int main()
{
    ll i,j,n,p,test;
    mm(dp2,-1);
    mm(dp1,-1);
    //fout;
    for(i=1000;i>=1;i--)
        for(j=i;j>=1;j--)
            ncr(i,j);

    in(test);
    for(ll t=1;t<=test;t++)
    {
        in(n);
        p=call2(n);
        pf("Case %lld: %lld\n",t,p);
    }
    return 0;
}
