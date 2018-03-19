#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
#define mm(arr,a) memset(arr,a,sizeof(arr))
#define fout freopen("out.txt","w",stdout)
#define inf 1<<30
#define pb push_back

using namespace std;
typedef long long ll;

ll arr[305][305],dp[40][305][305],dir[305][305];

vector<ll>v;
ll test;

ll call(ll t,ll a,ll b)
{
    if(t==test)
    {
        if(a==0 && b==0)
            return 0;
        return inf;
    }
    if(a<=0 && b<=0)
        return inf;
    if(dp[t][a][b]!=-1)
        return dp[t][a][b];
    ll x=v[t];
    ll minn=inf,nn,p;
    ll pos=0;
    for(ll i=0;i<=x;i++)
    {
        p=call(t+1,a-i,b-(x-i))+arr[t*2][i]+arr[1+t*2][x-i];
        if(p<minn)
            dir[a][b]=i;
        minn=min(minn,p);
    }
    return dp[t][a][b]=minn;
}

void print_path(ll n,ll a,ll b)
{
    if(a==0 && b==0)
        return;
    if(n<=test)
        pf("%lld ",dir[a][b]);
    print_path(n+1,a-dir[a][b],b+dir[a][b]-v[n]);
    return;
}

int main()
{
    ll t,r,x,i,j,a,b;
    while(in(a),in(b))
    {
        if(a==0 && b==0)
            break;
        in(test);
        r=0;
        mm(dp,-1);
        for(t=0;t<test;t++)
        {
            in(x);
            v.push_back(x);
            arr[t*2][0]=0;
            arr[1+t*2][0]=0;
            for(j=1;j<=x;j++)
                in(arr[r][j]);
            r++;
            for(j=1;j<=x;j++)
                in(arr[r][j]);
            r++;
        }
        ll x=call(0,a,b);
        pf("%lld\n",x);
        print_path(0,a,b);
        printf("\n");
        v.clear();
    }
    return 0;
}
