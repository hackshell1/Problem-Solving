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

vector<ll>v[10005];
vector<string>vs;
ll indegree[10006],vis[100005];
vector<ll>vv;

ll findd(S a)
{
    ll sz=vs.size(),i,j;
    for(i=0;i<sz;i++)
        if(vs[i]==a)
            return i;
    vs.pb(a);
    return sz;
}

struct ss
{
    ll node;
    ll dgr;
    ss(ll x,ll y)
    {
        node=x;
        dgr=y;
    }
};

bool operator<(const ss& l, const ss& r) {
  return r.dgr < l.dgr;
}

priority_queue<ss>q;


ll DAG(ll n)
{
    ll a,b,x,i,j,sz;
    if(q.top().dgr>0)
        return -1;
    while(!q.empty())
    {
        a=q.top().node;
        b=q.top().dgr;
        q.pop();

        //pf("A = %lld B = %lld\n",a,b);
        if(vis[a]!=-1)
            continue;
        if(b>0)
            return -1;
        vis[a]=1;
        vv.pb(a);
        sz=v[a].size();
        for(i=0;i<sz;i++)
        {
            x=v[a][i];
            if(indegree[x]>0)
            {
                indegree[x]--;
                q.push(ss(x,indegree[x]));
            }
        }
    }
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    string s1,s2;
    fout;
    while(cin>>n)
    {
        test++;
        for(i=1;i<=n;i++)
        {
            cin>>s1;
            findd(s1);
        }
        cin>>m;
        for(i=0;i<m;i++)
        {
            cin>>s1>>s2;
            a=findd(s1);
            b=findd(s2);
            v[a].pb(b);
            indegree[b]++;
        }
        cnt=vs.size();
        for(i=0;i<cnt;i++)
            q.push(ss(i,indegree[i]));
        mm(vis,-1);
        p=DAG(cnt);
        pf("Case #%lld: Dilbert should drink beverages in this order: ",test);
        if(p!=-1)
        {
            cnt=vv.size();
            for(i=0;i<cnt;i++){
                cout<<vs[vv[i]];
                if(i<cnt-1)
                    pf(" ");
            }
            pf(".\n");
        }
        else
            pf("NO\n");
        vs.cl;
        vv.cl;
        for(i=0;i<cnt;i++)
            v[i].cl;
        pf("\n");
    }
    return 0;
}

