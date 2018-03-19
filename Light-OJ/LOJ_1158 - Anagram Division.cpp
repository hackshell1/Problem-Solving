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

char s[12];
ll dp[(1<<10)+1][1001],vis[(1<<10)+1][1001],counter[10];
ll factorial[20],t,n,k;

void fac(ll x)
{
    ll i,sum=1;
    factorial[0]=1;
    for(i=1;i<=x;i++)
        factorial[i]=factorial[i-1]*i;
    return;
}

ll chek(ll mask,ll pos)
{
    if((mask&(1<<pos))==0)
        return 0;
    return 1;
}

ll sett(ll mask,ll pos)
{
    return mask|(1<<pos);
}

ll call(ll mask,ll modd)
{
    if(mask==((1<<n)-1))
    {
        if(modd==0)
            return 1;
        return 0;
    }

    if(vis[mask][modd]==t)
        return dp[mask][modd];

    ll p=0,i,x,number;
    for(i=0;i<n;i++)
    {
        if(chek(mask,i)==0){
            x=(modd*10)+(s[i]-'0');
            if(x>=k)
                x=x%k;

            number=(modd*10)+s[i]-'0';
            p+=call(sett(mask,i),x);
        }
    }
    vis[mask][modd]=t;
    return dp[mask][modd]=p;
}

int main()
{
    ll i,j,m,x,cnt=0,count=0,y,p,q,maxx=0,minn=1<<30,a,b,test=0,sum=0,c;
    fac(15);
    cin>>test;
    mm(vis,-1);
    //fout;
    for(t=1;t<=test;t++)
    {
        getchar();
        cin>>s>>k;
        n=strlen(s);
        sort(s,s+n);
        cnt=0;
        mm(counter,0);
        for(i=0;i<n;i++)
            counter[s[i]-'0']++;

        p=call(0,0);
        //pf("Sz = %lld\n",(ll)v.size());

        for(i=0;i<=9;i++)
            p=p/factorial[counter[i]];

        pf("Case %lld: %lld\n",t,p);
    }
    return 0;
}
