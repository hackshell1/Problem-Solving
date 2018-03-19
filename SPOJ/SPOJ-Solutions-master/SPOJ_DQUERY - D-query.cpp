#include<bits/stdc++.h>
#define in(a) scanf("%d",&a)
#define pf printf

using namespace std;
typedef long long ll;



struct ss
{
    int a,b,pos,ans;
}qry[200005];

int sq,number,arr[30005],occur[1000005],n,ans[30005];

bool compare(ss l,ss r)
{
    if(l.a/sq==r.b/sq)
        return l.b<r.b;
    return l.a<r.a;
}

int add(int a)
{
    occur[arr[a]]++;
    if(occur[arr[a]]==1)
        number++;
}

int removee(int  a)
{
    occur[arr[a]]--;
    if(occur[arr[a]]==0)
        number--;
}

int main()
{
    int i,qr;
    in(n);
    for(i=0;i<n;i++)
        in(arr[i]);
    in(qr);
    for(i=0;i<qr;i++)
    {
        in(qry[i].a);
        in(qry[i].b);
        qry[i].a--;
        qry[i].b--;
        qry[i].pos=i;
    }
    sq=(int)sqrt(n);
    sort(qry,qry+qr,compare);

    int lo,hi;
    number=0;
    lo=0,hi=0;
    for(i=0;i<qr;i++)
    {
        while(lo<qry[i].a)
        {
            removee(lo);
            lo++;
        }
        while(lo>qry[i].a)
        {
            lo--;
            add(lo);
        }
        while(hi<=qry[i].b)
        {
            add(hi);
            hi++;
        }
        while(hi>qry[i].b+1)
        {
            hi--;
            removee(hi);
        }
        ans[qry[i].pos]=number;
    }
    for(i=0;i<qr;i++)
        pf("%d\n",ans[i]);
}
