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

ll t,n,m,bit[15],dp[9][(1<<8)+1][(1<<8)+1];

ll chek(ll pos,ll mask)
{
    if(pos>=m || pos<0)
        return 0;
    if((mask & (1<<pos))==0)
        return 0;
    return 1;
}

ll sett1(ll pos,ll mask)
{
    if(pos>=m || pos<0)
        return mask;
    return mask | (1<<pos);
}

ll sett0(ll pos,ll mask)
{
    if(pos>=m || pos<0)
        return mask;
    return mask & (~(1<<pos));
}

ll process(ll row,ll pos,ll mask)
{
    if(row<0 || row>=n)
        return mask;
    if(chek(pos-1,mask)==0)
        mask=sett1(pos-1,mask);
    else
        mask=sett0(pos-1,mask);

    if(chek(pos,mask)==0)
        mask=sett1(pos,mask);
    else
        mask=sett0(pos,mask);

    if(chek(pos+1,mask)==0)
        mask=sett1(pos+1,mask);
    else
        mask=sett0(pos+1,mask);

    return mask;
}

ll call(ll pos,ll last,ll curr);

ll call2(ll pos,ll clm,ll last,ll curr,ll next)
{
    if(clm>=m)
    {
        if(last==(1<<m)-1)
            return call(pos+1,curr,next);
        return 1e10;
    }
    ll p=0;
    return p=min(call2(pos,clm+1,last,curr,next),call2(pos,clm+1,process(pos-1,clm,last),process(pos,clm,curr),process(pos+1,clm,next))+1);
}

ll call(ll pos,ll last,ll curr)
{
    if(pos>=n)
    {
        if(last==(1<<m)-1)
            return 0;
        return 1e10;
    }
    if(dp[pos][last][curr]!=-1)
        return dp[pos][last][curr];
    return dp[pos][last][curr]=call2(pos,0,last,curr,bit[pos+1]);
}

int main()
{
    ll p,test,i,j,sum;
    char s[10];
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(m);
        getchar();
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            sum=0;
            for(j=0;j<m;j++)
            {
                sum=sum<<1;
                if(s[j]=='*')
                    sum|=1;
            }
            bit[i]=sum;
        }
        bit[n]=bit[n+1]=bit[n+2]=(1<<m)-1;

        mm(dp,-1);
        p=call(0,(1<<m)-1,bit[0]);
        if(p==1e10)
            pf("Case %lld: impossible\n",t);
        else
            pf("Case %lld: %lld\n",t,p);
    }
    return 0;
}
