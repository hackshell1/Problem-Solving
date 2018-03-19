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
#define pi acos(-1.0)
#define in(a) scanf("%lld",&a)
#define FOR(a,b,c) for(a=b;a<=c;a++)
#define ROF(a,b,c) for(a=c;a>=1;a--)
#define For(a,b,c) for(a=b;a<c;a++)
#define roF(a,b,c) for(a=c-1;a>=0;a--)
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


using namespace std;
typedef long long ll;

ll direction1[8]={0,1,0,-1,1,0,-1,0},direction2[16]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};
ll fill_outside[55][55],chek_visited[55][55];
char arr[55][55];

int main()
{
    fout;
    string st1="1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu5";
    string st2="1PIT'pz'h'{yhklthyr'vm'{ol'Pu{lyuh{pvuhs'I|zpulzz'Thjopul'Jvywvyh{pvu5";
    string st3="1KLJ'pz'{ol'{yhklthyr'vm'{ol'Kpnp{hs'Lx|pwtlu{'Jvywvyh{pvu5";
    string s,s1;
    while(cin>>s){
        if(s==st1)
        printf("*CDC is the trademark of the Control Data Corporation.\n");
   else if(s==st2)
        printf("*IBM is a trademark of the International Business Machine Corporation.\n");
    else if(s==st3)
        printf("*DEC is the trademark of the Digital Equipment Corporation.\n");
    }
    return 0;
}
