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

ll arr[12][12],dir[8]={0,1,0,-1,1,0,-1,0},vis[12][12];

struct ss
{
    ll a,b;
    char c;
    ss(ll x,ll y,char z)
    {
        a=x;
        b=y;
        c=z;
    }
};

bool compare(ss l,ss r)
{
    return l.c<r.c;
}

vector<ss>v;


ll bfs(ll a,ll b,ll c,ll d,ll n)
{
    mm(vis,-1);
    queue<ss>q;
    q.push(ss(a,b,'c'));
    vis[a][b]=0;

    while(!q.empty())
    {
        a=q.front().a;
        b=q.front().b;
        q.pop();

        for(ll i=0;i<7;i+=2)
        {
            ll x=a+dir[i];
            ll y=b+dir[i+1];
            if(vis[x][y]==-1 && arr[x][y]==0 && x>=0 && x<n && y>=0 && y<n)
            {
                vis[x][y]=vis[a][b]+1;
                q.push(ss(x,y,'c'));
                if(x==c && y==d)
                    return vis[x][y];
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
    cin>>test;
    for(t=1;t<=test;t++)
    {
        mm(arr,-1);
        cin>>n;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>c;
                if(c=='.')
                    arr[i][j]=0;
                else if(c>='A' && c<='Z')
                {
                    arr[i][j]=-1;
                    v.pb(ss(i,j,c));
                }
            }
        }

        ll sz=v.size();
        sort(v.begin(),v.begin()+sz,compare);
        ll rrr=0;
        sum=0;
        for(i=0;i<sz-1;i++)
        {
            arr[v[i].a][v[i].b]=0;
            arr[v[i+1].a][v[i+1].b]=0;
            x=bfs(v[i].a,v[i].b,v[i+1].a,v[i+1].b,n);
            if(x==-1)
            {
                rrr=1;
                break;
            }
            else
                sum+=x;
        }
        if(rrr==1)
            pf("Case %lld: Impossible\n",t);
        else
            pf("Case %lld: %lld\n",t,sum);
        mm(arr,-1);
        mm(vis,-1);
        v.cl;
    }
}
