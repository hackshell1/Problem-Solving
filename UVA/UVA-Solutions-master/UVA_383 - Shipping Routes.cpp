#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
#define mm(arr,x) memset(arr,x,sizeof(arr))
#define pb push_back
#define fout freopen("out.txt","w",stdout)
#define cl clear()

using namespace std;
typedef long long ll;

vector<string>v;
vector<ll>vv[300];
ll vis[10000];

ll findd(string s,ll sz)
{
    for(ll i=0;i<sz;i++)
        if(v[i]==s)
            return i;
    return -1;
}

ll bfs(ll a,ll b)
{
    mm(vis,-1);
    ll i,j,x,y;
    queue<ll>q;
    q.push(a);
    vis[a]=0;
    while(q.size()>0)
    {
        x=q.front();
        q.pop();
        ll sz=vv[x].size();
        for(i=0;i<sz;i++)
        {
            y=vv[x][i];
            if(vis[y]==-1)
            {
                q.push(y);
                vis[y]=vis[x]+1;
                if(y==b)
                    return vis[y];
            }
        }
    }
    return -1;
}

int main()
{
    ll test,t,i,m,n,p,j,a,b,sz,wt;
    fout;
    pf("SHIPPING ROUTES OUTPUT\n");
    in(test);
    string s;
    for(t=1;t<=test;t++)
    {
        pf("\nDATA SET  %lld\n\n",t);
        in(m),in(n),in(p);
        getchar();
        for(i=1;i<=m;i++){
            cin>>s;
            v.pb(s);
        }
        ll sz=v.size();
        for(i=1;i<=n;i++)
        {
            cin>>s;
            a=findd(s,sz);
            cin>>s;
            b=findd(s,sz);
            vv[a].pb(b);
            vv[b].pb(a);
        }
        getchar();
        for(i=0;i<p;i++)
        {
            in(wt);
            cin>>s;
            a=findd(s,sz);
            cin>>s;
            b=findd(s,sz);
            if(a==-1 || b==-1)
            {
                pf("NO SHIPMENT POSSIBLE\n");
                continue;
            }
            ll x=bfs(a,b);
            if(x==-1)
            {
                pf("NO SHIPMENT POSSIBLE\n");
                continue;
            }
            pf("$%lld\n",x*100*wt);
        }
        for(i=0;i<m+5;i++)
            vv[i].cl;
    }
    pf("\nEND OF OUTPUT\n");
    return 0;
}
