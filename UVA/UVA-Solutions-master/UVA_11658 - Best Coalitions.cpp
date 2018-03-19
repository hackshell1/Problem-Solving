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

ll min(ll a,ll b,ll c)
{
    return min(min(a,b),c);
}

ll min(ll a,ll b,ll c,ll d)
{
    return min(min(a,b,c),d);
}

ll min(ll a,ll b,ll c,ll d,ll e)
{
    return min(min(a,b,c,d),e);
}

ll min(ll a,ll b,ll c,ll d,ll e,ll f)
{
    return min(min(a,b,c,d,e),f);
}

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

D arr[105];
ll n,k,taken;
D dp[101][10001];

D calculate(D total,D owner,D div)
{
    //pf("%lf %lf %lf and ans = %.2lf\n",total,owner,div,(100.0*owner)/total);
    return ((100.0*owner)/total);
}

D call(ll pos,ll taken,D percent)
{
    D p=0.0;
    if(pos>n)
    {
        if(percent+arr[k]>50.00){
            //pf("Pos = %lld Perce = %0.2lf And Taken = %lld %0.2f\n",pos,percent+arr[k],taken,arr[pos]);
            p =calculate(percent+arr[k],arr[k],taken+0.0);
            //pf("%0.2lf...........................................................................................\n",p);
            return p;
        }
        return 0;
    }
    ll per=(ll)(percent*100);
    if(dp[pos][per]!=-1.0)
        return dp[pos][per];
    if(pos==k)
        p=call(pos+1,taken,percent);
    else
        p=max(call(pos+1,taken+1,percent+arr[pos]),call(pos+1,taken,percent));
    return dp[pos][per]=p;
}

int main()
{
    ll i,j;
    //fout;
    while(in(n),in(k))
    {
        if(n==0 && k==0)
            return 0;
        for(i=1;i<=n;i++)
            scanf("%lf",&arr[i]);

        for(i=0;i<=100;i++)
            for(j=0;j<10000;j++)
                dp[i][j]=-1.00;

        D p=call(1,1,0);
        pf("%0.2lf\n",p);
        //pf("%0.2lf\n",max((D)(p/(1000000+0.0)),(arr[k]/100.0)));
    }
    return 0;
}
