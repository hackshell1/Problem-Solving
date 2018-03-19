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

S s,s1;
ll len,dp[101][101];

ll call(ll posx,ll posy)
{
    if(posx>=posy)
        return 0;
    if(dp[posx][posy]!=-1)
        return dp[posx][posy];
    ll p=1000000000000000;
    if(s[posx]==s[posy])
        p=call(posx+1,posy-1);
    else
        p=min(p,min(call(posx+1,posy)+1,call(posx,posy-1)+1));
    return dp[posx][posy]=p;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,sum=0,c;
    in(test);
    getchar();
    for(t=1;t<=test;t++)
    {
        cin>>s;
        len=s.length();
        mm(dp,-1);
        p=call(0,len-1);
        pf("Case %lld: %lld\n",t,p);
    }
    return 0;
}

