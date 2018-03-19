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

vector<ll>v[20005],V;
ll vis[20005];

ll findd(ll a)
{
    ll i, sz=V.size();
    for(i=0;i<sz;i++)
        if(V[i]==a)
            return i;
    V.pb(a);
    return sz;
}

ll bfs_1D(ll a)
{
    ll x,y,sz,cnt1=0,cnt0=0,i;
    if(v[a].size()==0)
        return 0;
    queue<ll>q;
    while(!q.empty())
        q.pop();
    q.push(a);
    vis[a]=0;
    cnt0=1;
    while(q.size()>0)
    {
        x=q.front();
        q.pop();
        sz=v[x].size();
        for(i=0;i<sz;i++)
        {
            y=v[x][i];
            if(vis[y]==-1)
            {
                q.push(y);
                vis[y]=vis[x]+1;
                if(vis[y]%2==0)
                    cnt0++;
                else
                    cnt1++;
            }
        }
    }
    return max(cnt0,cnt1);
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0;
    //fout;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n);
        x=0;
        for(i=0;i<n;i++)
        {
            in(a);
            in(b);
            v[a].pb(b);
            v[b].pb(a);
        }
        ll sz=n;

        mm(vis,-1);
        for(i=0;i<20005;i++)
            if(vis[i]==-1)
                x+=bfs_1D(i);


        pf("Case %lld: %lld\n",t,x);



        for(i=0;i<20005;i++)
            v[i].clear();
        V.cl;
    }
    return 0;
}
