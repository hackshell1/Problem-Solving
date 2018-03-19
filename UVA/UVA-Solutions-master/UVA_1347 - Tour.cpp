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
/*#define in(a,b) scanf("%lld %lld",&a,&b)
#define in(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define in(a,b,c,d) scanf("%lld %lld %lld %lld",&a,&b,&c,&d)*/
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


struct ss
{
    ll a,b;
}arr[1005];


bool comp(ss l,ss r)
{
    return l.a<r.a;
}

ll pdistance(ll x,ll y)
{
    ll x1=arr[x].a;
    ll y1=arr[x].b;
    ll x2=arr[y].a;
    ll y2=arr[y].b;
    return (ll)(sqrt(((x1-x2+0.0)*(x1-x2+0.0))+((y1-y2+0.0)*(y1-y2+0.0)))*10000);
}

ll min(ll a,ll b,ll c)
{
    return min(min(a,b),c);
}

ll dp[1005][1005];

ll call(ll posx,ll posy,ll n)
{
    /*
    if(n==3)
        return 0;
    */
    if(dp[posx][posy]!=-1)
        return dp[posx][posy];
    ll p=1e16;
    ll maxx=max(posx,posy)+1;
    //pf("maxx = %lld\n",maxx);
    if(maxx==n-1)
    {
        //pf("Ret = %lld\n",pdistance(posx,n-1)+pdistance(posy,n-1));
        return pdistance(posx,n-1)+pdistance(posy,n-1);
    }
    if(maxx<n)
        p=min(call(posx,maxx,n)+pdistance(posy,maxx),call(maxx,posy,n)+pdistance(posx,maxx),p);
    return dp[posx][posy]=p;
}


int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    string s,s1,s2;


    while(scanf("%lld",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            in(a),in(b);
            arr[i].a=a;
            arr[i].b=b;
        }
        sort(arr,arr+n,comp);
        mm(dp,-1);
        p=call(0,0,n)/*+pdistance(0,1)+pdistance(0,2)*/;
        pf("%0.2f\n",p/10000.00);
    }
}
