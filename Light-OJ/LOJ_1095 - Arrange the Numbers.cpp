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

ll ncr[1090][1090],D_val[2005];

ll findd_D_val(ll x)
{
    if(x==0)
        return 0;
    if(x==1)
        return 0;
    if(x==2)
        return 1;
    if(D_val[x]!=-1)
        return D_val[x];
    return D_val[x]=((x-1)*((findd_D_val(x-1)%mod+findd_D_val(x-2)%mod))%mod)%mod;
}

ll NCR(ll n,ll r)
{
    if(n==r)
        return 1;
    if(r==1)
        return n;
    if(ncr[n][r]!=-1)
        return ncr[n][r];
    return ncr[n][r]=( NCR(n-1,r-1)%mod + NCR(n-1,r)%mod )%mod;
}

ll makeans(ll x,ll y)
{
    ll sum=D_val[x],i;
    for(i=1;i<=y;i++)
        sum+=(ncr[y][i]*D_val[x+i])%mod;
    return sum;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c,ans;
    string s,s1,s2;

    mm(ncr,-1);
    for(i=1;i<=1005;i++)
        for(j=1;j<=i;j++)
            ncr[i][j]=NCR(i,j);

    mm(D_val,-1);
    D_val[0]=1;
    D_val[1]=0;
    D_val[2]=1;
    findd_D_val(2000);

    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(m),in(k);
        ans=0;
        ans=ncr[m][k];


        a=n-m;
        b=m-k;
        sum=0;

        sum+=D_val[b];
        for(i=1;i<=a;i++)
            sum=(sum%mod + (ncr[a][i]%mod*D_val[b+i])%mod)%mod;
        ans=(ans%mod * sum%mod)%mod;

        pf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}
