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

ll max_even(ll x)
{
    if(x%2==0)
        return x;
    return x-1;
}

ll min_odd(ll x)
{
    if(x%2==0)
        return x-1;
    return x;
}

string itoaa(ll n)
{
    char x[100]={'\0'};
    ll lim=log10(n);
    for(ll i=lim;i>=0;i--)
    {
        x[i]=(n%10)+'0';
        n=n/10;
    }
    string r=x;
    return r;
}

ll gcd(ll a,ll b)
{
    while(1)
    {
        if(b%a==0)
            return a;
        if(a==1)
            return 1;
        ll x=a;
        a=b%a;
        b=x;
    }
    return 1;
}

ll poww(ll x,ll n)
{
    ll sum=1,i;
    for(i=1;i<=n;i++)
        sum*=x;
    return sum;
}

ll upr_bnd(ll x,ll siz,ll *arr)
{
    return upper_bound(arr,arr+siz,x)-arr;
}

ll lr_bnd(ll x,ll siz,ll *arr)
{
    return lower_bound(arr,arr+siz,x)-arr;
}

ll int_point_distance(ll x1,ll y1,ll x2,ll y2)
{
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

float float_point_distance(float x1,float y1,float x2,float y2)
{
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

void arrin(ll *arr,ll lo,ll hi)
{
    ll i;
    for(i=lo;i<=hi;i++)
        in(arr[i]);
}

struct ss
{
    ll a,b;
    ss(ll x,ll y)
    {
        a=x;
        b=y;
    }
};

ll arr[25][25];
ll dir1[8]={0,1,0,-1,1,0,-1,0};

ll bfs(ll a1,ll a2,ll h1,ll h2,ll n,ll m)
{
    ll vis[25][25];
    ll x,y,p,q,i,j;
    queue<ss>qq;
    mm(vis,-1);
    vis[a1][a2]=0;
    qq.push(ss(a1,a2));
    while(!qq.empty())
    {
        x=qq.front().a;
        y=qq.front().b;
        qq.pop();

        for(i=0;i<7;i+=2)
        {
            p=x+dir1[i];
            q=y+dir1[i+1];
            if(vis[p][q]==-1 && arr[p][q]!=-1 && p>=0 && p<n && q>=0 && q<m)
            {
            //pf("P = %lld Q = %lld\n",p,q);
                qq.push(ss(p,q));
                vis[p][q]=vis[x][y]+1;
                if(p==h1 && q==h2)
                    return vis[p][q];
            }
        }
    }
    return -1;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,test=0,len,sum=0;
    in(test);
    char ch;
    ll a1,a2,b1,b2,c1,c2,h1,h2,z;
    for(t=1;t<=test;t++)
    {
        in(n),in(m);
        getchar();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>ch;
                if(ch=='#')
                    arr[i][j]=-1;
                else if(ch=='.')
                    arr[i][j]=0;
                else if(ch=='m')
                    arr[i][j]=-1;
                else if(ch=='h')
                {
                    h1=i;
                    h2=j;
                    arr[i][j]=0;
                }
                else if(ch=='a')
                {
                    a1=i;
                    a2=j;
                    arr[i][j]=0;
                }
                else if(ch=='b')
                {
                    b1=i;
                    b2=j;
                    arr[i][j]=0;
                }
                else if(ch=='c')
                {
                    c1=i;
                    c2=j;
                    arr[i][j]=0;
                }
            }
        }
        x=bfs(a1,a2,h1,h2,n,m);
        y=bfs(b1,b2,h1,h2,n,m);
        z=bfs(c1,c2,h1,h2,n,m);

        //pf("X = %lld Y= %lld Z = %lld\n",x,y,z);

        if(x==-1 || y==-1 || z==-1)
            pf("Case %lld: Imposisble\n",t);
        else
            pf("Case %lld: %lld\n",t,max(x,max(y,z)));
    }
    return 0;
}

