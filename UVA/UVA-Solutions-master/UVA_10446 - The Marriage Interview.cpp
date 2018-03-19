#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
#define mm(arr,a) memset(arr,a,sizeof(arr))
#define fout freopen("out.txt","w",stdout)
#define inf 1<<30
#define pb push_back

using namespace std;
typedef long long ll;

ll dp[100][100];

ll call(ll n,ll back)
{
    ll sum=0;
    ll i;
    if(n==0) return 1;
    if(n<0)
        return 0;
    if(dp[n][back]!=-1)
        return dp[n][back];
    for(i=1;i<=back;i++)
        sum+=call(n-i,back);
    return dp[n][back]=sum+1;
}

int main()
{
    ll a,b,casee=0;
    while(in(a),in(b))
    {
        mm(dp,-1);
        pf("Case %lld: %lld\n",casee,call(a,b));
    }
}
