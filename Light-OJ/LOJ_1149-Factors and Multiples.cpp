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
#define ps push


using namespace std;
typedef long long ll;

ll arr[205],vis[205];

vector<ll>graph[205];

ll BPM(ll a)
{
    //pf("now with %lld => %lld\n",a,arr[a]);
    ll sz=graph[a].size();
    for(ll i=0;i<sz;i++)
    {
        ll u=graph[a][i];
        if(vis[u]==a)
            continue;
        if(vis[u]==-1)
        {
            vis[u]=a;
            return 1;
        }
        else
        {
            //pf("And going with %lld =>> %lld\n",u,arr[u]);
            ll prev=vis[u];
            vis[u]=a;
            if(BPM(u)==1)
                return 1;
            else
                vis[u]=prev;
        }
    }
    return 0;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    //fin;
    //fout;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n);
        for(i=0;i<n;i++)
            in(arr[i]);
        in(m);
        for(i=0+n;i<m+n;i++)
            in(arr[i]);
        for(i=0;i<n;i++)
        {
            x=arr[i];
            for(j=n;j<m+n;j++)
            {
                y=arr[j];
                if(y%x==0)
                {
                    graph[i].pb(j);
                    graph[j].pb(i);
                }
            }
        }

        /*for(i=0;i<n;i++)
        {
            pf("%lld  siz = %lld =  >> ",arr[i],(ll)graph[i].size());
            for(j=0;j<graph[i].size();j++)
                pf("%lld ",arr[graph[i][j]]);
            pf("\n");
        }*/

        mm(vis,-1);
        cnt=0;
        for(i=0;i<n;i++){
            //pf("I = %lld\n",i);
            cnt+=BPM(i);
        }
        pf("Case %lld: %lld\n",t,cnt);
        for(i=0;i<n+m;i++)
            graph[i].cl;
    }
    return 0;
}
