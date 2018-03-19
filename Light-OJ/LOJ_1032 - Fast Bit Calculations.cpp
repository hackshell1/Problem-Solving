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

ll arr[40],len,dp[40][3][3][40];

void makebin(ll a)
{
    ll i,cnt=log2(a);
    for(i=cnt;i>=0;i--)
    {
        arr[i]=a%2;
        a=a/2;
    }
}

ll call(ll pos,ll small_or_eql,ll last,ll taken)
{
    if(pos>=len)
        return taken;

    if(dp[pos][small_or_eql][last][taken]!=-1)
        return dp[pos][small_or_eql][last][taken];


    ll p=0,start=0,endd=1,i;

    if(small_or_eql==1)
        endd=arr[pos];

    for(i=0;i<=endd;i++)
    {
        ll next_smaller_eq=0,next_taken=taken,add=0;

        if(i==endd && small_or_eql==1)
            next_smaller_eq=1;

        if(last==1 && i==1)
            next_taken=taken+1;
        if(last==1 && i==1)
            add=1;


        p+=call(pos+1,next_smaller_eq,i,next_taken);
    }
    return dp[pos][small_or_eql][last][taken]=p;
}

int main()
{
    ll test,t,i,n,p;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n);
        len=log2(n)+1;
        makebin(n);
        mm(dp,-1);
        p=call(0,1,0,0);
        pf("Case %lld: %lld\n",t,p);
    }
    return 0;
}
