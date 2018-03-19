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
#define cl clear()


using namespace std;
typedef long long ll;

vector<ll>v[30005],V[30005];

ll bfs_1D(ll a,ll type)
{
    ll vis[30005],x,y,sz,maxx=0,pos;
    mm(vis,-1);
    queue<ll>q;
    while(!q.empty())
        q.pop();
    q.push(a);
    vis[a]=0;
    while(q.size()>0)
    {
        x=q.front();
        q.pop();
        sz=v[x].size();
        for(ll i=0;i<sz;i++)
        {
            y=v[x][i];
            if(vis[y]==-1)
            {
                q.push(y);
                vis[y]=vis[x]+V[x][i];
                if(maxx<vis[y])
                {
                    maxx=vis[y];
                    pos=y;
                }
            }
        }
    }
    if(type==1)
        return pos;
    return maxx;
}

int main()
{
    ll i,j,k,n,m,x=0,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    //fout;
    in(test);
    ll degree[30005];
    for(t=1;t<=test;t++)
    {
        x=0;
        in(n);
        mm(degree,0);
        for(i=0;i<n-1;i++)
        {
            in(a),in(b),in(c);
            v[a].pb(b);
            v[b].pb(a);
            V[a].pb(c);
            V[b].pb(c);
        }
        x=bfs_1D(0,1);
        x=bfs_1D(x,2);
        pf("Case %lld: %lld\n",t,x);
        for(i=0;i<n+4;i++)
        {
            V[i].cl;
            v[i].cl;
        }
    }
    return 0;
}

