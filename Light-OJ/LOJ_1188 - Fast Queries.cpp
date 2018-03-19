#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf

using namespace std;
typedef long long ll;

ll arr[1000000],block,number,occur[1000000];

struct ss
{
    ll a,b,ans,pos;
}aee[1000000];

bool compare(ss l,ss r)
{
    if(l.a/block==r.a/block)
        return l.b<r.b;
    return l.a/block <r.a/block;
}

bool cmpr(ss l,ss r)
{
    return l.pos<r.pos;
}

void add(ll pos)
{
    occur[arr[pos]]++;
    if(occur[arr[pos]]==1)
        number++;
    return;
}

void removee(ll pos)
{
    occur[arr[pos]]--;
    if(occur[arr[pos]]==0)
        number--;
    return;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,minn=1<<30,a,b,test=0,len,sum=0;

    //freopen("out.txt","w",stdout);

    in(test);
    for(t=1;t<=test;t++)
    {
        for(i=0;i<=100000;i++)
            occur[i]=0;

        number=0;
        in(n),in(q);
        for(i=0;i<n;i++)
            in(arr[i]);

        for(i=0;i<q;i++)
        {
            in(aee[i].a),in(aee[i].b);
            aee[i].a--;
            aee[i].b--;
            aee[i].ans=0;
            aee[i].pos=i;
        }
        block=sqrt(n);
        sort(aee,aee+q,compare);

        ll lo=0,hi=0;
        for(i=0;i<q;i++)
        {
            x=aee[i].a;
            y=aee[i].b;


            while(lo < x) {
				removee(lo);
				lo++;
			}


			while(lo > x) {
				add(lo-1);
				lo--;
			}

			while(hi <= y) {
				add(hi);
				hi++;
			}

			while(hi > y+1) {
				removee(hi - 1);
				hi--;
			}
        }
        sort(aee,aee+q,cmpr);
        pf("Case %lld:\n",t);
        for(i=0;i<q;i++)
            pf("%lld\n",aee[i].ans);
    }
    return 0;
}




