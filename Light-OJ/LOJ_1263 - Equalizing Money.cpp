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

vector<ll>v[100005],V;

ll arr[100050],vis[100005],cnt,countt;

void dfs(ll root)
{
    vis[root]=1;
    cnt++;
    countt+=arr[root];
    ll sz=v[root].size(),i,j;
    for(i=0;i<sz;i++)
    {
        ll x=v[root][i];
        if(vis[x]==-1)
            dfs(x);
    }
}


int main()
{
    ll i,j,k,n,m,x,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;

    in(test);
    for(t=1;t<=test;t++)
    {
        pf("Case %lld: ",t);
        in(n),in(m);
        sum=0;
        for(i=1;i<=n;i++){
            in(arr[i]);
            sum+=arr[i];
        }
        for(i=0;i<m;i++)
        {
            in(a),in(b);
            v[a].pb(b);
            v[b].pb(a);
        }
        mm(vis,-1);
        ll rr=0;
        for(i=1;i<=n;i++)
        {
            if(vis[i]==-1)
            {
                cnt=0;
                countt=0;
                dfs(i);
                if(countt%cnt!=0)
                {
                    rr=1;
                    break;
                }
                else
                    V.pb(countt/cnt);
            }
        }
        for(i=0;i<V.size()-1;i++)
        {
            if(V[i]!=V[i+1])
            {
                rr=1;
                break;
            }
        }
        if(rr==0)
            pf("Yes\n");
        else
            pf("No\n");
        V.cl;
        for(i=1;i<=n;i++)
            v[i].cl;
    }

return 0;

}

