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

struct ss
{
    ll node,degree;
    ss(ll a,ll b)
    {
        node=a;
        degree=b;
    }
};

bool operator<(const ss& l, const ss& r)
{
    if(l.degree==r.degree)
        return l.node>r.node;
    return r.degree < l.degree;
}

priority_queue<ss>q;
vector<ll>v[10005],V;

ll indegree[100005],vis[10005];


ll solve()
{
    ll x,dgr,y,i,sz,cnt=q.size();
    while(!q.empty())
    {
        x=q.top().node;
        dgr=q.top().degree;
        q.pop();
        cnt--;
        if(cnt<0)
            return 1;
        if(dgr>0)
            return -1;
        V.push_back(x);
        sz=v[x].size();
        for(i=0;i<sz;i++)
        {
            y=v[x][i];
            if(indegree[y]>0)
            {
                indegree[y]--;
                q.push(ss(y,indegree[y]));
            }
        }
    }
    return 1;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    in(n),in(m);
    for(i=1;i<=m;i++)
    {
        in(a);
        in(b);
        for(j=0;j<b;j++)
        {
            in(p);
            v[p].pb(a);
            indegree[a]++;
        }
    }
    for(i=1;i<=n;i++)
            q.push(ss(i,indegree[i]));

    mm(vis,-1);

    p=solve();

    if(p==1)
    {
        for(i=0;i<V.size();i++)
            pf("%lld ",V[i]);
    }
    return 0;
}
