#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
using namespace std;
typedef long long ll;

deque<ll>dq;

int main()
{
    ll test,t,i,n,m,cnt,a,x;
    string s;
    //freopen("Out.txt","w",stdout);
    in(test);
    for(t=1;t<=test;t++)
    {
        dq.clear();
        in(n),in(m);
        pf("Case %lld:\n",t);
        for(i=0;i<m;i++)
        {
            cin>>s;
            if(s=="pushLeft" || s=="pushRight")
                cin>>a;

            if(s=="pushLeft")
            {
                if(dq.size()<n)
                {
                    dq.push_back(a);
                    pf("Pushed in left: %lld\n",a);
                }
                else
                 pf("The queue is full\n");
                 continue;
            }
            else if(s=="pushRight")
            {
                if(dq.size()<n)
                {
                    dq.push_front(a);
                    pf("Pushed in right: %lld\n",a);
                }
                else
                 pf("The queue is full\n");
                 continue;
            }
            else if(s=="popRight")
            {
                if(dq.size()>0)
                {
                    x=dq.front();
                    dq.pop_front();
                    pf("Popped from right: %lld\n",x);
                }
                else
                    pf("The queue is empty\n");
                    continue;
            }
            else
            {
                if(dq.size()>0)
                {
                    x=dq.back();
                    dq.pop_back();
                    pf("Popped from left: %lld\n",x);
                }
                else
                    pf("The queue is empty\n");
                    continue;
            }
        }
    }
    return 0;
}
