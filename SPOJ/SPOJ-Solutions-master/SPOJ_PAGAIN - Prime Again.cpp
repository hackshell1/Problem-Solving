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
typedef unsigned long long ull;

ull Farmets(ull N,ull P,ull M)    ///****** i always used 2 as the base {(2^(n-1))%n==1 famtes Little theorm says if it is a prime mod ans will be 1}
{
    //pf("N = %lld P = %lld M = %lld\n",N,P,M);
	if(P==0) return 1;
	if(P%2==0)
	{
		ll ret=Farmets(N,P/2,M);
		return ((ret%M)*(ret%M))%M;
	}
	else return ((N%M)*(Farmets(N,P-1,M)%M))%M;
}

int main()
{
    ll test,t,i,j,p,q,a;

    //pf("%lld\n",Farmets(2,4294967290,4294967291));

    in(test);
    //fout;
    for(t=1;t<=test;t++)
    {
        in(a);
        a--;    ///************* as the problem wants me to find the nearesr prime smaller than n so i decremnted 1

        if(a==2)     /// ************* if input is 3 ans will be 2
        {
            pf("2\n");
            continue;
        }
        ll to;
        if(a-1000>=2)     ///****** it is sure that a solution will be in the interval n ---> n-1000
            to=a-1000;
        else
            to=2;
        for(i=a;i>=to;i--)
        {
            if(Farmets(2,i-1,i)==1)   ///******* i used farmets little theorm
            {
                pf("%lld\n",i);
                break;
            }
        }
    }
    return 0;
}
