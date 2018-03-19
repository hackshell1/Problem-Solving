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

S s,s1,s2;
set<S>v;

ll dp[105][105],len1,len2,chek1[26][105],chek2[26][105],last1[26],last2[26];

ll call(ll posx,ll posy)
{
    if(posx>=len1 || posy>=len2)
        return 0;
    if(dp[posx][posy]!=-1)
        return dp[posx][posy];
    ll p=0;
    if(s[posx]==s1[posy])
        p=max(call(posx+1,posy+1)+1,p);
    else
        p=max(call(posx+1,posy),call(posx,posy+1));
    return dp[posx][posy]=p;
}

void fillup1(ll p,ll x,ll y,ll z)
{
    ll i;
    for(i=x;i<=y;i++)
        chek1[p][i]=z;
    return;
}

void precal()
{
    ll i,j,k;
    for(i=0;i<len1;i++)
    {
        ll x=s[i]-'a';
        ll last=last1[x]+1;
        fillup1(x,last,i,i);
        last1[x]=i;
    }
}

void fillup2(ll p,ll x,ll y,ll z)
{
    ll i;
    for(i=x;i<=y;i++)
        chek2[p][i]=z;
    return;
}

void preca2()
{
    ll i,j,k;
    for(i=0;i<len2;i++)
    {
        ll x=s1[i]-'a';
        ll last=last2[x]+1;
        fillup2(x,last,i,i);
        last2[x]=i;
    }
}

ll path_print(char c,ll need,ll x,ll y)
{
    if(need==0)
    {
        pf("\n");
        return 1;
    }

    x=chek1[c-'a'][x];
    y=chek2[c-'a'][y];

    if(x==-1 || y==-1)
        return 0;

    if(dp[x][y]!=need)
        return 0;
    pf("%c",c);

    for(ll i=0;i<26;i++)
    {
        ll p=path_print('a'+i,need-1,x+1,y+1);
        if(p==1)
            return 1;
    }
    return 0;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    //fout;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>s>>s1;
        len1=s.length();
        len2=s1.length();

        mm(dp,-1);
        p=call(0,0);
        pf("Case %lld: ",t);
        if(p==0)
        {
            pf(":(\n");
            continue;
        }
        mm(chek1,-1);
        mm(chek2,-1);
        mm(last1,-1);
        mm(last2,-1);

        precal();
        preca2();

        for(i=0;i<26;i++)
        {
            q=path_print('a'+i,p,0,0);
            if(q==1)
                break;
        }
    }
    return 0;
}
