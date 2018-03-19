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
#define mid (lo+hi)/2
#define LEFT node*2
#define RIGHT (node*2)+1

using namespace std;
typedef unsigned long long ll;
typedef string S;
typedef double D;

ll n,m,t,bit[109],dp[108][(1<<9)+10],a,b,vis[109][(1<<9)+10],mod;

ll chek(ll pos,ll mask)
{
    if(pos>=m || pos<0)
        return 1;
    if((mask & (1<<pos))==0)
        return 0;
    return 1;
}

ll sett(ll pos,ll mask)
{
    return mask | (1<<pos);
}

ll process1(ll pos,ll mask1,ll mask2)
{
    if(chek(pos,mask1)==0 && chek(pos,mask2)==0)
    {
        a=sett(pos,a);
        b=sett(pos,b);
        return 1;
    }
    return 0;
}

ll process2(ll pos,ll mask1,ll mask2)
{
    if(chek(pos,mask1)==0 && chek(pos+1,mask1)==0)
    {
        a=sett(pos,a);
        a=sett(pos+1,a);
        b=b;
        return 1;
    }
    return 0;
}

ll process3(ll pos,ll mask1,ll mask2)
{
    if(chek(pos,mask1)==0 && chek(pos,mask2)==0 && chek(pos+1,mask2)==0)
    {
        a=sett(pos,a);
        b=sett(pos,b);
        b=sett(pos+1,b);
        return 1;
    }
    return 0;
}

ll process4(ll pos,ll mask1,ll mask2)
{
    if(chek(pos,mask1)==0 && chek(pos+1,mask1)==0 && chek(pos,mask2)==0)
    {
        a=sett(pos,a);
        a=sett(pos+1,a);
        b=sett(pos,b);
        return 1;
    }
    return 0;
}

ll process5(ll pos,ll mask1,ll mask2)
{
    if(chek(pos,mask1)==0 && chek(pos,mask2)==0 && chek(pos-1,mask2)==0)
    {
        a=sett(pos,a);
        b=sett(pos-1,b);
        b=sett(pos,b);
        return 1;
    }
    return 0;
}

ll process6(ll pos,ll mask1,ll mask2)
{
    if(chek(pos,mask1)==0 && chek(pos+1,mask1)==0 && chek(pos+1,mask2)==0)
    {
        a=sett(pos,a);
        a=sett(pos+1,a);
        b=sett(pos+1,mask2);
        return 1;
    }
    return 0;
}

ll process(ll x,ll pos,ll mask1,ll mask2)
{
    a=mask1;
    b=mask2;
    if(x==1)
        return process1(pos,mask1,mask2);
    if(x==2)
        return process2(pos,mask1,mask2);
    if(x==3)
        return process3(pos,mask1,mask2);
    if(x==4)
        return process4(pos,mask1,mask2);
    if(x==5)
        return process5(pos,mask1,mask2);
    if(x==6)
        return process6(pos,mask1,mask2);
    return 0;
}

ll call(ll pos,ll mask);

ll call2(ll pos,ll clm,ll mask1,ll mask2)
{
    if(clm>=m)
    {
        if(mask1==(1<<m)-1)
            return call(pos+1,mask2);  /// when i am in the clm number of m we get in the next row if and only if the current row is full with tiles
        return 0;
    }

    ll p=0,i;
    if(chek(clm,mask1)!=0)
        return call2(pos,clm+1,mask1,mask2)%mod;  /// if anyway i get the section of mask tiles is filled with another one tiles i will skip that colum of mask and then i will go ahed of that row mask
    for(i=1;i<=6;i++)
    {
        if(process(i,clm,mask1,mask2)==1){
            x=call(pos,clm+1,a,b);
            if(mod-x<)
            p=(p%mod+call2(pos,clm+1,a,b)%mod)%mod;
        }
    }
    return p;
}

ll call(ll pos,ll mask)
{
    //pf("pos = %lld Mask = %lld\n",pos,mask);
    if(pos==n)
        return 1;
    if(vis[pos][mask]==t)
        return dp[pos][mask];
        ll p=0;
    p=call2(pos,0,mask,bit[pos+1])%mod;
    vis[pos][mask]=t;
    return dp[pos][mask]=p;
}

int main()
{
    ll test,i,sum,j,p;
    mod=18446744073709551615;
    //freopen("outt.txt","w",stdout);
    cin>>test;
    char arr[105][105];
    mm(vis,0);
    mm(dp,0);
    for(t=1;t<=test;t++)
    {
        cin>>n>>m;

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>arr[i][j];

        if(n<m)
        {
            for(i=0;i<n;i++)
                for(j=0;j<m;j++)
                    swap(arr[i][j],arr[j][i]);
            swap(m,n);
        }

        /*for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                pf("%c",arr[i][j]);
            pf("\n");
        }*/

        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<m;j++)
            {
                sum<<=1;
                if(arr[i][j]=='#')
                    sum|=1;
            }
            bit[i]=sum;
        }
        bit[n]=bit[n+1]=bit[n+2]=(1<<m)-1;

        p=call(0,bit[0]);
        pf("Case %llu: %llu\n",t,p);
    }
    return 0;
}
