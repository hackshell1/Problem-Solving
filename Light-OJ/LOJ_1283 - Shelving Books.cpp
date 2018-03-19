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

ll t,n,arr[105],dp[101][101][101],vis[101][101][101];

ll call(ll pos,ll x,ll y,ll lastpos1,ll lastpos2)
{
    //pf("POs = %lld x = %lld y = %lld last1 = %lld last 2 = %lld\n",pos,x,y,arr[lastpos1],arr[lastpos2]);
    if(pos>n)
        return 0;

    if(vis[pos][lastpos1][lastpos2]==t)
        return dp[pos][lastpos1][lastpos2];
    ll p=0;
    if(arr[pos]>=arr[lastpos1] && arr[pos]<=arr[lastpos2])
        p=call(pos+1,x+1,y,pos,lastpos2)+1;
    if(arr[pos]<=arr[lastpos2] && arr[pos]>=arr[lastpos1])
        p=max(p,call(pos+1,x,y-1,lastpos1,pos)+1);
    p=max(p,call(pos+1,x,y,lastpos1,lastpos2));
    vis[pos][lastpos1][lastpos2]=t;
    return dp[pos][lastpos1][lastpos2]=p;
}

int main()
{
    ll test,i;

    in(test);
    for(t=1;t<=test;t++)
    {
        in(n);
        arr[0]=0;
        arr[n+1]=1000000000000;
        for(i=1;i<=n;i++)
            in(arr[i]);
        mm(dp,-1);
        ll p=call(1,1,n,0,n+1);
        pf("Case %lld: %lld\n",t,p);
    }
}
