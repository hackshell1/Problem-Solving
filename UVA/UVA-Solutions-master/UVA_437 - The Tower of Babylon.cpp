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

struct ss
{
    ll x,y,z,dimension;
    ss(ll a,ll b,ll c,ll d)
    {
        x=a;
        y=b;
        z=c;
        dimension=d;
    }
};

bool comp(ss l,ss r)
{
    return l.dimension>r.dimension;
}


vector<ss>v;

void pushall(ll a,ll b,ll c)
{

    v.pb(ss(max(a,b),min(a,b),c,a*b));
    v.pb(ss(max(a,c),min(a,c),b,a*c));
    v.pb(ss(max(b,c),min(b,c),a,b*c));


    /*v.pb(ss(a,b,c,a*b));
    v.pb(ss(a,c,b,a*c));
    v.pb(ss(b,a,c,b*a));
    v.pb(ss(b,c,a,b*c));
    v.pb(ss(c,b,a,b*c));
    v.pb(ss(c,a,b,b*c));*/
}

ll dp[31*4],nn;

ll call(ll last)
{
    //pf("Last = %lld %lld %lld %lld\n",v[last].x,v[last].y,v[last].z,v[last].dimension);
    if(dp[last]!=-1)
       return dp[last];
    ll maxx=0;
    for(ll i=last+1;i<nn;i++)
    {
        if(v[last].dimension>v[i].dimension)
        {
            if(v[i].x<v[last].x && v[i].y<v[last].y)
            {
                //pf("Now nitese Last = %lld %lld %lld %lld\n",v[i].x,v[i].y,v[i].z,v[i].z);
                maxx=max(call(i)+v[i].z,maxx);
            }
        }
    }
    //pf("Ret %lld\n",maxx);
    return dp[last]=maxx;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c,sz;
    string s,s1,s2;
    test=0;
    //fout;
    while(in(n))
    {
        test++;
        maxx=0;
        p=-100000000000000;
        if(n==0)
            break;
        for(i=1;i<=n;i++)
        {
            in(a),in(b),in(c);
            /*maxx=max(a,maxx);
            maxx=max(b,maxx);
            maxx=max(c,maxx);*/
            pushall(a,b,c);
        }
        sort(v.begin(),v.begin()+v.size(),comp);
        sz=v.size();

        mm(dp,-1);
        nn=sz;
        for(i=0;i<sz;i++)
        {
            p=max(p,call(i)+v[i].z);
        }
        pf("Case %lld: maximum height = %lld\n",test,p);
        v.cl;
    }
}
