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

ll dp[1005][1005][3],arr[1005],invoke[1005],n;

ll call(ll pos,ll taken,ll onetaken)
{
    if(pos>=n)
        return 0;
    if(onetaken==1 && pos>=n-1)
        return 0;
    if(dp[pos][taken][onetaken]!=-1)
        return dp[pos][taken][onetaken];
    ll p=-1;
    if(pos==0)
        p=max((call(pos+2,taken+1,1)+arr[pos]),call(pos+1,taken,onetaken)); /// jodi kokhono pos==0 tokhon abossoi ai kaj ta e korte hobe.
    else
        p=max(call(pos+1,taken,onetaken),call(pos+2,taken+1,onetaken)+arr[pos]);

    ///******************************************    vul approach
    /*

    if(pos==0)
        p=max(call(pos+2,taken+1,1)+arr[pos]); /// jodi kokhono pos==0 tokhon abossoi ai kaj ta e korte hobe. Its not like fully 0-1 knapsack

    p=max(call(pos+1,taken,onetaken),call(pos+2,taken+1,onetaken)+arr[pos]); tar mane se again 0 pos k niye o n-1 k invoked kore ditese na, mane onetaken = 0 e rekjhe dae

    */


    return dp[pos][taken][onetaken]=p;
}

int main()
{
    ll i,j,k,test,t,p;

    in(test);
    for(t=1;t<=test;t++)
    {
        in(n);
        for(i=0;i<n;i++)
            in(arr[i]);
        mm(dp,-1);
        mm(invoke,0);
        p=call(0,0,0);
        pf("Case %lld: %lld\n",t,p);
    }
    return 0;

}
