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

ll arr[10005],vis[10005],sit[10005],booked;

ll findd(ll a)
{
    if(vis[a]!=-1)
        booked=1;
    if(arr[a]<=-1)
        return a;
    return arr[a]=findd(arr[a]);
}


bool compare(ss l,ss r)
{
    return l.c<r.c;
}

vector<ss>v;
vector<ll>vv[10005];


void dfs(ll root)
{
    //pf("Root = %lld\n",root);
    if(vis[root]==1)
        booked=1;
    vis[root]=0;
    ll i,sz=vv[root].size();
    for(i=0;i<sz;i++)
    {
        ll x=vv[root][i];
        if(vis[x]==-1 || vis[x]==1)
            dfs(x);
    }
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    string s,s1,s2;
    //fout;
    in(test);
    for(t=1;t<=test;t++)
    {
        sum=0;
        in(n),in(m),in(maxx);

        for(i=0;i<m;i++)
        {
            in(a),in(b),in(c);
            v.pb(ss(a,b,c));
        }
        sort(v.begin(),v.begin()+v.size(),compare);
        mm(arr,-1);
        mm(vis,-1);

        cnt=0;
        sum=0;
        for(i=0;i<v.size();i++)
        {
            a=v[i].a;
            b=v[i].b;
            c=v[i].c;

            booked=0;
            ll booked1=0,booked2=0;

            p=findd(a);
            booked1=booked;

            booked=0;
            q=findd(b);
            booked2=booked;

            //pf("P=  %lld q = %lld\n",p,q);

            if(p==q)
                continue;

            if(c>=maxx*2)
            {
                //pf("2 er ceye boro C = %lld Maxx = %lld\n",c,maxx);
                if(booked1==0 && booked2==0)
                {
                    //pf("2 ta e baba ma sara %lld %lld==>> p=%lld q=%lld\\n",a,b,p,q);
                    vis[p]=1;
                    vis[q]=1;
                    cnt+=2;
                    sum+=maxx*2;
                    //pf("Sum = %lld and cnt = %lld\n",sum,cnt);
                }
                else if(booked1==0)
                {
                    //pf("1 tar nai bab ma, for %lld\n",p);
                    vis[p]=1;
                    cnt++;
                    sum+=maxx;
                    //pf("sum = %lld cnt = %lld\n",sum,cnt);
                }
                else if(booked2==0){
                    vis[q]=1;
                    cnt++;
                    sum+=maxx;
                }
                else
                    continue;
            }
            else if(c>=maxx && c<maxx*2)
            {
                //pf("Just 1 ta neoa jabe\n");
                if(booked1==0 && booked2==0)
                {
                    vis[q]=1;
                    arr[p]=q;
                    sum+=maxx+c;
                    vv[a].pb(b);
                    vv[b].pb(a);
                    cnt++;
                }
                else if(booked1==0)
                {
                    vis[p]=1;
                    sum+=maxx;
                    cnt++;
                }
                else if(booked2==0)
                {
                    vis[q]=1;
                    sum+=maxx;
                    cnt++;
                }
                else
                    continue;
            }
            else if(maxx>c)
            {
                //pf("Na na neoa jabe na\n");
                if(booked1==0 && booked2==0)
                {
                    //pf("%lld %lld not booked\n",p,q);
                    arr[p]=q;
                    sum+=c;
                    vv[a].pb(b);
                    vv[b].pb(a);
                }
                else if(booked1==0)
                {
                    arr[p]=q;
                    vv[a].pb(b);
                    vv[b].pb(a);
                }
                else if(booked2==0)
                {
                    arr[q]=p;
                    vv[a].pb(b);
                    vv[b].pb(a);
                }
                else
                    continue;
            }
        }

        for(i=1;i<=n;i++)
        {
            booked=0;
            if(vis[i]==-1 || vis[i]==1){
                dfs(i);
                if(booked==1)
                    continue;
                cnt++;
                sum+=maxx;
            }
        }

        pf("Case %lld: %lld %lld\n",t,sum,cnt);

        for(i=0;i<=n;i++)
            vv[i].cl;
        v.clear();

    }
    return 0;
}
