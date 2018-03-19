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

S s;
vector<ll>v[1005];

ll len,dp[1005],poss[10005];

void get1(ll pos)
{
    ll x=pos,y=pos;
    v[pos].pb(pos);
    x--;
    y++;
    while(1)
    {
        if(x<0 || y>=len || s[x]!=s[y])
            return;
        v[x].pb(y);
        x--;
        y++;
    }
}

void get2(ll x,ll y)
{
    v[x].pb(y);
    x--;
    y++;
    while(1)
    {
        if(x<0 || y>=len || s[x]!=s[y])
            return;
        v[x].pb(y);
        x--;
        y++;
    }
}

ll call(ll pos)
{
    if(pos>=len)
        return 0;
    if(dp[pos]!=-1)
        return dp[pos];
    ll p=inf,sz=v[pos].size();
    for(ll i=0;i<sz;i++)
    {
        p=min(p,call(v[pos][i]+1)+1);
    }
    return dp[pos]=p;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,sum=0,c;
    in(test);
    getchar();
    for(t=1;t<=test;t++)
    {
        cin>>s;
        len=s.length();
        mm(dp,-1);
        for(i=0;i<len;i++)
            get1(i);
        for(i=1;i<len;i++)
            if(s[i-1]==s[i])
                get2(i-1,i);
        //pf("Yes\n");
        p=call(0);
        //pf("P = %lld\n",p);
        pf("Case %lld: %lld\n",t,p);
        for(i=0;i<len;i++)
            v[i].cl;
    }
    return 0;
}

