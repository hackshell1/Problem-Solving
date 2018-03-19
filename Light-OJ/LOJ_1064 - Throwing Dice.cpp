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

ll n,k,dp[26][2][155];

ll poww(ll x,ll n)
{
    ll sum=1,i;
    for(i=1;i<=n;i++)
        sum*=x;
    return sum;
}

ll gcd(ll a,ll b)
{
    while(1)
    {
        if(b%a==0)
            return a;
        if(a==1)
            return 1;
        ll x=a;
        a=b%a;
        b=x;
    }
    return 1;
}


void findd(ll p,ll x,ll k)   /// P = Number of way to be that event, X in the number of Dice, And K is the number of Summation of the faces of the Dice at least which should be.
{
    //pf("P = %lld N = %lld K = %lld\n",p,x,k);
    if(p==0 || x==0){
        pf("0\n");
        return;
    }
    else
    {
        ll cnt=1;
        while(1)
        {
            ll gc=gcd(p,6);
            if(gc==1)
                break;
            p=p/gc;
            cnt*=6/gc;
            x--;
            if(x==0)
                break;
        }
        while(x-->0)
            cnt*=6;
        if(p==1 && cnt==1)
        {
            pf("1\n");
            return;
        }
        pf("%lld/%lld\n",p,cnt);
    }
    return;
}

ll call(ll pos,ll grtr,ll need)
{
    if(pos==n)
    {
        if(grtr==1 || need>=k)
            return 1;
        return 0;
    }
    if(dp[pos][grtr][need]!=-1)
        return dp[pos][grtr][need];
    ll p=0,i,x;
    for(i=1;i<=6;i++)
    {
        x=need+i;
        p+=call(pos+1,(x>=k)|grtr,k==0?x:x%k);
    }
    return dp[pos][grtr][need]=p;
}

int main()
{
    ll test,t,p;
    //fout;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(k);
        /*if(t!=136)
            continue;
        pf("%lld %lld\n",n,k);*/
        if(n==0)
        {
            pf("Case %lld: 0\n",t);
            continue;
        }
        mm(dp,-1);
        p=call(0,0,0);
        pf("Case %lld: ",t);
        findd(p,n,k);
    }
    return 0;
}
