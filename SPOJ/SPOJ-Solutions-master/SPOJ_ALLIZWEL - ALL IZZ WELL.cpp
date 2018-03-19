#include<bits/stdc++.h>
#define in(a) scanf("%lld",&a)
#define pf printf
using namespace std;
typedef long long ll;

vector<ll>v1,v2;
char arr[1000][1000];
ll alphabet[26],vis1[105][105],a,b;
string ss="ALLIZZWELL";

ll call(ll i,ll j,ll pos)
{
    if(pos>=10)
        return 1;
    if(vis1[i][j]>0)
        return 0;
    if(i<0 || i>=a || j<0 || j>=b)
        return 0;
    if(arr[i][j]<'A' || arr[i][j]>'Z')
        return 0;
    if(arr[i][j]!=ss[pos])
        return 0;
    /*pf("I = %lld J = %lld\n",i,j);
    pf("%c in pos %lld for pos = %c  for i = %lld j = %lld\n",arr[i][j],pos,ss[pos],i,j);*/

    if(arr[i][j]==ss[pos])
    {
        //pf("Yess milese %lld porjonto in %lld %lld................... %c == %c\n",pos,i,j,arr[i][j],ss[pos]);
        vis1[i][j]=1;
        ll p=call(i,j+1,pos+1)|call(i,j-1,pos+1)|call(i+1,j,pos+1)|call(i-1,j,pos+1)|call(i-1,j-1,pos+1)|call(i+1,j+1,pos+1)|call(i+1,j-1,pos+1)|call(i-1,j+1,pos+1);
        if(p==1)
            return 1;
        else
            vis1[i][j]=0;
    }
    return 0;
}

int main()
{
    ll test,i,t,j;
    //freopen("out.txt","w",stdout);
    in(test);
    char c;
    for(t=1;t<=test;t++)
    {
        memset(alphabet,0,sizeof(alphabet));
        in(a),in(b);
        getchar();
        for(i=0;i<a;i++)
            for(j=0;j<b;j++){
                cin>>arr[i][j];
                if(arr[i][j]=='A'){
                    v1.push_back(i);
                    v2.push_back(j);
                }
            }

        /*for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
                pf("%c ",arr[i][j]);
            pf("\n");
        }*/
        ll siz=v1.size(),p=0;
        for(i=0;i<siz;i++)
        {
            memset(vis1,0,sizeof(vis1));
            p|=call(v1[i],v2[i],0);
            //pf("P = %lld got for %lld %lld\n",p,v1[i],v2[i]);
        }
            if(p==0)
                pf("NO\n");
            else
                pf("YES\n");
        v1.clear();
        v2.clear();
    }
    return 0;
}
