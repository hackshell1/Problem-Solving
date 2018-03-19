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

map<char,ll>mp;
vector<ll>v[100005];
vector<string>V;
ll indegree[10005],vis[10005],dk;
char chart[100];

struct ss
{
    ll node,dgr;
    ss(ll x,ll y)
    {
        node=x;
        dgr=y;
    }
};

bool operator<(const ss& l, const ss& r){
  return l.dgr > r.dgr;
}

priority_queue<ss>q;
queue<string>

ll DAG(ll n)
{
    ll a,b,x,i,sz;
    a=q.top().dgr;
    if(a>0)
        return -1;
    while(!q.empty())
    {
        a=q.top().node;
        b=q.top().dgr;
        q.pop();
        if(b>0)
            return -1;
        pf("%c ",chart[a]);
        sz=v[a].size();
        for(i=0;i<sz;i++)
        {
            x=v[a][i];
            if(indegree[x]>=1){
                indegree[x]--;
                if(indegree[x]==0)
                    V[dk].pb(x);
                q.push(ss(x,indegree[x]));
            }
        }
    }
    return 1;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,maxx=0,minn=1<<30,a,b,test=0,sum=0;
    char s1[1005],s2[1005];
    in(test);
    getchar();
    for(t=1;t<=test;t++)
    {
        gets(s1);
        gets(s2);
        ll len1,len2;
        len1=strlen(s1);
        len2=strlen(s2);
        cnt=0;

        for(i=0;i<len1;i++)
            if(s1[i]>='A' && s1[i]<='Z')
                if(mp.find(s1[i])==mp.end())
                {
                    mp[s1[i]]=cnt++;
                    chart[cnt-1]=s1[i];
                }

        for(i=0;i<len2;i++)
        {
            if(s2[i]>='A' && s2[i]<='Z')
            {
                a=mp[s2[i]];
                b=mp[s2[i+2]];
                v[a].pb(b);
                indegree[b]++;
                i+=2;
            }
        }
        mm(vis,-1);
        for(i=0;i<cnt;i++)
            q.push(ss(i,indegree[i]));
        p=DAG(cnt);
        pf("P = %lld\n",p);
    }
}
