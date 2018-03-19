#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
#define inf 1<<30


using namespace std;
typedef long long ll;

vector<ll>vv[1000005],v;
ll deepth[100000];

findd(ll a,ll type)
{
    ll siz=v.size(),i;
    for(i=0;i<siz;i++)
        if(v[i]==a)
            return i;
    if(type==1)
    {
        v.push_back(a);
        return siz;
    }
    return -1;
}

ll bfs(ll node,ll depth)
{
    ll x,siz,i;
    vector<ll>vis1;
    queue<ll>q;
    vis1.clear();
    deepth[node]=0;
    q.push(node);
    ll dep=0;
    ll cnt=1;
    while(1)
    {
        pf("Abar ashce\n");
        pf("Dep = %lld\n",dep);
        if(q.size()==0)
            break;
        dep++;
        if(dep>depth)
            break;
        x=q.front();
        q.pop();
        vis1.push_back(x);
        siz=vv[x].size();

        pf("For x = %lld\n",v[x]);

        for(i=0;i<siz;i++)
        {
            pf("%lld and depth = %lld  ... ",v[vv[x][i]],deepth[vv[x][i]]);
            if(deepth[vv[x][i]]==-1)
            {
                pf(" allowed\n");
                deepth[vv[x][i]]=dep;
                q.push(vv[x][i]);
                cnt++;
            }
        }
        pf("Yessssss\n");
        siz=q.size();
        for(i=0;i<siz;i++)
            pf("%lld ",v[q.front()+i]);
        pf("\n");
        pf("Ashce.............................................\n");
        dep++;
        pf("qsiz = %lld\n",q.size());
    }
    pf("Vs1 size %d\n",vis1.size());
    pf("Cnt = %lld\n",cnt);
    return cnt;
}

int main()
{
    ll test=0,n,i,a,b,x,siz;
    memset(deepth,-1,sizeof(deepth));
    while(in(n))
    {
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            in(a),in(b);
            a=findd(a,1);
            b=findd(b,1);
            vv[a].push_back(b);
            vv[b].push_back(a);
        }
        siz=v.size();
        while(in(a),in(b))
        {
            test++;
            if(a==0 && b==0)
                break;
            x=a;
            a=findd(a,2);
            if(a==-1)
            {
                pf("Case %lld: %lld nodes not reachable from node %lld with TTL = 2.",test,siz,x,b);
                continue;
            }
            x=bfs(a,b);
        }
    }
}
