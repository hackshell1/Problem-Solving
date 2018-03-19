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

ll indegree[10005], vis[100005],numbering;
vector<ll>v[100005],VV1,VV2;

bool operator<(const ss& l, const ss& r) {
    if(l.dgr==r.dgr)
        return r.node<l.node;
    return r.dgr<l.dgr;
}


priority_queue<ss>q;

ll solve(ll n)
{
    vector<ll>v1,v2;
    ll cnt=0,i,j,a,d,sz,x;
    while(!q.empty())
    {
        v1.cl;
        v2.cl;
        if(cnt==n)
            return 1;
        if(q.top().dgr>0)
            return -1;
        ll test=0;
        while(!q.empty() && q.top().dgr==0)
        {
            x=q.top().node;
            if(vis[x]==-1)
            {
                v1.pb(q.top().node);
                v2.pb(q.top().dgr);
                test=1;
            }
            q.pop();
            if(q.empty())
                break;
        }

        for(i=0;i<v1.size();i++)
        {
            a=v1[i];
            d=v2[i];
            if(vis[a]!=-1)
                continue;
            vis[a]=1;
            VV1.pb(a);
            VV2.pb(numbering);
            cnt++;
            if(cnt==n)
                return 1;
            sz=v[a].size();
            for(j=0;j<sz;j++)
            {
                x=v[a][j];
                if(vis[x]==-1 && indegree[x]>=1)
                {
                    indegree[x]--;
                    q.push(ss(x,indegree[x]));
                }
            }
        }

        if(test==1)
            numbering++;
    }
    return 1;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(m);
        mm(indegree,0);
        mm(vis,-1);
        for(i=0;i<m;i++)
        {
            in(a),in(b);
            v[b].pb(a);
            indegree[a]++;
        }
        for(i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(ss(i,0));
        numbering=1;
        p=solve(n);

        pf("Scenario #%lld:\n",t);

        for(i=0;i<VV1.size();i++)
            pf("%lld %lld\n",VV2[i],VV1[i]);
        for(i=0;i<n+10;i++)
            v[i].cl;
        VV1.cl;
        VV2.cl;
    }
    return 0;
}
