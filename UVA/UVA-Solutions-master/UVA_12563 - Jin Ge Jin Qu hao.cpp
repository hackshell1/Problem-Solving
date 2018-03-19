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
#define LEFT node*2
#define RIGHT (node*2)+1


using namespace std;
typedef long long ll;
typedef string S;
typedef double D;

ll arr[1005],dp[51][9005],n,m,time;

ll call(ll pos,ll taken)
{
    if(taken==time)
        return 0;
    if(taken>time)
        return -1e10;
    if(pos==n)
        return 0;
    if(dp[pos][taken]!=-1)
        return dp[pos][taken];
    return dp[pos][taken]=max(call(pos+1,taken+arr[pos])+1,call(pos+1,taken));
}

/*
ll calll(ll pos,ll koyta_nisi,ll time_nisi,ll koyta_most,ll time_neoajabe)
{
    if(time_nisi>=time_neoajabe)
        return -1e10;
    if(koyta_nisi==koyta_most)
        return time_nisi;
    if(pos==n)
    {
        if(time_nisi>=time_neoajabe)
            return -1e10;
        if(koyta_nisi>koyta_most || koyta_nisi<koyta_most)
            return -1e10;
        return time_nisi;
    }
    if()
}
*/

int main()
{
    ll i,j,k,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    string s,s1,s2;
    //fout;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(time);
        for(i=0;i<n;i++)
            in(arr[i]);

        mm(dp,-1);
        time--;
        p=call(0,0);
        pf("P = %lld\n",p);

    }
}
