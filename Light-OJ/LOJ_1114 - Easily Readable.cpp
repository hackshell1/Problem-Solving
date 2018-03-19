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

ll precal[27][27][10001];
vector<S>v;

int main()
{
    ll test,t,i,j,len,n;
    in(test);
    char s[10001],s1[100001];
    S s2;
    for(t=1;t<=test;t++)
    {
        in(n);
        getchar();
        for(i=0;i<n;i++)
        {
            gets(s);
            len=strlen(s);
            precal[s[0]-'a'][s[len-1]-'a'][len]++;
        }
        in(n);
        getchar();
        for(i=0;i<n;i++)
        {
            gets(s);
            len=strlen(s);
            for(j=0;j<len;j++)
            {
                if(s[j]==' ')
                {
                    v.pb(s2);
                    s2.cl;
                    continue;
                }
                s2+=s[j];
                if(len-1==j)
                {
                    v.pb(s2);
                    s2.cl;
                    continue;
                }
            }
            pf("Siz = %lld\n",v.size());
            ll sum=1;
            for(j=0;j<v.size();j++){
                s2=v[i];
                len=s2.length();
                sum*=precal[s2[0]][s2[len-1]][len];
            }
            pf("%lld\n",sum);
            v.cl;
        }
        mm(precal,0);
    }
}
