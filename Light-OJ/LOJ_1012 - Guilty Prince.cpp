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

ll arr[505][505],vis[505][505];
ll dir[4][2]={0,1,
              0,-1,
              1,0,
              -1,0};


struct ss
{
    ll a,b;
    ss(ll aa,ll bb)
    {
        a=aa;
        b=bb;
    }
};

ll bfs(ll a,ll b,ll m,ll n)
{
    mm(vis,-1);
    queue<ss>q;
    q.push(ss(a,b));
    vis[a][b]=0;
    ll sum=1,i,j,aa,bb;
    while(!q.empty())
    {
        a=q.front().a;
        b=q.front().b;
        q.pop();
        for(i=0;i<4;i++)
        {
            aa=a+dir[i][0];
            bb=b+dir[i][1];
            if(aa>=0 && aa<m && bb>=0 && bb<n && arr[aa][bb]!=1 && vis[aa][bb]==-1)
            {
                q.push(ss(aa,bb));
                vis[aa][bb]=vis[a][b]+1;
                sum++;
            }
        }
    }
    return sum;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0;
    in(test);
    char ch[1000];
    for(t=1;t<=test;t++)
    {
        in(a),in(b);
        getchar();
        mm(arr,1);
        for(i=0;i<b;i++)
        {
            j=0;
            cin>>ch;
            for(j=0;j<a;j++)
            {
                if(ch[j]=='.')
                    arr[i][j]=0;
                else if(ch[j]=='@')
                {
                    arr[i][j]=0;
                    x=i;
                    y=j;
                }
                else
                    arr[i][j]=1;
            }
        }
        x=bfs(x,y,b,a);
        pf("Case %lld: %lld\n",t,x);
    }
    return 0;
}

