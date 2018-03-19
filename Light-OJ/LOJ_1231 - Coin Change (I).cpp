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
#define mod 100000007
#define mid (lo+hi)/2
#define LEFT node*2
#define RIGHT (node*2)+1


using namespace std;
typedef long long ll;
typedef string S;
typedef double D;

ll dp[51][1005],vis[51][1005],arr[10005],aee[1005];

ll call(ll pos,ll taken,ll n)
{
    //pf("Taken = %lld\n",taken);
    if(taken<0)
        return 0;

    if(pos==n)
    {
        if(taken==0)
            return 1;
        return 0;
    }

    if(taken==0)
        return 1;

    if(dp[pos][taken]!=-1)
        return dp[pos][taken];

    ll p=0,q=0,i;

    for(i=0;i<=aee[pos];i++)
    {
        q=call(pos+1,taken-(arr[pos]*i),n);
        p=((p%mod)+(q%mod))%mod;
    }

    return dp[pos][taken]=p%mod;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;

    in(test);
    fout;

    for(t=1;t<=test;t++)
    {
        in(n),in(k);
        for(i=0;i<n;i++)
            in(arr[i]);

        for(i=0;i<n;i++)
            in(aee[i]);

        mm(dp,-1);
        pf("Case %lld: %lld\n",t,call(0,k,n));
    }
    return 0;
}
