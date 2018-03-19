#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
#define inf 1<<30

using namespace std;
typedef long long ll;

char s[10000];
ll arr[1005][1005],a,b,vis[1005][1005];

ll call(ll i,ll j,ll k,ll l)
{
    if(i<0 || i>=a || j<0 || j>=b)
        return inf;
    if(arr[i][j]==1)
        return inf;
    if(vis[i][j]>-1)
        return vis[i][j];
    if(i==k && j==l)
        return 1;
    ll p=inf;
    if(vis[i][j]<=-1)
        vis[i][j]=inf;
    p=min(p,call(i,j+1,k,l));
    p=min(p,call(i,j-1,k,l));
    p=min(p,call(i-1,j,k,l));
    p=min(p,call(i+1,j,k,l));
    if(vis[i][j]==-1)
        return vis[i][j]=p+1;
    if(vis[i][j]<p+1)
        return vis[i][j];
    return vis[i][j]=p+1;
}

int main()
{
    ll i,test,t,n,j,len,x;
    while(in(a),in(b))
    {
        if(a==0 && b==0)
            break;
        in(test);
        getchar();
        memset(arr,0,sizeof(arr));
        memset(vis,-1,sizeof(vis));
        for(t=1;t<=test;t++)
        {
            ll y;
            in(y);
            in(n);
            for(i=0;i<n;i++)
            {
                in(x);
                arr[y][x]=1;
            }
        }
        ll x,y,z,zz;
        in(x),in(y),in(z),in(zz);
        ll p=call(x,y,z,zz);
        pf("%lld\n",p-1);
    }
    return 0;
}
