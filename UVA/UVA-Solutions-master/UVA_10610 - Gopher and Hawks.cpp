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

ll max_even(ll x)
{
    if(x%2==0)
        return x;
    return x-1;
}

ll min_odd(ll x)
{
    if(x%2==0)
        return x-1;
    return x;
}

string itoaa(ll n)
{
    char x[100]={'\0'};
    ll lim=log10(n);
    for(ll i=lim;i>=0;i--)
    {
        x[i]=(n%10)+'0';
        n=n/10;
    }
    string r=x;
    return r;
}

ll gcd(ll a,ll b)
{
    while(1)
    {
        if(b%a==0)
            return a;
        if(a==1)
            return 1;
        ll x=a;
        a=b%a;
        b=x;
    }
    return 1;
}

ll poww(ll x,ll n)
{
    ll sum=1,i;
    for(i=1;i<=n;i++)
        sum*=x;
    return sum;
}

ll upr_bnd(ll x,ll siz,ll *arr)
{
    return upper_bound(arr,arr+siz,x)-arr;
}

ll lr_bnd(ll x,ll siz,ll *arr)
{
    return lower_bound(arr,arr+siz,x)-arr;
}

ll int_point_distance(ll x1,ll y1,ll x2,ll y2)
{
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

float float_point_distance(float x1,float y1,float x2,float y2)
{
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

void arrin(ll *arr,ll lo,ll hi)
{
    ll i;
    for(i=lo;i<=hi;i++)
        in(arr[i]);
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,velocity;
    float x1,y1,x2,y2;
    while(cin>>velocity,cin>>m)
    {
        if(velocity==0 && m==0)
            break;
        cin>>x1>>y1;
        cin>>x2>>y2;

    }
}

