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

ll t,n,dp1[100005],dp2[100005],arr[100005];

ll callinc(ll pos,ll last)
{
    pf("Pos = %lld Last = %lld\n",pos,last);
    if(pos>=n)
        return 0;
    if(dp1[pos]!=-1)
        return dp1[pos];
    ll p=0;
    p=callinc(pos+1,last);
    pf("In pos %lld not taking %lld p = %lld where last = %lld\n",pos,arr[pos],p,last);
    if(arr[pos]>last)
    {
        p=max(p,callinc(pos+1,arr[pos])+1);
        pf("In pos = %lld taking %lld  p =%lld where last = %lld\n",pos,arr[pos],p,last);
    }
    pf("From pos = %lld taking last = %lld max = %lld\n\n\n",pos,last,p);
    return dp1[pos]=p;
}

ll calldec(ll pos,ll last)
{
    //pf("pos = %lld last = %lld\n",pos,last);
    if(pos>=n)
        return 0;
    if(dp2[pos]!=-1)
        return dp2[pos];
    ll p=0;
    p=calldec(pos+1,last);
    if(arr[pos]<last)
        p=max(p,calldec(pos+1,arr[pos])+1);
    return dp2[pos]=p;
}

int main()
{
    ll p,test,i,q;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n);

        for(i=0;i<n;i++)
            in(arr[i]);

        mm(dp1,-1);
        mm(dp2,-1);
        p=callinc(0,-1e10);
        q=calldec(0,1e10);
        pf("P = %lld Q = %lld\n",p,q);
    }
}
