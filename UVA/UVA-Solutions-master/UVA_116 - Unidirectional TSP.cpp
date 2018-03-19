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
#define rep(i,a,b,c) for(i=a;i<=b;i+=c)
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

ll min(ll a,ll b,ll c)
{
    return min(min(a,b),c);
}

ll min(ll w,ll x,ll y,ll z)
{
    return min(min(x,y),min(z,w));
}

ll dp[105][105],arr[105][105],n,m;

ll call(ll x,ll y)
{
    if(y==m)
        return 0;
    if(x==-1)
        x=n-1;
    else if(x==n)
        x=0;
    if(dp[x][y]!=1+(1<<30))
        return dp[x][y];
    return dp[x][y]=min(call(x+1,y+1),call(x,y+1),call(x-1,y+1))+arr[x][y];
}

void print_path(ll x,ll y)
{
    //pf("X = %lld Y = %lld\n",x,y);
    if(y==m-1)
    {
        pf("%lld\n",x+1);
        return;
    }
    ll minn=1+(1<<30),a,b,c;
    pf("%lld ",x+1);b=dp[x][y+1];
    if(x==0)
    {
        a=dp[n-1][y+1];
        c=dp[x+1][y+1];
        minn=min(a,b,c);
        //pf("minn = %lld in pos = %lld %lld   1\n",minn,x,y);
        if(minn==b)
            print_path(x,y+1);
        else if(minn==c)
            print_path(x+1,y+1);
        else if(minn==a)
            print_path(n-1,y+1);
        return;
    }
    else if(x==n-1)
    {
        a=dp[x-1][y+1];
        c=dp[0][y+1];
        minn=min(a,b,c);
        //pf("minn = %lld in pos = %lld %lld   2\n",minn,x,y);
        if(minn==c)
            print_path(0,y+1);
        else if(minn==a)
            print_path(x-1,y+1);
        else if(minn==b)
            print_path(x,y+1);
        return;
    }
    else
    {
        a=dp[x-1][y+1];
        c=dp[x+1][y+1];
        minn=min(a,b,c);
        //pf("minn = %lld in pos = %lld %lld   3\n",minn,x,y);
        if(minn==a)
            print_path(x-1,y+1);
        else if(minn==b)
            print_path(x,y+1);
        else if(minn==c)
            print_path(x+1,y+1);
        return;
    }
}

int main()
{
    ll i,j,k,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    string s,s1,s2;

    //fout;

    while(scanf("%lld%lld",&n,&m)==2)
    {
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                in(arr[i][j]);

        ll makedp=1073741825;

        for(i=0;i<105;i++)
            for(j=0;j<105;j++)
                dp[i][j]=1+(1<<30);

        minn=(1<<30)+1;
        x=-1;



        for(i=0;i<n;i++)
        {
            if(dp[i][0]==makedp)
            {
                p=call(i,0);
                if(minn>p)
                {
                    minn=p;
                    x=i;
                }
            }
        }
        /*pf("\n\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                pf("%5lld ",dp[i][j]);
            pf("\n");
        }
        pf("\n\n");*/
        if(n==1)
        {
            for(i=0;i<m;i++){
                pf("1");
                if(i<m-1)
                    pf(" ");
            }
            pf("\n");
        }
        else
            print_path(x,0);
        pf("%lld\n",minn);
    }
    return 0;
}
