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
#define mod %1000007
#define mid (lo+hi)/2
#define LEFT node*2
#define RIGHT (node*2)+1

using namespace std;
typedef int ll;
typedef string S;
typedef double D;

ll len1,len2,dp[1001][1001],last1[26],last2[26],precal1[26][1001],precal2[26][1001],ans[1001][1001],vis2[1001][1001],vis1[1001][1001];
char s[1001],s1[1001];

ll call(ll x,ll y,ll t)
{
    if(x>=len1 || y>=len2)
        return 0;
    if(vis1[x][y]==t)
        return dp[x][y];
    if(s[x]==s1[y])
        dp[x][y]=call(x+1,y+1,t)+1;
    else
        dp[x][y]=max(call(x+1,y,t),call(x,y+1,t));
    vis1[x][y]=t;
    return dp[x][y];
}

void fillup1(ll last,ll x,ll y)
{
    ll i,j,k;
    for(i=last;i<=x;i++)
        precal1[y][i]=x;
    return;
}

void fillup2(ll last,ll x,ll y)
{
    ll i,j,k;
    if(last>x)
        swap(x,last);
    for(i=last;i<=x;i++)
        precal2[y][i]=x;
    return;
}

void calc()
{
    ll i,j,x,k,last;
    for(i=0;i<len1;i++)
    {
        x=s[i]-'a';
        last=last1[x]+1;
        last1[x]=i;
        fillup1(last,i,x);
    }
    for(i=0;i<len2;i++)
    {
        x=s1[i]-'a';
        last=last2[x]+1;
        last2[x]=i;
        fillup2(last,i,x);
    }
}

ll findall(ll x,ll y,ll need,ll t)
{
    if(need==0)
        return 1;
    if(x>=len1 || y>=len2)
        return 0;
    if(vis2[x][y]==t)
        return ans[x][y];
    ll p=0;
    for(ll i=0;i<26;i++)
    {
        ll xx=precal1[i][x];
        ll yy=precal2[i][y];
        if(xx==-1 || yy==-1)
            continue;
        if(dp[xx][yy]==need)
            p+=findall(xx+1,yy+1,need-1,t);
    }
    vis2[x][y]=t;
    return ans[x][y]=p mod;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,sum=0,c;
    //fin;
    //fout;
    scanf("%d",&test);
    mm(vis1,-1);
    mm(vis2,-1);
    getchar();
    for(t=1;t<=test;t++)
    {
        scanf("%s%s",s,s1);

        /*for(i=0;i<len1;i++)
        {
            x=s[i]-'a';
            if(precal1[x][0]==-1)
                for(j=0;j<len1;j++)
                    precal1[x][j]=-1;
        }

        for(i=0;i<len2;i++)
        {
            x=s1[i]-'a';
            if(precal2[x][0]==-1)
                for(j=0;j<len2;j++)
                    precal2[x][j]=-1;
        }*/


        len1=strlen(s);
        len2=strlen(s1);
        //mm(dp,-1);


        //mm(vis1,-1);
        //mm(vis2,-1);
        mm(precal1,-1);
        mm(precal2,-1);

        p=call(0,0,t);
        mm(last1,-1);
        mm(last2,-1);
        calc();

        //mm(ans,-1);
        //mm(vis2,-1);
        q=findall(0,0,p,t);
        //pf("P = %lld Q = %lld\n",p,q);

        pf("Case %d: %d\n",t,q);
    }
}
