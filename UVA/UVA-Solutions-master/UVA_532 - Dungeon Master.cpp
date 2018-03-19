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
    ll a,b,c;
};

ll arr[100][100][100],vis[100][100][100],dir[6][3]={0,1,0,0,-1,0,1,0,0,-1,0,0,0,0,1,0,0,-1};

ll bfs(ss s,ss d,ll kk,ll ii,ll jj)
{
    ll aa,bb,cc,a,b,c,i;
    queue<ss>q;
    ss curr,curr1,curr2;
    q.push(s);
    arr[s.a][s.b][s.c]=1;
    vis[s.a][s.b][s.c]=0;
    while(q.size()>0)
    {
        curr=q.front();
        q.pop();
        a=curr.a;
        b=curr.b;
        c=curr.c;
        for(i=0;i<6;i++)
        {
            aa=dir[i][0]+a;
            bb=dir[i][1]+b;
            cc=dir[i][2]+c;
            if(aa>=0 && aa<kk && bb>=0 && bb<ii && cc>=0 && cc<jj && vis[aa][bb][cc]==-1 && arr[aa][bb][cc]==0)
            {
                curr1.a=aa;
                curr1.b=bb;
                curr1.c=cc;
                vis[aa][bb][cc]=vis[a][b][c]+1;
                q.push(curr1);
                if(aa==d.a && bb==d.b && cc==d.c)
                    return vis[aa][bb][cc];
            }
        }
    }
    return -1;
}


int main()
{
    //freopen("out.txt","w",stdout);
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    ss start,endd;
    char ch[100];
    while(in(a),in(b),in(c))
    {
        if(a==b && b==c && a==0)
            break;
        mm(vis,-1);
        mm(arr,1);
        getchar();
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                cin>>ch;
                for(k=0;k<c;k++)
                {
                    if(ch[k]=='S')
                    {
                        start.a=i;
                        start.b=j;
                        start.c=k;
                        arr[i][j][k]=1;
                    }
                    else if(ch[k]=='E')
                    {
                        endd.a=i;
                        endd.b=j;
                        endd.c=k;
                        arr[i][j][k]=0;
                    }
                    else if(ch[k]=='#')
                        arr[i][j][k]=1;
                    else if(ch[k]=='.')
                        arr[i][j][k]=0;
                }
            }
        }
        x=bfs(start,endd,a,b,c);
        if(x==-1)
            pf("Trapped!\n");
        else
            pf("Escaped in %lld minute(s).\n",x);
    }
    return 0;
}
