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
#define inf 1<<30


using namespace std;
typedef long long ll;

ll vis1[1005][1005],vis2[1005][1005],arr[1005][1005],dir1[4]={0,0,1,-1},dir2[4]={1,-1,0,0};

struct ss
{
    ll a,b;
    ss(ll x,ll y)
    {
        a=x;
        b=y;
    }
};

queue<ss>q1,q2;

ll bfs(ll m,ll n)
{
    ll x1,x2,y1,y2,sz,i,j;
    while(q1.size()>0)
    {
        if(q2.size()>0)
        {
            sz=q2.size();
            for(i=0;i<sz;i++)
            {
                x1=q2.front().a;
                y1=q2.front().b;
                q2.pop();
                for(j=0;j<4;j++)
                {
                    x2=x1+dir1[j];
                    y2=y1+dir2[j];
                    if(x2<m && x2>=0 && y2<n && y2>=0 && arr[x2][y2]!=-inf && vis2[x2][y2]==-1)
                    {
                        vis2[x2][y2]=1;
                        q2.push(ss(x2,y2));
                    }
                }
            }
        }
        sz=q1.size();
        for(i=0;i<sz;i++)
        {
            x1=q1.front().a;
            y1=q1.front().b;
            q1.pop();
            for(j=0;j<4;j++)
            {
                x2=x1+dir1[j];
                y2=y1+dir2[j];
                if(x2<=-1 || x2>=m || y2<=-1 || y2>=n)
                    return vis1[x1][y1]+1;
                if(arr[x2][y2]!=-inf && vis1[x2][y2]==-1 && vis2[x2][y2]!=1)
                {
                    vis1[x2][y2]=vis1[x1][y1]+1;
                    q1.push(ss(x2,y2));
                }
            }
        }
    }
    return -1;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0;
    cin>>test;
    char ch;
    for(t=1;t<=test;t++)
    {
        cin>>m>>n;
        getchar();
        mm(vis1,-1);
        mm(vis2,-1);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>ch;
                if(ch=='#')
                    arr[i][j]=-inf;
                else if(ch=='J'){
                    q1.push(ss(i,j));
                    arr[i][j]=0;
                    vis1[i][j]=0;
                }
                else if(ch=='F')
                {
                    q2.push(ss(i,j));
                    vis2[i][j]=1;
                    arr[i][j]=0;
                }
                else
                    arr[i][j]=0;
            }
        }
        x=bfs(m,n);
        if(x==-1)
            pf("IMPOSSIBLE\n");
        else
            pf("%lld\n",x);
        while(q1.size()>0)
            q1.pop();
        while(q2.size()>0)
            q2.pop();
    }
    return 0;
}

