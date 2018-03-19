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

vector<string>v;

ll vis[100];

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    string s1,s2;
    while(cin>>s1)
    {
        mm(vis,0);
        v.pb(s1);
        len=s1.length();
        maxx=max(maxx,len);

        while(cin>>s1)
        {
            if(s1=="#")
                break;
            v.pb(s1);
            len=s1.length();
            maxx=max(maxx,len);

        }
        ll sz=v.size();
        for(i=0;i<maxx;i++)
        {
            for(j=0;j<sz;j++)
            {
                s1=v[j];
                len=s1.length()-1;
                ll chek_chek=s1[i]-'A';
                if(len>=i && vis[chek_chek]==0){
                    vis[chek_chek]++;
                    pf("%c",s1[i]);
                }
            }
        }
        pf("\n");
        v.clear();
    }

    return 0;
}

