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

struct ss
{
    ll a,b,c;
    ss(ll x,ll y,ll f)
    {
        a=x;
        b=y;
        c=f;
    }
};

ll arr[250][250],visj[250][250],visf[250][250],dir[8]={0,1,0,-1,1,0,-1,0};

vector<ss>v;

ll bfs(ss start,ll n,ll m)
{
    queue<ss>q;
    mm(visf,-1);
    mm(visj,-1);
    ll i,j;
    ll sz=v.size();
    for(i=0;i<sz;i++)
    {
        q.push(ss(v[i].a,v[i].b,v[i].c));
        visf[v[i].a][v[i].b]=1;
    }
    q.push(ss(start.a,start.b,start.c));
    visj[start.a][start.b]=0;
    ll x,y;
    while(!q.empty())
    {
        ss curr=q.front();
        q.pop();
        if(curr.c==0)
        {
            for(i=0;i<7;i+=2)
            {
                x=curr.a+dir[i];
                y=curr.b+dir[i+1];
                if(x>=0 && x<n && y>=0 && y<m && arr[x][y]==0 && visf[x][y]==-1)
                {
                    q.push(ss(x,y,0));
                    visf[x][y]=1;
                }
            }
        }
        else if(curr.c==1)
        {
            for(i=0;i<7;i+=2)
            {
                x=curr.a+dir[i];
                y=curr.b+dir[i+1];
                if(x>=n || x<0 || y>=m || y<0)
                    return visj[curr.a][curr.b]+1;
                if(arr[x][y]!=-1 && visf[x][y]==-1 && visj[x][y]==-1)
                {
                    q.push(ss(x,y,1));
                    visj[x][y]=visj[curr.a][curr.b]+1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0;
    in(test);
    char c;
    for(t=1;t<=test;t++)
    {
        pf("Case %lld: ",t);
        mm(arr,-1);
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>c;
                if(c=='#')
                    arr[i][j]=-1;
                else if(c=='J')
                {
                    x=i;
                    y=j;
                    arr[i][j]=0;
                }
                else if(c=='F')
                {
                    arr[i][j]=0;
                    v.pb(ss(i,j,0));
                }
                else if(c=='.')
                    arr[i][j]=0;
            }
        }
        x=bfs(ss(x,y,1),n,m);
        if(x==-1)
            pf("IMPOSSIBLE\n");
        else
            pf("%lld\n",x);
        v.cl;
    }
    return 0;
}

