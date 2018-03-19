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

ll chek[1005],n,t,dp[1005][3],vis[1005];
vector<ll>v[1005];

ll call(ll pos,ll last,ll yn)
{
    pf("Pos %lld last = %lld yn = %lld\n",pos,last,yn);
    vis[pos]=1;
    ll i,sz,ans,x;
    sz=v[pos].size();

    if(sz==1)
    {
        if(v[pos][0]==last)
        {
            if(yn==0)
                return 1;
            return 0;
        }
    }
    if(dp[pos][yn]!=-1)
        return dp[pos][yn];

    ans=0;
    if(yn==0)
    {
        ans=1;
        for(i=0;i<sz;i++)
        {
            x=v[pos][i];
            if(x==last)
                continue;
            ans+=call(x,pos,1);
        }
    }
    else
    {
        ll ans1=1,ans0=0;
        for(i=0;i<sz;i++)
        {
            x=v[pos][i];
            if(x==last)
                continue;
            ans1+=call(x,pos,1);
            ans0+=call(x,pos,0);
        }
        ans=min(ans0,ans1);
    }
    return dp[pos][yn]=ans;
}

ll dp1[1005][3][1005],taken;

ll call1(ll pos,ll last,ll yn)
{
    pf("Pos %lld last = %lld yn = %lld\n",pos,last,yn);
    vis[pos]=1;
    ll i,sz,ans,x;
    sz=v[pos].size();
    if(taken<=0)
        return -1e10;
    if(sz==1)
    {
        if(v[pos][0]==last)
        {
            if(yn==0)
            {
                if(taken>0)

            }
            return 0;
        }
    }
    if(dp1[pos][yn][taken]!=-1)
        return dp1[pos][yn][taken];

    ans=0;
    if(yn==0)
    {
        ans=1;
        for(i=0;i<sz;i++)
        {
            x=v[pos][i];
            if(x==last)
                continue;
            ans+=call(x,pos,1);
        }
    }
    else
    {
        ll ans1=1,ans0=0;
        for(i=0;i<sz;i++)
        {
            x=v[pos][i];
            if(x==last)
                continue;
            ans1+=call(x,pos,1);
            ans0+=call(x,pos,0);
        }
        ans=min(ans0,ans1);
    }
    return dp[pos][yn]=ans;
}

int main()
{
    ll test,m,i,a,b,p;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(m);
        mm(chek,0);
        for(i=1;i<=m;i++)
        {
            in(a),in(b);
            a++;
            b++;
            v[a].pb(b);
            v[b].pb(a);
            chek[a]++;
            chek[b]++;
        }
        mm(vis,-1);
        mm(dp,-1);
        p=0;
        for(i=1;i<=n;i++)
        {
            if(chek[i]==1 && vis[i]==-1)
                p+=call(i,0,1);
        }
        mm(dp1,-1);
        q=call1(1,0,1,p+1);
        pf("Case %lld: %lld\n",t,p);


        for(i=0;i<=n;i++)
            v[i].cl;
    }
}


/*

1
11 8

0 1
0 5
1 3
1 4
4 6
5 7
7 9
7 10


ans

Case 1: 4 2 6

*/
