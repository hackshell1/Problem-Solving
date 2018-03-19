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
typedef char C;

vector<char>v;

ll findd(char c)
{
    ll i,sz=v.size();
    for(i=0;i<sz;i++)
        if(v[i]==c)
            return i;
    v.pb(c);
    return sz;
}

C s[30];

ll n,arr[30],len,dp[21][1<<20],vis[21][1<<20],siz;

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

ll call(ll pos,ll mask,ll test)
{
    pf("Pos = %lld Mask = %lld\n",pos,mask);
    if(mask==(1<<len))
        return 1;
    if(vis[pos][mask]==test)
        return dp[pos][mask];
    ll i,p=0,x=arr[pos];
    for(i=0;i<len;i++)
    {
        if(chek(mask,i)==0)
        {
            arr[pos]--;
            if(arr[pos]==0)
                p+=call(pos+1,sett(mask,i),test);
            else
                p+=call(pos,sett(mask,i),test);
        }
    }
    arr[pos]=x;
    vis[pos][mask]=test;
    return dp[pos][mask]=p;
}

int main()
{
    ll test,t,i,p;
    mm(vis,-1);
    in(test);
    for(t=1;t<=test;t++)
    {
        getchar();
        mm(arr,0);
        scanf("%s%lld",s,&n);
        len=strlen(s);
        sort(s,s+len);
        for(i=0;i<len;i++)
            arr[findd(s[i])]++;
        siz=v.size();
        p=call(0,0,t);
        pf("P = %lld\n",p);
    }
}

