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

ll vis[1000005];

ll chek(ll x)
{
    ll ans=0;
    while(x>0)
    {
        ans+=(x%10)*(x%10);
        x=x/10;
    }
    return ans;
}

map<ll,ll>mp,MP;

int main()
{
    ll a,b,ans,i,j,cnt,x,y;
    while(in(a),in(b))
    {
        if(a==0 && b==0)
            break;

        ll x=a,y=b;

        cnt=1;
        ll minn=1e10;
        while(mp.find(a)==mp.end())
        {
            //pf("A = %lld in cnt = %lld\n",a,cnt);
            mp[a]=cnt++;
            a=chek(a);
        }
        cnt=1;
        while(MP.find(b)==MP.end())
        {
            //pf("B = %lld Cnt = %lld\n",b,cnt);

            if(mp.find(b)!=mp.end()){
                minn=min(minn,mp.find(b)->second+cnt);
                //cout<<mp.find(b)->first<<"  "<<mp.find(b)->second<<"\n";
            }
            MP[b]=cnt++;
            b=chek(b);
        }

        pf("%lld %lld %lld\n",x,y,minn==1e10?0:minn);
        mp.cl;
        MP.cl;


    }
    return 0;
}
