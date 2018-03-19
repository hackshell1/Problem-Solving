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

S s1,s2,s3;
ll len1,len2,len3,dp[60][60][60];

ll call(ll i,ll j,ll k)
{
    if(i==len1 || j==len2 || k==len3)
        return 0;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];

    ll p=0;
    if(s1[i]==s2[j] && s2[j]==s3[k])
        p=call(i+1,j+1,k+1)+1;
    else
        p=max(call(i+1,j,k),call(i,j+1,k),call(i,j,k+1),call(i+1,j+1,k),max(call(i,j+1,k+1),call(i+1,j,k+1)));
    return dp[i][j][k]=p;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>s1>>s2>>s3;
        len1=s1.length();
        len2=s2.length();
        len3=s3.length();
        mm(dp,-1);
        p=call(0,0,0);
        pf("Case %lld: %lld\n",t,p);
    }
    return 0;
}
