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

ll arr[100005],dp[100005],n;

ll call(ll pos,ll k)
{
    if(pos>=n)
        return 0;
    if(dp[pos]!=-1)
        return dp[pos];
    ll p=1e10,i=pos+2;

    while(ceil((arr[i]-arr[pos]+0.0)/(2.0))<=k && i<n)
    {
        p=min(p,call(i+1,k)+1);
        i++;
    }
    return dp[pos]=p;
}

int main()
{
    ll test,t,k,i,cnt=0,a,b,j,p;
    //fin;
    //fout;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(k);
        for(i=0;i<n;i++)
            in(arr[i]);
        sort(arr,arr+n);
        mm(dp,-1);
        p=call(0,k);
        if(p>=1e10)
            pf("Case %lld: -1\n",t);
        else
            pf("Case %lld: %lld\n",t,p);
    }
    return 0;
}
