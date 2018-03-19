#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf

using namespace std;
typedef long long ll;
vector<string>v;
vector<ll>vv[1000];

ll findd(string s)
{
    ll siz=v.size();
    for(ll i=0;i<siz;i++)
    {
        if(v[i]==s)
            return i;
    }
    v.push_back(s);
    return siz;
}

ll chek(ll a,ll b)
{
    ll i,j,len1,len2;
    string s1,s2;
    s1=v[a];
    s2=v[b];
    len1=s1.length();
    len2=s2.length();
    if(len1!=len2)
        return 0;
    ll cnt=0;
    for(i=0;i<len1;i++)
    {
        if(s1[i]!=s2[i])
            cnt++;
    }
    if(cnt>1)
        return 0;
    return 1;
}

ll bfs(ll a,ll b)
{
    //pf("a = %lld b = %lld\n",a,b);
    if(a==b)
        return 0;
    ll vis[205],i,x;
    memset(vis,0,sizeof(vis));
    queue<ll>q;
    q.push(a);
    vis[a]=0;
    while(q.size()>0)
    {
        x=q.front();
        q.pop();
        ll siz=vv[x].size();
        for(i=0;i<siz;i++)
        {
            if(vis[vv[x][i]]==0)
            {
                q.push(vv[x][i]);
                vis[vv[x][i]]=vis[x]+1;
                if(vv[x][i]==b){
                    ll sizz=q.size();
                    for(i=0;i<sizz;i++)
                        q.pop();
                    return vis[b];
                }
            }
        }
    }
    ll sizz=q.size();
    for(i=0;i<sizz;i++)
        q.pop();
    return vis[b];
}


void get(char *s,ll len)
{
    string s1="\0",s2="\0";
    ll i,j;
    for(i=0;i<len;i++)
    {
        if(s[i]==' ')
            break;
        s1+=s[i];
    }
    for(j=i+1;j<len;j++)
        s2+=s[j];
    cout<<s1<<" "<<s2;
    pf(" %lld\n",bfs(findd(s1),findd(s2)));
    return;
}

int main()
{
    ll test,t,i,j,siz,x;
    string s1,s2,s;
    //freopen("out.txt","w",stdout);
    cin>>test;
    for(t=0;t<test;t++)
    {
        while(cin>>s)
        {
            if(s=="*")
                break;
            findd(s);
        }
        siz=v.size();
        for(i=0;i<siz;i++)
        {
            for(j=i+1;j<siz;j++)
            {
                x=chek(i,j);
                if(x==1)
                {
                    vv[i].push_back(j);
                    vv[j].push_back(i);
                }
            }
        }
        char sss[1000];
        getchar();
        while(gets(sss))
        {
            ll len=strlen(sss);
            if(len==0)
                break;
            get(sss,len);
        }
        siz=v.size();
        for(i=0;i<siz;i++)
            vv[i].clear();
        v.clear();
        if(t<test-1)
            pf("\n");
    }
    return 0;
}
