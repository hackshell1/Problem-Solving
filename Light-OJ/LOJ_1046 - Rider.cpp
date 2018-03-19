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
#define test_then in(test);for(t=1;t<=test;t++)


using namespace std;
typedef long long ll;

struct ss
{
    ll a,b,c;
    ss(ll x,ll y,ll z)
    {
        a=x;
        b=y;
        c=z;
    }
};

vector<ss>v;
ll dir[20]={1,2,1,-2,2,1,2,-1,-1,2,-1,-2,-2,1,-2,-1},vis[11][11],arr[11][11];

ll bfs(ll a,ll b,ll c,ll x,ll y,ll n,ll m)
{
    mm(vis,-1);
    queue<ss>q;
    if(a==x && b==y)
        return 0;
    vis[a][b]=0;
    q.push(ss(a,b,0));
    while(!q.empty())
    {
        ll r=q.front().a;
        ll s=q.front().b;
        q.pop();

        for(ll i=0;i<15;i+=2)
        {
            ll u=r+(dir[i]);
            ll v=s+(dir[i+1]);
            if(vis[u][v]==-1 && u>=0 && u<n && v>=0 && v<m)
            {
                vis[u][v]=vis[r][s]+1;
                q.push(ss(u,v,0));
                if(u==x && v==y)
                    return vis[u][v];
            }
        }
    }
    return -1;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0;
    char c;
    //fout;
    test_then
    {
        mm(arr,-1);
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>c;
                if(c=='.')
                    arr[i][j]=0;
                else if(c>='1' && c<='9')
                {
                    arr[i][j]=0;
                    v.pb(ss(i,j,c-'0'));
                }
            }
        }

        minn=1<<30;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                ll sz=v.size();
                ll sum=0;
                for(k=0;k<sz;k++)
                {
                    x=bfs(v[k].a,v[k].b,v[k].c,i,j,n,m);
                    if(x==-1)
                    {
                        sum=1<<30;
                        break;
                    }
                    else
                        sum+=(ll)ceil(x/(v[k].c+0.0));
                }
                minn=min(minn,sum);
            }
        }
        pf("Case %lld: ",t);
        if(minn==1<<30)
            pf("-1\n");
        else
            pf("%lld\n",minn);
        v.cl;
    }
    return 0;
}

