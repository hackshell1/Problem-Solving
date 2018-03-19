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

#define pi acos(-1.0)
#define in(a) scanf("%lld",&a)
#define mm(arr,x) memset(arr,x,sizeof(arr))
#define pf printf
#define fin freopen("in.txt","r",stdin)
#define fout freopen("out.txt","w",stdout)
#define pb push_back
#define sq(x) ((x)*(x))
#define Sqrt(n) (long long)round(sqrt((double)n))
#define cl clear()


using namespace std;
typedef long long ll;

vector<ll>G[1000];
vector<char>V;
float arr[10000];
ll vis[1000];

ll findd(char ch)
{
    ll sz=V.size(),i;
    for(i=0;i<sz;i++)
        if(V[i]==ch)
            return i;
    V.pb(ch);
    return sz;
}

void process(string s,ll x)
{
    ll len=s.length(),i,y;
    for(i=0;i<len;i++)
    {
        if(s[i]==V[x])
            continue;
        if(s[i]!='*'){
            y=findd(s[i]);
            G[x].pb(y);
            G[y].pb(x);
        }
        else
        {
            G[x].pb(0);
            G[0].pb(x);
        }
    }
    return;
}

void bfs(ll root)
{
    queue<ll>q;
    q.push(root);
    vis[root]=0;
    while(q.size()>0)
    {
        ll x=q.front();
        q.pop();
        ll sz=G[x].size();
        for(ll i=0;i<sz;i++)
        {
            ll y=G[x][i];
            if(vis[y]==-1)
            {
                vis[y]=vis[x]+1;
                q.push(y);
            }
        }
    }
    return;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0;
    char ch;
    float f;
    string s;
    //fout;
    while(cin>>n)
    {
        float maxx=-100000.0;
        getchar();
        for(i=0;i<n+10;i++)
            arr[i]=0.00;
        V.pb('*');
        for(i=0;i<n;i++)
        {
            cin>>ch;
            cin>>f;
            cin>>s;
            x=findd(ch);
            arr[x]=f;
            process(s,x);
        }
        mm(vis,-1);
        bfs(0);
        ll pos=-1;
        for(i=1;i<V.size();i++)
        {
            ll r;
            if(vis[i]==-1)
                continue;
            if(vis[i]==1)
                r=0;

            else
                r=vis[i]-1;

            f=arr[i]-((5*r*arr[i])/100);
            if(f==maxx)
            {
                if(V[i]<V[pos])
                    pos=i;
            }
            else if(f>maxx)
            {
                maxx=f;
                pos=i;
            }

        }

        pf("Import from %c\n",V[pos]);

        ll sz=V.size();
        for(i=0;i<sz+10;i++)
            G[i].cl;
        V.cl;
    }
    return 0;
}
