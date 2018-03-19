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

ll arr[1005],dp[201][11][21],n,d,m;

ll findd(ll val)
{
     val=val%d;
     if(val<0)
        return val=val+d;
     return val;
}

ll call(ll pos,ll taken,ll sum)
{
    if(taken==m)
    {
        if(sum==0)
            return 1;
        return 0;
    }
    if(pos>=n)
        return 0;
    if(dp[pos][taken][sum]!=-1)
        return dp[pos][taken][sum];

    ll p=0;
    p+=call(pos+1,taken+1,findd((sum+arr[pos])))+call(pos+1,taken,sum);
    return dp[pos][taken][sum]=p;
}


int main()
{
    ll i,j,t,p,q,test=0;
    //fout;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(q);
        for(i=0;i<n;i++)
            in(arr[i]);

        pf("Case %lld:\n",t);
        for(i=0;i<q;i++)
        {
            mm(dp,-1);
            in(d),in(m);
            p=call(0,0,0);
            pf("%lld\n",p);
        }
    }
    return 0;
}
