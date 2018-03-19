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

map<S,ll>mp;

struct ss
{
    ll a,b,c;
    ss(ll x,ll y,ll z)
    {
        a=x;
        b=y;
        c=z;
    }
};

bool compare(ss l,ss r)
{
    return l.c<r.c;
}

vector<ss>v;
vector<ll>V[10005];
ll arr[10005],vis[10005];

ll findd(ll a)
{
    if(arr[a]==a)
        return a;
    return arr[a]=findd(arr[a]);
}

ll bfs(ll a)
{
    queue<ll>q;
    q.push(a);
    vis[a]=1;
    ll cnt=0;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        ll sz=V[a].size();
        for(ll i=0;i<sz;i++)
        {
            ll x=V[a][i];
            if(vis[x]==-1)
            {
                vis[x]=1;
                q.push(x);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    in(test);
    S s1,s2;
    for(t=1;t<=test;t++)
    {
        in(n);
        mp.cl;
        cnt=0;
        for(i=1;i<=n;i++)
        {
            cin>>s1>>s2>>c;
            if(mp.find(s1)==mp.end())
            {
                mp[s1]=cnt;
                a=cnt++;
            }
            else
                a=(ll)mp[s1];

            if(mp.find(s2)==mp.end())
            {
                mp[s2]=cnt;
                b=cnt++;
            }
            else
                b=(ll)mp[s2];

            v.pb(ss(a,b,c));
        }
        ll sz=v.size();
        sort(v.begin(),v.begin()+sz,compare);

        for(i=0;i<cnt+1;i++)
            arr[i]=i;
        sum=0;
        for(i=0;i<sz;i++)
        {
            a=v[i].a;
            b=v[i].b;
            c=v[i].c;

            p=findd(a);
            q=findd(b);

            if(p==q)
                continue;
            else
            {
                arr[q]=p;
                sum+=c;
                V[a].pb(b);
                V[b].pb(a);
            }
        }
        //pf("Sum = %lld\n",sum);

        mm(vis,-1);
        p=bfs(cnt-1);
        //pf("P = %lld and Cnt = %lld\n",p,cnt);

        pf("Case %lld: ",t);
        if(p<cnt-1)
            pf("Impossible\n");
        else
            pf("%lld\n",sum);

        for(i=0;i<cnt+10;i++)
            V[i].cl;
        v.cl;
    }
    return 0;
}
