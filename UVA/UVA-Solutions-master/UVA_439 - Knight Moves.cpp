#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
#define mm(arr,x) memset(arr,x,sizeof(arr))
#define pb push_back
#define frout freopen("out.txt","w",stdout)

using namespace std;

typedef long long ll;

ll vis[10][10];
ll d1[10]={-2,-2,2,2,1,1,-1,-1};
ll d2[10]={-1,1,-1,1,-2,2,2,-2};

struct ss
{
    ll x,y;
    ss(ll a,ll b)
    {
        x=a;
        y=b;
    }
};

queue<ss>q;

ll bfs(ll x1,ll y1,ll x2,ll y2)
{
    if(x1==x2 && y1==y2)
        return 0;
    while(!q.empty())
        q.pop();

    vis[x1][y1]=0;
    q.push(ss(x1,y1));

    while(q.size()>0)
    {
        x1=q.front().x;
        y1=q.front().y;
        q.pop();
        for(ll i=0;i<8;i++)
        {
            ll x=x1+d1[i];
            ll y=y1+d2[i];
            if(x>=1 && x<=8 && y>=1 && y<=8 && vis[x][y]<=-1)
            {
                vis[x][y]=vis[x1][y1]+1;
                q.push(ss(x,y));
                if(x==x2 && y==y2)
                    return vis[x2][y2];
            }
        }
    }
}


int main()
{
    char s[100];

    //frout;
    ll x1,x2,y1,y2,x;
    while(gets(s))
    {
        x1=s[0]-'a'+1;
        y1=s[1]-'0';
        x2=s[3]-'a'+1;
        y2=s[4]-'0';
        mm(vis,-1);
        x=bfs(x1,y1,x2,y2);

        //pf("from %lld %lld to %lld %lld     X = %lld\n",x1,y1,x2,y2,x);

        pf("To get from %c%c to %c%c takes %lld knight moves.\n",s[0],s[1],s[3],s[4],x);
    }
    return 0;
}


