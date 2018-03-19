#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
#define mm(arr,a) memset(arr,a,sizeof(arr))
#define inf 1<<30
#define pb push_back
#define fin freopen("in.txt","r",stdin)
#define fout freopen("out.txt","w",stdout)

using namespace std;
typedef long long ll;

vector<string>st;
vector<ll>v[1000];

ll parent[1100],vis[1100];

ll findd(string s)
{
    ll sz=st.size(),i;
    for(i=0;i<sz;i++)
        if(st[i]==s)
            return i;
    st.pb(s);
    return sz;
}

ll bfs(ll a,ll b)
{
    queue<ll>q;
    ll u,sz,i,j,x,y;
    if(a==b)
        return 0;
    q.push(a);
    vis[a]=0;
    parent[a]=a;
    while(q.size()>0)
    {
        x=q.front();
        q.pop();
        sz=v[x].size();
        for(i=0;i<sz;i++)
        {
            y=v[x][i];
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


void print_path(ll a,ll b)
{
    vector<ll>V;
    while(1)
    {
        V.pb(b);
        b=parent[b];
        if(parent[b]==b){
            V.push_back(b);
            break;
        }
    }
    ll sz=V.size();
    //pf("SZ = %lld\n",sz);
    for(ll i=sz-1;i>0;i--)
        cout<<st[V[i]]<<" "<<st[V[i-1]]<<endl;
    V.clear();
    return;
}



int main()
{
    string s;
    //fout;
    ll a,b,i,n;
    ll cnt=0;
    while(in(n)!=EOF)
    {
        if(cnt!=0)
            pf("\n");
        for(i=0;i<n;i++)
        {
            cin>>s;
            a=findd(s);
            cin>>s;
            b=findd(s);
            v[a].pb(b);
            v[b].pb(a);
        }
        cin>>s;
        a=findd(s);
        cin>>s;
        b=findd(s);
        mm(parent,-1);
        mm(vis,-1);
        ll x=bfs(a,b);
        //pf("X = %lld for a = %lld b = %lld\n",x,a,b);
        if(x==-1)
            pf("No route\n");
        else
        {
            if(x==0)
                cout<<st[a]<<" "<<st[a]<<endl;
            else
                print_path(a,b);
        }
        ll sz=st.size();
        for(i=0;i<sz+1;i++)
            v[i].clear();
        st.clear();
        cnt++;
    }
}
