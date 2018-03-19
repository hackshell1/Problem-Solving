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

vector<ll>v[100005],VV;
struct ss
{
    ll node;
    ll dgr;
    ss(ll a,ll b)
    {
        node=a;
        dgr=b;
    }
};

bool operator<(const ss& l, const ss& r) {
  return l.dgr > r.dgr;
}

priority_queue<ss>q;

ll indegree[100005],vis[100005];


ll DAG(ll n)
{
    for(ll i=1;i<=n;i++)
        q.push(ss(i,indegree[i]));

    mm(vis,-1);

    if(q.top().dgr!=0)
        return -1;

    while(!q.empty())
    {
        ll a=q.top().node;
        ll r=q.top().dgr;
        q.pop();
        ll sz=v[a].size();
        if(vis[a]==-1)
            pf("%lld ",a);
        else
            continue;
        vis[a]=1;
        for(ll i=0;i<sz;i++)
        {
            ll x=v[a][i];
            if(indegree[x]>=1)
                q.push(ss(x,--indegree[x]));
        }
    }
    return 1;
}


int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    //fout;
    while(in(n),in(m))
    {
        if(n==0 && m==0)
            break;
        mm(indegree,0);
        for(i=0;i<m;i++)
        {
            in(a),in(b);
            indegree[b]++;
            v[a].pb(b);
        }

        for(i=1;i<=n;i++)
            q.push(ss(i,indegree[i]));
        //pf("ans = ");
        c=DAG(n);
        pf("\n");
        for(i=0;i<=n;i++)
            v[i].cl;
        VV.cl;
    }
    return 0;
}
