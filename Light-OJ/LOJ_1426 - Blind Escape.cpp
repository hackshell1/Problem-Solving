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
#define logg(x,y) (double)log(y)/(double)log(x)
#define cl clear()
#define ps push
#define take pf("ASHCE....\n")
#define takee pf("gotttaaaaaa.......\n")

using namespace std;
typedef long long ll;

struct ss
{
    ll a,b,consider;
    string s;
    ss(ll x,ll y,ll z,string ss)
    {
        a=x,b=y,consider=z,s=ss;
    }
};


ll arr[16][16],direction2[8]={0,1,-1,0,1,0,0,-1},vis[16][16],req[5];
vector<string>v;

///    N
///W        E
///    S

ll findd(char ch)
{
    if(ch=='E')
        return 0;
    if(ch=='N')
        return 1;
    if(ch=='S')
        return 2;
    return 3;
}

string give(ll a)
{
    if(a==0)
        return "E";
    if(a==1)
        return "N";
    if(a==2)
        return "S";
    return "W";
}

ll bfs(ll a,ll b,ll n,ll m)
{
    queue<ss>Q;
    string s;
    Q.push(ss(a,b,0,s));
    vis[a][b]=1;
    while(!Q.empty())
    {
        ll x=Q.front().a;
        ll y=Q.front().b;
        ll z=Q.front().consider;
        string st=Q.front().s;
        if(x<0 || x>=n || y<0 || y>=m)
        {
            v.pb(st);
            return 1;
        }
        Q.pop();
        mm(req,0);
        ll len=st.length();
        len;
        ll len2=len-z;
        for(ll i=len2;i<len;i++)
        {
            if(st[i]=='E')
                req[0]=1;
            else if(st[i]=='N')
                req[1]=1;
            else if(st[i]=='W')
                req[2]=1;
            else
                req[3]=1;
        }
        if(z==1)
        {
            a=findd(st[len-1]);
            ll p,q;
            p=x+direction2[a*2];
            q=y+direction2[1+(a*2)];
            if(p>=n || p<0 || q<0 || q>=m)
            {
                v.pb(st);
                return 1;
            }
            if(arr[p][q]!=-1 && vis[p][q]==-1){
                Q.push(ss(p,q,1,st));
                continue;
            }
        }
        pf("From %lld %lld %lld => ",x,y,z);
        cout<<s<<endl;
        pf("%lld %lld with con %lld ==>> ",x,y,z);
        cout<<st<<endl;
        ll cnt=0;
        for(ll i=0;i<4;i++)
        {
            ll p,q;
            p=x+direction2[i*2];
            q=y=direction2[1+(i*2)];
            pf("Trying from %lld %lld with ",p,q);
            cout<<give(i)<<endl;
            if(req[i]!=0)
            {
                if(arr[p][q]!=-1 && vis[p][q]==-1){
                    Q.push(ss(p,q,1,st+give(i)));
                    cnt=1;
                    continue;
                }
                else
                    st+=give(i);
            }
        }
        /*if(cnt==0)
            return 0;*/
    }
    return 0;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    cin>>test;
    char ch;
    for(t=1;t<=test;t++)
    {
        cin>>n;
        cin>>m;
        for(i=0;i<n+5;i++)
            for(j=0;j<m+5;j++)
                arr[i][j]=1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>ch;
                if(ch=='#')
                    arr[i][j]=-1;
            }
        }
        for(i=0;i<n+1;i++)
        {
            for(j=0;j<m+1;j++)
                pf("%2lld ",(ll)arr[i][j]);
            pf("\n");
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(arr[i][j]==1)
                {
                    mm(vis,-1);
                    pf("GOT...............\n");
                    x=bfs(i,j,n,m);
                    pf("ANS for %lld,%lld got x = %lld\n",i,j,x);
                }
            }
        }
    }
}
