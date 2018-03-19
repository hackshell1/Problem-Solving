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



int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;
    string s,r;
    while(getline(cin,s))
    {
        len=s.length();
        for(i=0;i<len;i++)
        {
            if(s[i]!=' ')
                r+=s[i];
            else
            {
                ll len2=r.size();
                for(j=0;j<(len2/2);j++)
                    swap(r[j],r[len2-j-1]);
                cout<<r;
                r.cl;
                pf(" ");
            }
        }
        if(!r.empty()){
            ll len2=r.size();
            for(j=0;j<(len2/2);j++)
                swap(r[j],r[len2-j-1]);
            cout<<r;
        }
        pf("\n");
        s.cl;
        r.cl;
    }
    return 0;
}
