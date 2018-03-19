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

#define inf 1<<29
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

char s[100];
ll len,base,k,dp[(1<<16)][20],arr[50],vis[1<<(16)][20];

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

ll call(ll mask,ll kmean,ll t)
{
    if(mask==(1<<len)-1)
    {
        //pf("Mask = %lld and kmn = %lld\n",mask,kmean);
        if(kmean==0)
            return 1;
        return 0;
    }
    if(vis[mask][kmean]==t)
        return dp[mask][kmean];
    ll p=0,i,a,x;

    for(i=0;i<len;i++)
    {
        if(chek(mask,i)==0)
        {
            a=(kmean*base)+arr[i];
            x=a%k;
            p+=call(sett(mask,i),x,t);
        }
    }
    vis[mask][kmean]=t;
    return dp[mask][kmean]=p;
}

int main()
{
    ll test,t,i,p;
    //fout;
    in(test);
    mm(vis,-1);
    for(t=1;t<=test;t++)
    {
        in(base),in(k);
        getchar();
        scanf("%s",s);
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]>='A' && s[i]<='Z')
                arr[i]=s[i]-'A'+10;
            else
                arr[i]=s[i]-'0';
        }
        p=call(0,0,t);
        pf("Case %lld: %lld\n",t,p);
    }
    return 0;
}
