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


using namespace std;
typedef long long ll;


ll arr[10005],enemy[10005];


ll findd(ll x)
{
    if(arr[x]==x)
        return x;
    return  arr[x]=findd(arr[x]);
}


int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    //fout;
    while(in(n)!=EOF)
    {

        for(i=0;i<=n;i++)
            arr[i]=i;
        mm(enemy,-1);

        while(in(a),in(b),in(c))
        {
            x=findd(a);
            y=findd(b);
            if(a==3)
            {
                if(x==y)
                    pf("1\n");
                else
                    pf("0\n");
            }
            if(a==4)
            {
                if(x==y)
                    pf("0\n");
                else
                {
                    if(enemy[y]==x || enemy[x]==y)
                        pf("1\n");
                    else
                        pf("0\n");
                }
            }
        }
    }
    return 0;
}

