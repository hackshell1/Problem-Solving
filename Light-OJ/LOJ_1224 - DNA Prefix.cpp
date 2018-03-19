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

struct ss
{
    struct ss *next[5];
    bool yes_no;
    ll cnt;
    ss()
    {
        ll i=0;
        yes_no=false;
        cnt=0;
        for(i=0;i<4;i++)
            next[i]=NULL;
    }
}*root;


ll trie(string s,ll len)
{
    ll i,j,k,l;

    ss* curr=root;

    for(ll i=0;i<len;i++)
    {
        if(curr->next[s[i]-'0']==NULL)
            curr->next[s[i]-'0']=new ss();
        curr=curr->next[s[i]-'0'];
        curr->cnt++;
    }
    curr->yes_no=true;
}

ll maxx;

void chek(ss *curr,ll len)
{
    ll i,j;
    for(i=0;i<4;i++)
    {
        maxx=max(maxx,len*curr->cnt);
        if(curr->next[i]==NULL)
            continue;
        chek(curr->next[i],len+1);
    }
}

void del(ss* cur)
{
    for (int i = 0; i <4; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete (cur);
}

int main()
{
    ll i,j,k,n,test,t,len,cnt;
    string s;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>n;
        root=new ss();
        maxx=0;
        for(i=1;i<=n;i++)
        {
            cin>>s;
            len=s.length();
            maxx=max(maxx,len);
            for(j=0;j<len;j++)
            {
                if(s[j]=='A')
                    s[j]='0';
                else if(s[j]=='C')
                    s[j]='1';
                else if(s[j]=='G')
                    s[j]='2';
                else
                    s[j]='3';
            }
            trie(s,len);
            s.clear();
        }
        cnt=0;

        root->yes_no=false;

        chek(root,0);

        pf("Case %lld: %lld\n",t,maxx);

        del(root);
    }
    return 0;
}

