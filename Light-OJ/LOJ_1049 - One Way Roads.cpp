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
#define logg(x,y) (double)log(y)/(double)log(x)
#define cl clear()


using namespace std;
typedef long long ll;

vector<ll>v1[105],v2[105],V;
ll degree[105],vis[105];

ll findd(ll a)
{
    ll sz,i;
    sz=V.size();
    for(i=0;i<sz;i++)
        if(V[i]==a)
            return i;
    V.pb(a);
    return sz;
}

ll bfs(ll a,ll b,ll type)
{
    queue<ll>q;
    ll sum=0;
    mm(vis,-1);
    vis[a]=0;
    if(type==0)
    {
        if(v2[a][0]<0)
            sum-=v2[a][0];
        a=v1[a][0];
        q.push(a);
        vis[a]=1;
    }
    else
    {
        if(v2[a][1]<0)
            sum-=v2[a][1];
        a=v1[a][1];
        q.push(a);
        vis[a]=1;
    }
    ll sz,i,x;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        sz=v1[a].size();
        for(i=0;i<sz;i++)
        {
            x=v1[a][i];
            if(vis[x]==-1)
            {
                vis[x]=vis[a]+1;
                q.push(x);
                if(v2[a][i]<0)
                    sum+=abs(v2[a][i]);
            }
        }
    }
    sz=v1[a].size();
    for(i=0;i<sz;i++)
    {
        if(v1[a][i]==1 && v2[a][i]<0)
            sum-=v2[a][i];

    }
    return sum;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    //fout;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n);
        mm(degree,0);
        for(i=0;i<n;i++)
        {
            in(a),in(b),in(c);
            v1[a].pb(b);
            v1[b].pb(a);
            v2[a].pb(c);
            v2[b].pb(-c);
            degree[b]++;
        }

        ll sz=V.size();
        ll root=-1;

        for(i=1;i<=n;i++)
        {
            if(degree[i]==0)
            {
                root=i;
                break;
            }
        }

        if(root==-1)
        {
            pf("Case %lld: 0\n",t);
            continue;
        }

        for(i=1;i<=n;i++)
            if(degree[i]==0)
            {
                root=i;
                break;
            }
        x=bfs(1,1,0);

        y=bfs(1,1,1);
        pf("Case %lld: %lld\n",t,min(x,y));

        for(i=1;i<=n;i++){
            v1[i].cl;
            v2[i].cl;
        }
    }
    return 0;
}
