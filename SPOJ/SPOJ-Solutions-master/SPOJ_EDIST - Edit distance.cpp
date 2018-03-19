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

#define inf 1<<29
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

char s2[2005],s1[2005],dp[2005][2005];
ll len1,len2;

ll call(ll posx,ll posy)
{
    if(posx<=0)
        return posy;
    if(posy<=0)
        return posx;
    if(dp[posx][posy]!=-1)
        return dp[posx][posy];
    ll p=inf;
    if(s1[posx-1]==s2[posy-1])
        p=call(posx-1,posy-1);
    else
    {
        p=min(call(posx,posy-1)+1,p);
        p=min(call(posx-1,posy-1)+1,p);
        p=min(call(posx-1,posy)+1,p);//del
    }
    //return p;
    return dp[posx][posy]=p;
}

int main()
{
    ll test,t,i,p;
    //fout;
    in(test);
    getchar();
    for(t=1;t<=test;t++)
    {
        scanf("%s%s",s1,s2);
        len1=strlen(s1);
        len2=strlen(s2);
        mm(dp,-1);
        p=call(len1,len2);
        pf("%lld\n",p);
    }
    return 0;
}
