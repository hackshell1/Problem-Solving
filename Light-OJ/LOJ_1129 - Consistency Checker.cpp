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
    struct ss *next[10];
    bool yes_no;
    ll cnt;
    ss()
    {
        ll i=0;
        yes_no=false;
        cnt=0;
        for(i=0;i<10;i++)
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

bool chek(ss *curr)
{
    ll i,j;
    bool p=true;
    if(curr->yes_no==true && curr->cnt>1){
        return false;
    }
    for(i=0;i<10;i++)
    {
        if(curr->next[i]==NULL)
            continue;
        p&=chek(curr->next[i]);
        if(p==false)
            return false;
    }
    return p;
}

void del(ss* cur)
{
    for (int i = 0; i < 10; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete (cur);
}

vector<S>v;

int main()
{
    ll i,j,k,n,test,t,len,cnt;
    string s;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>n;
        root=new ss();
        for(i=1;i<=n;i++)
        {
            cin>>s;
            len=s.length();
            v.pb(s);
            trie(s,len);
            s.clear();
        }
        sort(v.begin(),v.begin()+v.size());
        cnt=0;

        root->yes_no=false;

        if(chek(root)==false)
            pf("Case %lld: NO\n",t);
        else
            pf("Case %lld: YES\n",t);

        v.clear();
        del(root);
        s.clear();
    }
    return 0;
}
