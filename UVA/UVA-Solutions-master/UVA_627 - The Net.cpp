#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
#define pb push_back
#define cl clear
#define mm(arr,a) memset(arr,a,sizeof arr)
#define fin freopen("in.txt","r",stdin)
#define fout freopen("out.txt","w",stdout)



using namespace std;
typedef long long ll;

vector<ll>v[1000];
ll parent[1000],vis[1000];

void process(string s)
{
    ll len=s.length(),i;
    ll sum=0;
    for(i=0;i<len;i++)
    {
        if(s[i]>='0' && s[i]<='9')
            sum=sum*10+(s[i]-'0');
        else
            break;
    }
    ll summ=0;
    for(i=i+1;i<len;i++)
    {
        if(s[i]>='0' && s[i]<='9')
            summ=summ*10+(s[i]-'0');
        else
        {
            v[sum].pb(summ);
            summ=0;
        }
    }
    if(summ>0)
        v[sum].pb(summ);
    return;
}

ll bfs(ll a,ll b)
{
    if(a==b)
        return 0;
    queue<ll>q;
    q.push(a);
    vis[a]=0;
    parent[a]=a;
    while(q.size()>0)
    {
        ll x=q.front();
        q.pop();
        ll sz=v[x].size();
        for(ll i=0;i<sz;i++)
        {
            ll y=v[x][i];
            if(vis[y]==-1)
            {
                q.push(y);
                vis[y]=vis[x]+1;
                parent[y]=x;
                if(y==b)
                    return vis[y];
            }
        }
    }
    return -1;
}

void print_path(ll a,ll b,ll c)
{
    vector<ll>V;
    while(1)
    {
        V.push_back(b);
        b=parent[b];
        if(b==a)
        {
            V.push_back(a);
            break;
        }
    }
    for(ll i=V.size()-1;i>=0;i--){
        pf("%lld",V[i]);
        if(i!=0)
            pf(" ");
    }
        pf("\n");
}

int main()
{
    string s;
    //fin;
    //fout;
    ll a,i,j,n,b,q,x;
    while(in(n)!=EOF)
    {
        getchar();
        for(i=1;i<=n;i++)
        {
            cin>>s;
            process(s);
        }
        in(q);
        pf("-----\n");
        for(i=1;i<=q;i++)
        {
            in(a),in(b);
            mm(vis,-1);
            mm(parent,-1);
            x=bfs(a,b);
            if(x==-1)
                pf("connection impossible\n");
            else if(x==0)
                pf("%lld\n",a);
            else
            {
                print_path(a,b,x);
            }
        }
        for(i=0;i<n+5;i++)
            v[i].clear();
    }
}
