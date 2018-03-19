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


using namespace std;
typedef long long ll;

ll direction1[8]={0,1,0,-1,1,0,-1,0},direction2[16]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};
char arr[55][55];
ll store_lines[55][55],chek_lines[55][55],cycle_cheking_mem[55][55];

void find_line(ll a,ll b,ll n,ll m,char ch)
{
    store_lines[a][b]=1;
    chek_lines[a][b]=1;
    for(ll i=0;i<16;i+=2)
    {
        ll x=a+direction2[i];
        ll y=b+direction2[i+1];
        if(x>=0 && x<n && y>=0 && y<m && arr[x][y]==ch && chek_lines[x][y]==-1 && store_lines[x][y]==-1)
        {
            store_lines[x][y]=1;
            chek_lines[x][y]=1;
            find_line(x,y,n,m,ch);
        }
    }
    return;
}

ll chek_cycle(ll a,ll b,ll n,ll m)
{
    cycle_cheking_mem[a][b]=1;
    ll ret=1;
    for(ll i=0;i<16;i+=2)
    {
        ll x=a+direction2[i];
        ll y=b+direction2[i+1];
        if(x<0 || x>=n || y<0 || y>=m)
            return 0;
        if(cycle_cheking_mem[x][y]==-1 && chek_lines[x][y]==-1)
        {
            cycle_cheking_mem[x][y]=1;
            if(chek_cycle(x,y,n,m)==0)
                return 0;
        }
    }
    return 1;
}

void fill_the_circle(ll a,ll b,ll n,ll m,char ch)
{
    store_lines[a][b]=1;
    arr[a][b]=ch;
    for(ll i=0;i<16;i+=2)
    {
        ll x=a+direction2[i];
        ll y=b+direction2[i+1];
        if(store_lines[x][y]==-1 && x>=0 && x<n && y>=0 && y<m)
        {
            store_lines[x][y]=1;
            arr[x][y]=ch;
            fill_the_circle(x,y,n,m,ch);
        }
    }
    return;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,l;
    char c;
    in(test);
    //fout;
    for(t=1;t<=test;t++)
    {
        in(n),in(m);
        getchar();
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>arr[i][j];

        mm(store_lines,-1);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(arr[i][j]!='.' && store_lines[i][j]==-1)
                {
                    mm(chek_lines,-1);
                    find_line(i,j,n,m,arr[i][j]);

                    ll rr=0;
                    for(ll k=0;k<n;k++)
                    {
                        for(ll l=0;l<m;l++)
                        {
                            if( chek_lines[k][l]==-1)
                            {
                                mm(cycle_cheking_mem,-1);
                                x=chek_cycle(k,l,n,m);
                                if(x==1)
                                    fill_the_circle(k,l,n,m,arr[i][j]);

                            }
                        }
                    }
                }
            }
        }

        pf("Case %lld:\n",t);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                pf("%c",arr[i][j]);
            }
            pf("\n");
        }

    }
    return 0;
}


