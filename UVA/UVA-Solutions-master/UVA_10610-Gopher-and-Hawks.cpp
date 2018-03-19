#include<bits/stdc++.h>
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

struct ss
{
    float x1,y1;
    ss(ll x,ll y)
    {
        x1=x;
        y1=y;
    }
};

vector<ss>V;
vector<ll>v[1005];
ll vis[1005];

ll findd(float f1,float f2)
{
    ll i,sz=V.size();
    for(i=0;i<sz;i++)
        if(V[i].x1==f1 && V[i].y1==f2)
            return i;
    V.pb(ss(f1,f2));
    return sz;
}

ll bfs(ll a,ll b,ll velocity,ll m)
{
    ll x,y,i,j;
    queue<ll>q;
    q.push(a);
    vis[a]=0;
    while(q.size()>0)
    {
        x=q.front();
        q.pop();
        ll sz=v[x].size();
        for(i=0;i<sz;i++)
        {
            y=v[x][i];
            if(vis[y]==-1)
            {
                float time=sqrt(((V[x].x1-V[y].x1)*(V[x].x1-V[y].x1))+((V[x].y1-V[y].y1)*(V[x].y1-V[y].y1)))/(velocity*60);
                //pf("from %0.2f %0.2f ==> %0.2f %0.2f  takes %0.2f time\n",V[x].x1,V[x].y1,V[y].x1,V[y].y1,time);
                if(time>m)
                    continue;
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
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,velocity;
    float x1,x2,y1,y2,f1,f2;
    char s1[1005],s2[1005],s[1005];
    while(cin>>velocity>>m)
    {
        mm(vis,-1);
        if(velocity==0 && m==0)
            break;
        cin>>x1>>y1;
        cin>>x2>>y2;
        findd(x1,y1);
        findd(x2,y2);
        getchar();
        while(gets(s))
        {
            len=strlen(s);
            if(len==0)
                break;
            ll l=0;
            for(i=0;i<len;i++)
            {
                if(s[i]==' ')
                {
                    s1[l]='\0';
                    break;
                }
                s1[l]=s[i];
                l++;
            }
            l=0;
            for(i=i+1;i<len;i++)
                s2[l++]=s[i];
            s2[l]='\0';
            f1=atof(s1);
            f2=atof(s2);
            findd(f1,f2);
        }
        ll sz=V.size();
        for(i=0;i<sz;i++)
        {
            for(j=0;j<sz;j++)
            {
                if(i==j)
                    continue;
                v[i].pb(j);
            }
        }
        mm(vis,-1);
        x=bfs(findd(x1,y1),findd(x2,y2),velocity,m);
        if(x==0 || x==1)
            pf("Yes, visiting 0 other holes.\n");
        else if(x==-1)
            pf("No.\n");
        else
            pf("Yes, visiting %lld other holes.\n",x-1);
        sz=V.size();
        for(i=0;i<sz;i++)
            v[i].cl;
        V.cl;
    }
    return 0;
}
