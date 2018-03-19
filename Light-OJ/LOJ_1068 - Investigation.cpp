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

ll A,B,arr[20],k,dp[12][3][111][111];

ll call(ll pos,ll sml_eql,ll main_sum,ll dig_sum,ll len)
{
    if(pos>len)
    {
        if(main_sum==0 && dig_sum==0)
            return 1;
        return 0;
    }
    if(dp[pos][sml_eql][main_sum][dig_sum]!=-1)
        return dp[pos][sml_eql][main_sum][dig_sum];
    ll p=0,i,nxt,start=0,endd=9;
    if(sml_eql==1)
    {
        start=0;
        endd=arr[pos];
    }

    for(i=start;i<=endd;i++)
        p+=call(pos+1,sml_eql&&(i==endd),((main_sum*10)+i)%k,(dig_sum+i)%k,len);
    return dp[pos][sml_eql][main_sum][dig_sum]=p;
}

int main()
{
    ll test,t,i,a,b,cnt,lim1,lim2,p,q;
    in(test);
    //fout;
    for(t=1;t<=test;t++)
    {
        in(a),in(b),in(k);
        if(k>100)
        {
            pf("Case %lld: 0\n",t);
            continue;
        }

        cnt=0;
        A=a;
        B=b;
        if(a>b)
            swap(a,b);
        lim1=log10(a);
        lim2=log10(b);
        a--;

        for(i=lim1;i>=0;i--)
        {
            arr[i]=a%10;
            a=a/10;
        }
        mm(dp,-1);
        p=call(0,1,0,0,lim1);

        for(i=lim2;i>=0;i--)
        {
            arr[i]=b%10;
            b=b/10;
        }

        mm(dp,-1);
        q=call(0,1,0,0,lim2);
        //pf("P = %lld Q = %lld\n",p,q);
        pf("Case %lld: %lld\n",t,q-p);
    }
    return 0;
}
