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


using namespace std;
typedef long long ll;

ll chek (ll n)
{
    ll lim=log2(n),start=-1,x,p,q,r;
    if((1<<lim)==n)
        return n*2;
    if(n==(1<<(lim+1))-1)
    {
        r=n;
        n=1<<(lim+1);
        r>>=1;
        n=n|r;
        return n;
    }
    for(ll i=0;i<=lim;i++)
    {
        if(start==-1 && (n&(1<<i))!=0)
            start=i;
        if(start!=-1 && (n&(1<<i))==0)
        {
            ll endd=i-1;
            n=n|(1<<i);
            n=n>>(endd+1);
            n=n<<(endd+1);
            r=0;
            for(ll j=0;j<endd-start;j++)
                r|=1<<j;
            n=n|r;
            return n;
        }
    }
    lim=log2(n);
    r=1<<(lim+1);
    n=n>>(start+1);
    n=n|r;
    return n;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0;
    //fout;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n);
        x=chek(n);
            pf("Case %lld: %lld\n",t,x);
    }
    return 0;
}
