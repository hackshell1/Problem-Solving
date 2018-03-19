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
    ll a,b,c;
    ss(ll x,ll y,ll z)
    {
        a=x;
        b=y;
        c=z;
    }
};

bool compare(ss l,ss r)
{
    return l.c<r.c;
}

vector<ss>v,vv[55];
ll arr[55],vis[55];
queue<ll>q;

ll findd(ll x)
{
    if(arr[x]<=-1)
        return x;
    return arr[x]=findd(arr[x]);
}


bool bfs(ll a,ll n)
{
    while(!q.empty())
        q.pop();

    vis[a]=1;
    q.push(a);

    while(!q.empty())
    {
        a=q.front();
        q.pop();
        ll sz=vv[a].size();
        for(ll i=0;i<sz;i++)
        {
            ll x=vv[a][i].a;
            if(vis[x]==-1)
            {
                q.push(x);
                vis[x]=0;
            }
        }
    }

    for(ll i=1;i<=n;i++)
    {
        if(vis[i]==-1)
            return false;
    }
    return true;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    string s,s1,s2;


    in(test);
    for(t=1;t<=test;t++)
    {
        in(n);
        sum=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                in(a);
                sum+=a;
                if(a>0)
                    v.pb(ss(min(i,j),max(i,j),a));
            }
        }

        sort(v.begin(),v.begin()+v.size(),compare);

        //pf("Sum = %lld\n",sum);
        mm(arr,-1);
        mm(vis,-1);
        cnt=0;
        for(i=0;i<v.size();i++)
        {
            a=v[i].a;
            b=v[i].b;
            c=v[i].c;

            p=findd(a);
            q=findd(b);

            if(p==q)
                continue;
            else
            {
                arr[p]=q;
                cnt+=c;
                vv[a].pb(ss(b,0,0));
                vv[b].pb(ss(a,0,0));
            }
        }
        if(bfs(1,n)==true)
            pf("Case %lld: %lld\n",t,sum-cnt);
        else
            pf("Case %lld: -1\n",t);
        for(i=0;i<=n;i++)
            vv[i].cl;
        v.clear();
    }
    return 0;
}











