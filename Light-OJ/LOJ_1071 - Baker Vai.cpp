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

ll n,m,arr[101][101],dp[101][101][101][3],t;

ll call(ll pos,ll x,ll y,ll dir)
{
    if(pos==n)
    {
        if(x==m-2 && y==m-1)
            return 0;
        return -100000000000;
    }
    if(dp[pos][x][y][dir]!=-1)
        return dp[pos][x][y][dir];

    ll p=-10000000000000,i,sum1=0,sum2=0,j;

    if(dir==0)
    {
        if(x+1<y)
            p=max(p,call(pos,x+1,y,0)+arr[pos][x]);
        p=max(p,call(pos,x,y,1)+arr[pos][x]);
    }
    if(dir==1)
    {
        if(y+1<m)
            p=max(p,call(pos,x,y+1,1)+arr[pos][y]);
        p=max(p,call(pos+1,x,y,0)+arr[pos][y]);
    }
    return dp[pos][x][y][dir]=p;
}

int main()
{
    ll i,j,p,test;
    //fin;
    //fout;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                in(arr[i][j]);
        mm(dp,-1);
        p=call(0,0,1,0);
        pf("Case %lld: %lld\n",t,p);
    }
    return 0;
}
