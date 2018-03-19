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
#define inf 1<<28


using namespace std;
typedef long long ll;

ll arr[505][505],vis[505][505],dir[8]={0,1,0,-1,1,0,-1,0},vis1[505][505];

struct ss
{
    ll a,b;
    ss(ll x,ll y)
    {
        a=x;
        b=y;
    }
};

ll bfs(ll a,ll b,ll n,ll m)
{
    mm(vis,-1);
    queue<ss>q;
    q.push(ss(a,b));
    vis[a][b]=0;
    ll cnt=0;
    while(!q.empty())
    {
        a=q.front().a;
        b=q.front().b;
        q.pop();
        for(ll i=0;i<7;i+=2)
        {
            ll x=dir[i]+a;
            ll y=dir[i+1]+b;
            if(x>=0 && x<n && y>=0 && y<m && arr[x][y]!=-1 && vis[x][y]==-1)
            {
                vis[x][y]=vis[a][b]+1;
                q.push(ss(x,y));
                if(arr[x][y]==1)
                    cnt++;
            }
        }
    }
    return cnt;
}

void dfs(ll a,ll b,ll p,ll q,ll n)
{
    vis1[a][b]=n;
    ll i,j,x,y;
    for(i=0;i<7;i+=2)
    {
        x=a+dir[i];
        y=b+dir[i+1];
        if(x>=0 && x<p && y>=0 && y<q && arr[x][y]!=-1 && vis1[x][y]==-1)
            dfs(x,y,p,q,n);
    }
    return;
}


int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,l;
    char c;
    //fout;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        mm(arr,-1);
        pf("Case %lld:\n",t);
        cin>>k>>l>>m;
        getchar();
        for(i=0;i<k;i++)
        {
            for(j=0;j<l;j++)
            {
                cin>>c;
                if(c=='#')
                    arr[i][j]=-1;
                else if(c=='C')
                    arr[i][j]=1;
                else if(c=='.')
                    arr[i][j]=0;
            }
        }
        mm(vis1,-1);
        for(i=0;i<m;i++)
        {
            in(a),in(b);
            a--;
            b--;
            if(vis1[a][b]==-1){
                x=bfs(a,b,k,l);
                dfs(a,b,k,l,x);
            }
            pf("%lld\n",vis1[a][b]);
        }
    }
    return 0;
}

