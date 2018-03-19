
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


ll chek(char s)
{
    if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u' || s=='A' || s=='E' || s=='I' || s=='O' || s=='U')
        return 1;
    if(s>='A' && s<='Z')
        return 0;
    if(s>='a' && s<='z')
        return 0;
    return -1;
}



int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0,c;

    string s,r;
    //fout;
    string str;
    while(getline(cin,str))
    {
        len=str.length();
        for(i=0;i<len;i++)
        {
            if(chek(str[i])==1)
            {
                if(s.empty()){
                    s+="ay";
                    r+=str[i];
                }
                else
                    r+=str[i];
            }
            else if(chek(str[i])==0)
            {
                if(s.empty())
                {
                    s+=str[i];
                    s+="ay";
                }
                else
                    r+=str[i];
            }
            else
            {
                r=r+s;
                cout<<r;
                r.cl;
                s.cl;
                pf("%c",str[i]);
            }
        }
        if(!s.empty() && !r.empty())
            cout<<r+s;
        pf("\n");
        s.cl;
        r.cl;
    }
    return 0;
}

