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
#define cl clear()


using namespace std;
typedef long long ll;

vector<string>V;
vector<ll>v[10000];
ll vis[10000],parent[10000];

                                                           ///.............................bfs_1D(a,b)

void bfs_1D(ll a)
{
    ll x,y,sz;
    mm(vis,-1);
    queue<ll>q;
    q.push(a);
    vis[a]=0;
    while(q.size()>0)
    {
        x=q.front();
        q.pop();
        sz=v[x].size();
        for(ll i=0;i<sz;i++)
        {
            y=v[x][i];
            if(vis[y]==-1)
            {
                q.push(y);
                vis[y]=vis[x]+1;
            }
        }
    }
    return;
}


ll findd(string s1)
{
    ll len=s1.length(),i;
    string s;
    for(i=0;i<len;i++)
    {
        if(s1[i]!=' ')
            s+=s1[i];
    }
    ll sz=V.size();
    for(i=0;i<sz;i++)
        if(V[i]==s)
            return i;
    V.pb(s);
    return sz;
}

void process(string s)
{
    ll len=s.length(),i;
    vector<string>ss;
    string s1;
    vector<ll>rr;
    for(i=0;i<len;)
    {
        if(s[i+1]==','){
            s1+=s[i];
            rr.pb(findd(s1));
            s1.clear();
            i+=3;
        }
        else if(s[i+1]==':')
        {
            s1+=s[i];
            rr.pb(findd(s1));
            s1.cl;
            break;
        }
        else{
            s1+=s[i];
            i++;
        }
    }
    ll sz=rr.size();

    for(ll i=0;i<sz;i++)
        for(ll j=0;j<sz;j++)
            if(i!=j){
                v[rr[i]].pb(rr[j]);
                v[rr[j]].pb(rr[i]);
            }
    return;
}

string prcs(string s)
{
    ll len=s.length();
    string s1;
    for(ll i=0;i<len;i++)
    {
        if(s[i]==',')
            return s1;
        s1+=s[i];
    }
    return s;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0;
    fout;
    in(test);
    char s[10000];
    string s1,s2;
    for(t=1;t<=test;t++)
    {
        pf("Scenario %lld\n",t);
        in(n),in(q);
        getchar();
        for(i=1;i<=n;i++)
        {
            gets(s);
            process(s);
        }


        //pf("Szzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\n");
        bfs_1D(findd("Erdos"));


        /*for(i=0;i<V.size();i++)
        {
            cout<<V[i]<<"<><><>-----";
            for(j=0;j<v[i].size();j++)
                cout<<V[v[i][j]]<<"<>";
            pf("\n");
        }*/

        for(i=1;i<=q;i++)
        {
            cin>>s1>>s2;
            s1=prcs(s1);
            x=findd(s1);
            y=findd(s2);
            cout<<s1<<", "<<s2<<" ";
            if(vis[x]!=-1 && vis[y]!=-1 && vis[x]==vis[y])
                cout<<vis[x]<<endl;
            else
                pf("infinity\n");

            /*for(j=0;j<V.size();j++)
                cout<<V[j]<<"<>";
            pf("\n");*/

        }
        ll sz=V.size();
        for(i=0;i<sz;i++)
            v[i].cl;
        V.cl;
    }
    return 0;
}
