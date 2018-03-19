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

string s,s1,s2;
ll len1,len2,dp[35][35],getting[35][35][100];

ll call(ll posx,ll posy)
{
    if(posx>=len1 || posy>=len2)
        return 0;
    if(dp[posx][posy]!=-1)
        return dp[posx][posy];
    if(s[posx]==s1[posy])
        return dp[posx][posy]=max(dp[posx][posy],call(posx+1,posy+1)+1);
    return dp[posx][posy]=max(max(dp[posx][posy],call(posx+1,posy)),call(posx,posy+1));
}

ll getall(ll posx,ll posy,ll len)
{
    //pf("Len  = %lld\n",len);
    if(posx>=len1 && posy>=len2)
    {
        if(len>0)
            return 0;
        return 1;
    }
    if(len<=0)
        return 0;
    if(posx>=len1 && posy<len2)
        return getting[posx][posy][len]=getall(posx,posy+1,len-1);
    if(posx<len1 && posy>=len2)
        return getting[posx][posy][len]=getall(posx+1,posy,len-1);
    if(getting[posx][posy][len]!=-1)
        return getting[posx][posy][len];
    if(s[posx]==s1[posy])
        return getting[posx][posy][len]=getall(posx+1,posy+1,len-1);
    return getting[posx][posy][len]=getall(posx,posy+1,len-1)+getall(posx+1,posy,len-1);
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>s>>s1;
        len1=s.length();
        len2=s1.length();
        mm(dp,-1);
        p=call(0,0);
        pf("Case %lld: %lld ",t,len1+len2-p);
        mm(getting,-1);
        pf("%lld\n",getall(0,0,len1+len2-p));
    }
    return 0;
}
