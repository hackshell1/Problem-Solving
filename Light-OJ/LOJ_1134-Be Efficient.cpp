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

ll arr[100005],countt[100005];

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    in(test);
    for(t=1;t<=test;t++)
    {
        in(n),in(k);
        p=0;
        for(i=0;i<n;i++)
        {
            in(arr[i]);
            arr[i]%=k;
        }
        countt[arr[0]]++;

        for(i=1;i<n;i++){
            arr[i]=(arr[i-1]+arr[i])%k;
            if(arr[i]==0)
                p++;
        }
        if(arr[0]==0)
            p++;

        mm(countt,0);
        countt[arr[0]]++;
        for(i=1;i<n;i++)
        {
            if(countt[arr[i]]>0)
                p+=countt[arr[i]];
            countt[arr[i]]++;
        }
        pf("Case %lld: %lld\n",t,p);
    }
    return 0;
}
