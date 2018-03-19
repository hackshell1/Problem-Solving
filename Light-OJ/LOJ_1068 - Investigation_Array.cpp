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

ll t,k,len,dp[14][3][3][150][150],arr[20],aee[20];

ll call(ll pos,ll eql_sml1,ll eql_sml2,ll sum,ll digsum)
{
    if(pos>len)
    {
        if(sum==0 && digsum==0)
            return 1;
        return 0;
    }
    if(dp[pos][eql_sml1][eql_sml2][sum][digsum]!=-1)
        return dp[pos][eql_sml1][eql_sml2][sum][digsum];

    ll p=0,start=0,endd=9,i;

    if(eql_sml1==1)
        start=arr[pos];
    if(eql_sml2==1)
        endd=aee[pos];

    for(i=start;i<=endd;i++)
    {
        ll x=(i+(sum*10))%k;
        ll y=(i+digsum)%k;
        p+=call(pos+1, start==i && eql_sml1?1:0, endd==i && eql_sml2==1?1:0, x,y);
    }
    return dp[pos][eql_sml1][eql_sml2][sum][digsum]=p;
}

int main()
{
    ll test,i,p;
    ll a,b;
    //fout;
    in(test);
    for(ll t=1;t<=test;t++)
    {
        in(a),in(b),in(k);
        if(a>b)
            swap(a,b);
        if(k>99)
        {
            pf("Case %lld: 0\n",t);
            continue;
        }
        ll lim1=log10(a);
        ll lim2=log10(b);
        ll cnt=0;
        if(lim2>lim1)
        {
            for(i=1;i<=(lim2-lim1);i++)
                arr[cnt++]=0;
        }

        for(i=lim1;i>=0;i--)
        {
            arr[cnt+i]=a%10;
            a=a/10;
        }

        for(i=lim2;i>=0;i--)
        {
            aee[i]=b%10;
            b/=10;
        }


        len=lim2;

        /*for(i=0;i<=len;i++)
            pf("%lld",arr[i]);
        pf("\n");
        for(i=0;i<=len;i++)
            pf("%lld",aee[i]);
        pf("\n");*/

        mm(dp,-1);
        p=call(0,1,1,0,0);
        pf("Case %lld: %lld\n",t,p);
    }
    return 0;
}

