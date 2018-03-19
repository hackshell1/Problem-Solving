#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf

using namespace std;
typedef long long ll;

ll arr[1005][1005],cost[1005][1005],pos[8]={0,1,0,-1,1,0,-1,0};

struct ss
{
    ll i,j;
    ss(ll a,ll b)
    {
        i=a;
        j=b;
    }
};

int main()
{
    ll test,t,i,j,a,b,m,n,how,h,r,y,p1,q1,x,p2,q2,p;
    queue<ss>q;
    bool f;
    while(in(n),in(m))
    {
        if(n==0 && m==0)
            return 0;

        for(i=0;i<=n;i++)
        {
            for(j=0;j<m;j++)
            {
                arr[i][j]=0;
                cost[i][j]=0;
            }
        }

        in(how);
        for(h=0;h<how;h++)
        {
            in(x);
            in(r);
            for(i=0;i<r;i++)
            {
                in(p);
                arr[x][p]=1;
            }
        }
        in(x),in(y);
        q.push(ss(x,y));
        arr[x][y]=1;
        cost[x][y]=0;
        in(x),in(y);
        f=false;
        while(q.size()>0)
        {
            //pf("Q.size = %lld\n",q.size());
            p1=q.front().i;
            q1=q.front().j;
            q.pop();
            //pf("For root  %lld %lld....................\n",p1,q1);
            for(i=0;i<8;i+=2)
            {
                p2=p1+pos[i];
                q2=q1+pos[i+1];
                //pf("Try with %lld %lld\n",p2,q2);
                if(arr[p2][q2]==0 && p2>=0 && p2<n && q2>=0 && q2<m)
                {
                    q.push(ss(p2,q2));
                    //pf("Pushed %lld %lld\n",p2,q2);
                    arr[p2][q2]=1;
                    cost[p2][q2]=cost[p1][q1]+1;
                    if(p2==x && q2==y)
                    {
                        f=true;
                        break;
                    }
                }
            }
            //pf("ses    >>>               >>\n");
            if(f==true)
                break;
        }
        pf("%lld\n",cost[x][y]);
        ll siz=q.size();
        for(i=0;i<siz;i++)
            q.pop();
    }
    return 0;
}
