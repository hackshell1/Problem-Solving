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
#define mod 1000000007
#define mid (lo+hi)/2
#define LEFT node*2
#define RIGHT (node*2)+1
#define maxn log2(100008)+1

using namespace std;
typedef long long ll;
typedef string S;
typedef double D;

S s;
ll len;

struct ss
{
    ll a,b,pos;
}arrr[100005];

bool compare(ss l,ss r)
{
    if(l.a==r.a)
        return l.b<r.b;
    return l.a<r.a;
}

ll arr[20][100008];

ll suffix_array()
{
    //cout<<s<<endl;

    ll lim=log2(len)+1,i,j;
    for(i=1;i<=lim;i++)
    {
        ll right=(1<<i-1);
        for(j=0;j<len;j++)
        {
            arrr[j].a=arr[i-1][j];
            arrr[j].b=j+right>=len?-1:arr[i-1][j+right];
            arrr[j].pos=j;
        }
        sort(arrr,arrr+len,compare);
        ll cnt=1;
        arr[i][arrr[0].pos]=cnt;
        for(j=1;j<len;j++)
            arr[i][arrr[j].pos]=(arrr[j].a==arrr[j-1].a?(arrr[j].b==arrr[j-1].b?cnt:++cnt):++cnt);

    }

    ll pos;
    /*for(i=1;i<=len;i++)
        pf("%3lld ",i);
    pf("\n\n");

    for(i=0;i<lim;i++)
    {
        for(j=0;j<len;j++)
            pf("%3lld ",arr[i][j]);
        pf("\n");
    }*/

    ll minn=100000000000,p=-1;
    lim=log2(len/2);
    //pf("Lim = %lld\n",lim);
    for(i=0;i<=len/2;i++)
    {
        if(arr[lim][i]<minn)
        {
            minn=arr[lim][i];
            p=i;
        }
    }
    //pf("P=  %lld Minn = %lld\n",p,minn);
    return p;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,sum=0,c;

    cin>>n;
    for(t=1;t<=n;t++)
    {
        cin>>len>>s;
        /*for(i=0;i<len/2;i++)
            swap(s[i],s[len-i-1]);*/
        len+=len;
        s+=s;
        for(i=0;i<len;i++)
            arr[0][i]=s[i]-'a'+1;


        p=suffix_array();
        pf("%lld\n",p);
    }
    return 0;
}

