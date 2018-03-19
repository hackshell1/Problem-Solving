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
    ll node,dgr;
    ss(ll a,ll b)
    {
        node=a;
        dgr=b;
    }
};

bool operator<(const ss& l, const ss& r)
{
    if(r.dgr==l.dgr)
        return r.node<l.node;
    return r.dgr < l.dgr;
}
priority_queue<ss>q;
ll indegree[10005],vis[10005];
vector<ll>v[10050],VV;

ll solve(ll n)
{
    ll a,b,d,sz,x,cnt=0;
    while(!q.empty())
    {
        a=q.top().node;
        d=q.top().dgr;
        //pf("A = %lld B = %lld\n",a,d);
        q.pop();
        if(vis[a]!=-1)
            continue;
        if(d!=0)
            return -1;
        vis[a]=1;
        VV.pb(a);
        cnt++;
        ll sz=v[a].size();
        for(ll i=0;i<sz;i++)
        {
            x=v[a][i];
            if(indegree[x]==0)
                continue;
            if(vis[x]==-1)
            {
                indegree[x]--;
                q.push(ss(x,indegree[x]));
            }
        }
        if(cnt==n)
            return 1;
    }
    return 1;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    in(n),in(m);
    for(i=0;i<m;i++)
    {
        in(a),in(b);
        v[a].pb(b);
        indegree[b]++;
    }
    for(i=1;i<=n;i++)
        if(indegree[i]==0)
            q.push(ss(i,0));
    mm(vis,-1);
    p=solve(n);
    if(p==-1)
        pf("Sandro fails.\n");
    else
    {
        ll sz=VV.size();
        for(i=0;i<sz;i++)
            pf("%lld ",VV[i]);
        pf("\n");
    }
    return 0;
}
