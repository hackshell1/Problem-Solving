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

using namespace std;
typedef long long ll;
typedef string S;
typedef double D;

struct ss
{
    ll st,ed,pos;
}vis[100005];

vector<ll>v[10005];
ll timer;

void dfs(ll root)
{
    vis[root].st=++timer;
    vis[root].pos=root;
    ll sz,i,j,x;
    sz=v[root].size();
    for(i=0;i<sz;i++)
    {
        x=v[root][i];
        if(vis[x].st==-1)
            dfs(x);
    }
    vis[root].ed=++timer;
}

bool compare(ss l,ss r)
{
    if(l.ed==r.ed)
        return l.pos>r.pos;
    return l.ed>r.ed;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    while(in(n),in(m))
    {
        if(n==0 && m==0)
            break;
        for(i=0;i<m;i++)
        {
            in(a),in(b);
            v[a].pb(b);
        }
        timer=0;
        for(i=0;i<=n;i++)
        {
            vis[i].st=-1;
            vis[i].ed=-1;
        }

        for(i=1;i<=n;i++)
        {
            if(vis[i].st==-1)
                dfs(i);
        }
        sort(vis+1,vis+n+1,compare);
        for(i=1;i<=n;i++)
            pf("%lld ",vis[i].pos);
        pf("\n");

        for(i=1;i<=n;i++)
            v[i].cl;
    }
    return 0;
}
