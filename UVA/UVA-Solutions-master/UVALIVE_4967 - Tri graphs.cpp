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
    return min(a,min(b,c));
}

ll min(ll a,ll b,ll c,ll d)
{
    return min(min(a,b,c),d);
}


ll arr[300010],dp[300009];

ll call(ll pos,ll last)
{
    if(pos==last)
        return arr[pos];
    if(pos>last)
        return 1e15;
    if(dp[pos]!=-1)
        return dp[pos];
    ll p=1e15;
    if(pos%3==1)
        return dp[pos]=min(call(pos+1,last),call(pos+3,last),call(pos+4,last))+arr[pos];
    if(pos%3==2)
        return dp[pos]=min(call(pos+1,last),call(pos+2,last),call(pos+3,last),call(pos+4,last))+arr[pos];
    if(pos%3==0)
        return dp[pos]=min(call(pos+2,last),call(pos+3,last))+arr[pos];
}

int main()
{
    ll n,tst=1;
    while(in(n))
    {
        if(n==0)
            return 0;
        ll cnt=1;
        mm(dp,-1);
        for(ll i=1;i<=n*3;i++)
            in(arr[i]);
        ll p=call(2,(n*3)-1);
        pf("%lld. %lld\n",tst++,p);
    }
    return 0;
}
