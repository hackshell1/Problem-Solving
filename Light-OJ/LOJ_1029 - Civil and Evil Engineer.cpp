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

ll arr[10005];

struct ss
{
    ll a,b,c;
    ss(ll x,ll y,ll z)
    {
        a=x;
        b=y;
        c=z;
    }
};

bool compare(ss l ,ss r)
{
    return l.c<r.c;
}

bool compare1(ss l,ss r)
{
    return l.c>r.c;
}

vector<ss>v,V;

ll findd(ll a)
{
    if(arr[a]==a)
        return a;
    return arr[a]=findd(arr[a]);
}

ll get1()
{
    ll sz=v.size(),a,b,c;
    ll cnt=0;
    for(ll i=0;i<sz;i++)
    {
        a=v[i].a;
        b=v[i].b;
        c=v[i].c;
        ll p=findd(a);
        ll q=findd(b);
        if(p==q)
            continue;
        else
        {
            arr[q]=p;
            cnt+=c;
        }
    }
    return cnt;
}

ll get2()
{
    ll sz=V.size(),a,b,c;
    ll cnt=0;
    for(ll i=0;i<sz;i++)
    {
        a=V[i].a;
        b=V[i].b;
        c=V[i].c;
        ll p=findd(a);
        ll q=findd(b);
        if(p==q)
            continue;
        else
        {
            arr[q]=p;
            cnt+=c;
        }
    }
    return cnt;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n);
        while(in(a),in(b),in(c))
        {
            if(a==0 && b==0 && c==0)
                break;
            v.pb(ss(a,b,c));
            V.pb(ss(a,b,c));
        }
        ll sz=v.size();
        sort(v.begin(),v.begin()+sz,compare);
        sort(V.begin(),V.begin()+sz,compare1);

        for(i=0;i<=n;i++)
            arr[i]=i;
        p=get1();

        for(i=0;i<=n;i++)
            arr[i]=i;

        q=get2();

        pf("Case %lld: ",t);
        if((p+q)%2==0)
            pf("%lld\n",(p+q)/2);
        else
            pf("%lld/2\n",p+q);
            V.cl;
            v.cl;
    }
    return 0;
}
