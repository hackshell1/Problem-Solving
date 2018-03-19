/*
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
//#include<bits/stdc++.h>
using namespace std;

#define tm ttttttt
#define j0 jjjjjjj
#define j1 jjjjjjjj
#define jn jjjjjjjjj
#define y0 yyyyyyy
#define y1 yyyyyyyy
#define yn yyyyyyyyy
#define arg aaaaaaa

#define Fin(f) freopen(f, "r", stdin)
#define Fout(f) freopen(f, "w", stdout)
#define CI() fclose(stdin)
#define CO() fclose(stdout)
#define SR() srand((unsigned)time(NULL))
#define random(m) ((rand() << 16 | rand()) % m) // [0,m)
#define randomm(a, b) (a + ((rand() << 16 | rand()) % (b - a)))
#define randomP(a, n) srand((unsigned)time(NULL)), random_shuffle(a, a + (n))
#define AS(a) assert(a)

#define all(a) a.begin(), a.end()
#define PB push_back
#define sq(x) ((x) * (x))
#define Sqrt(n) (int)round(sqrt((double)n))


#define Inter(v, a, n, b, m) v.resize(set_intersection(a, a + (n), b, b + (m), v.begin()) - v.begin())
#define SInter(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Inter(v, a, n, b, m)
#define Union(v, a, n, b, m) v.resize(set_union(a, a + (n), b, b + (m), v.begin()) - v.begin());
#define SUnion(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Union(v, a, n, b, m)
#define Diff(v, a, n, b, m) v.resize(set_difference(a, a + (n), b, b + (m), v.begin()) - v.begin())
#define SDiff(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Diff(v, a, n, b, m)
#define Sym(v, a, n, b, m) v.resize(set_symmetric_difference(a, a + (n), b, b + (m) v.begin()) - v.begin())
#define SSym(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Sym(v, a, n, b, m)

#define setInter(a, b, to) set_intersection(all(a), all(b), inserter(to, to.begin())) //to.insert()
#define setUnion(a, b, to) set_union(all(a), all(b), inserter(to, to.begin())) // to.insert()

#define Cnt1 __builtin_popcount
#define LBpos(n) (31 - __builtin_clz(n))
#define LBposll(n) (63 - __builtin_clzll(n))
#define RBpos(n) (__builtin_ffs(n) - 1)
#define RBposll(n) (__builtin_ffsll(n) - 1)

#define For(i, n) for (i = 0; i < (n); ++i)
//#define For(i, n) for (int i = 0, _ = (n); i < _; ++i)
#define Forr(i, start, n) for (i = start; i < (n); ++i)
#define Forrr(i, start, n, step) for (i = start; i < (n); i += step)
#define rFor(i, n) for (i = (n); i >= 0; --i)
#define rForr(i, n, end) for (i = n; i >= (end); --i)
#define rForrr(i, n, end, step) for (i = n; i >= (end); i -= step)
#define loop(it, a) for (it = a.begin(); it != a.end(); ++it)
#define rloop(it, a) for (it = a.rbegin(); it != a.rend(); ++it)

#define SI(a) scanf("%d", &a)
#define SII(a, b) scanf("%d%d", &a, &b)
#define SIII(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define SIIII(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define SIIIII(a, b, c, d, e) scanf("%d%d%d%d%d", &a, &b, &c, &d, &e)
#define SIIIIII(a, b, c, d, e, f) scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f)
#define SL(a) scanf("%I64d", &a)
#define SLL(a, b) scanf("%I64d%I64d", &a, &b)
#define SLLL(a, b, c) scanf("%I64d%I64d%I64d", &a, &b, &c)
#define SLLLL(a, b, c, d) scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &d)
#define SD(a) scanf("%lf", &a)
#define SDD(a, b) scanf("%lf%lf", &a, &b)
#define SDDD(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)
#define SDDDD(a, b, c, d) scanf("%lf%lf%lf%lf", &a, &b, &c, &d)
#define SA(a, i, n) For(i, n) scanf("%d", a + i)
#define SAA(a, i, n, j, m) For(i, n) For(j, m) SI(a[i][j])
#define SAA1(a, i, n, j, m) Forr(i, 1, n + 1) Forr(j, 1, m + 1) SI(a[i][j])
#define SS(s) scanf("%s", s)
#define SSS(s, s2) scanf("%s%s", s, s2)
#define SC(c) scanf(" %c", &c)
#define GC(c) (c = getchar())
#define Gn() getchar()
#define UC(c) ungetc(c, stdin)

#define PI(a) printf("%d\n", a)
#define PII(a, b) printf("%d %d\n", a, b)
#define PIII(a, b, c) printf("%d %d %d\n", a, b, c)
#define PIIII(a, b, c, d) printf("%d %d %d %d\n", a, b, c, d)
#define PIIIII(a, b, c, d, e) printf("%d %d %d %d %d\n", a, b, c, d, e)
#define PL(a) printf("%I64d\n", a)
#define PLL(a, b) printf("%I64d %I64d\n", a, b)
#define PLLL(a, b, c) printf("%I64d %I64d %I64d\n", a, b, c)
#define PD(a) printf("%f\n", a)
#define PDD(a, b) printf("%f %f\n", a, b)
#define PDDD(a, b, c) printf("%f %f %f\n", a, b, c)
#define PA(a, i, n) For(i, (n) - 1) printf("%d ", a[i]); PI(a[(n) - 1])
#define PAA(a, i, n, j, m) For(i, n) {For(j, (m) - 1) printf("%d ", a[i][j]); PI(a[i][(m) - 1]);}
#define PAn(a, i, n) For(i, n) PI(a[i])
#define rPA(a, i, n) rForr(i, n - 1, 1) printf("%d ", a[i]); PI(a[0])
#define rPAn(a, i, n) rFor(i, n - 1) PI(a[i])
#define PC(c) putchar(c)
#define Pn() putchar(10)
#define Ps() putchar(32)

#define Uni(a) a.resize(unique(all(a)) - a.begin()) // STL
#define SUni(a) sort(all(a)); Uni(a) // STL
#define Unii(a, n) (unique(a, a + (n)) - a)
#define SUnii(a, n) sort(a, a + n); Unii(a, n)
#define Acc(a, n) (accumulate(a, a + (n), 0)) //Acc(a.begin(), k);
#define Accv(a) (accumulate(all(a), 0))
#define AaddB(a, n, b) transform(a, a + (n), b, a, plus<int>()) For(i, n) a[i] += b[i](int i)
#define mem(a, num) memset(a, num, sizeof(a))
#define cpy(to, from) memcpy(to, from, sizeof(from))
#define Rcpy(l, r, b) reverse_copy(l, r, b)
#define kTo10(ans, str, s, m, k) strncpy(str, s, m), str[m] = 0, ans = strtol(str, NULL, k)

#define LE(T) less_equal<T>
#define GR(T) greater<T>
#define GE(T) greater_equal<T>
#define NET(T) not_equal_to<T>

#define nth(a, k, n) nth_element(a + 0, a + k, a + n)
#define nthg(a, k, n) nth_element(a + 0, a + k, a + n, greater<int>())
#define Min(a, n) (*min_element(a, a + (n)))
#define Max(a, n) (*max_element(a, a + (n)))
#define Minpos(a, n) (min_element(a, a + (n)) - (a))
#define Maxpos(a, n) (max_element(a, a + (n)) - (a))
#define Lval(a, n, x) (*lower_bound(a, a + (n), x))
#define Uval(a, n, x) (*upper_bound(a, a + (n), x))
#define Lpos(a, n, x) (lower_bound(a, a + (n), x) - (a))
#define Upos(a, n, x) (upper_bound(a, a + (n), x) - (a))
#define BS(a, n, x) binary_search(a, a + (n), x)
#define Range(a, n, x) equal_range(a, a + (n), x)
#define Fpos(a, n, x) (find(a, a + (n), x) - (a))
#define Fd(a, x) (a.find(x) != a.end())
#define Fdd(a, x) (find(all(a), x) != a.end())
template<class T> inline void Qmin(T &a, const T b) {if (b < a) a = b;}
template<class T> inline void Qmax(T &a, const T b) {if (a < b) a = b;}

const int inf = 0x3f3f3f3f; /// 1.06e9 (INT_MAX 2.147e9)
const long long llinf = 0x3f3f3f3f3f3f3f3fLL; /// 4.56e18 (LLONG_MAX 9.22e18)
const double pi = acos(-1.0);
const double tens[11] = {0.0, 1e-1, 1e-2, 1e-3, 1e-4, 1e-5, 1e-6, 1e-7, 1e-8, 1e-9, 1e-10};
double fgcd(double a, double b) {return fabs(b) > eps ? fgcd(b, fmod(a, b)) : a;}

const int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
const int dirr[8][2] = {1, 0, 1, 1, 0, 1, -1, 1, -1, 0, -1, -1, 0, -1, 1, -1};
const int knight_dir[8][2] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};

INT_MAX = -1u >> 1
gets(s), GC(ch) SS(s), SC(ch)
main() STL
val[i] = ++i
stable_sort(a, a + n);
advance(it, n);
For(i, n) ++it;
size()(int)xx.size()

#pragma comment(linker, "/STACK:102400000,102400000")
ios_base::sync_with_stdio(false);
#define _set() cout.precision(15)//, cout.setf(ios::hex, ios::basefield), cout.setf(ios::showbase)
#define _unset() cout.unsetf(ios::floatfield)//, cout.unsetf(ios::hex), cout.unsetf(ios::showbase)
#define DI(a) _set(), printf(#a" = "), cout << (a) << endl, _unset()
#define DII(a, b) _set(), printf(#a" = "), cout << (a), printf(", "#b" = "), cout << (b) << endl, _unset()
#define DIII(a, b, c) _set(), printf(#a" = "), cout << (a), printf(", "#b" = "), cout << (b), printf(", "#c" = "), cout << (c) << endl, _unset()
#define DIIII(a, b, c, d) _set(), printf(#a" = "), cout << (a), printf(", "#b" = "), cout << (b), printf(", "#c" = "), cout << (c), printf(", "#d" = "), cout << (d) << endl, _unset()
#define DA(a, i, n) For(i, n) printf(#a"[%2d] = ", i), cout << a[i] << endl
#define DAA(a, i, n, j, m) For(i, n) For(j, m) printf(#a"[%2d][%2d] = ", i, j), cout << a[i][j] << endl

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p2;
typedef pair<pair<int, int>, int> p3;
typedef pair<int, pair<int, int> > pi3;
typedef vector<int>::iterator viter;
typedef set<int>::iterator siter;
typedef map<int, int>::iterator miter;
typedef multiset<int>::iterator msiter;
typedef multimap<int, int>::iterator mmter;
typedef priority_queue<int> pq;
typedef priority_queue<int, vector<int>, greater<int> > spq;
#define MT(a, b, c) p3(p2(a, b), c)
#define MT(a, b, c) p3(a, p2(b, c))
#define x first
#define y second
p2 operator + (const p2 &a, const p2 &b) {return p2(a.x + b.x, a.y + b.y);}
p2 operator += (p2 &a, const p2 &b) {return a = a + b;}

const double eps = 1e-8;
const ll mod = ll(1e9) + 7;
inline int Qceil(int x, int y) {return x ? (x - 1) / y + 1 : 0;}
inline double round(double x) {return x > 0.0 ? floor(x + 0.5) : ceil(x - 0.5);}
inline bool okC(char &c) {return c = getchar(), c != 10 && ~c;} //return (c = getchar()) == 32;
inline bool okS(char *s) {return s = gets(s), s && *s;}
ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}
int gcd(int a, int b){return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}
template<class T> inline T _len(T x) {T cnt = 0; for (; x; ++cnt, x /= 10); return cnt;}
template<class T> inline T isSQ(T n) {T tmp = Sqrt(n); return sq(tmp) == n ? tmp : 0;}
inline bool isint(double x) {return fabs(x - round(x)) < eps;}
inline int sign(double x) {return x < -eps ? -1 : x > eps;}
struct comp {bool operator()(const double &a, const double &b)const {return a + eps < b;}};
#define TT int tttt; scanf("%d%*c", &tttt); while(tttt--) // TT{ ... }
#define QQ int qqqq; scanf("%d%*c", &qqqq); while(qqqq--) // QQ{ ... }
#define Pcas() printf("Case %d: ", ++cas)
*/




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
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)
#define pb push_back
#define sq(x) ((x)*(x))
#define Sqrt(n) (long long)round(sqrt((double)n))
#define cl clear


using namespace std;
typedef long long ll;

struct s
{
    ll a,b,c;
}ss[1000000];



bool compare(s l,s r){return l.a<r.a;}
ll chek(ll bit,ll pos){if(bit&(1<<pos)==1)return 1;return 0;}
ll sett(ll bit,ll pos){return bit|(1<<pos);}

ll max_even(ll x)
{
    if(x%2==0)
        return x;
    return x-1;
}

ll min_odd(ll x)
{
    if(x%2==0)
        return x-1;
    return x;
}

string itoaa(ll n)
{
    char x[100]={'\0'};
    ll lim=log10(n);
    for(ll i=lim;i>=0;i--)
    {
        x[i]=(n%10)+'0';
        n=n/10;
    }
    string r=x;
    return r;
}

ll gcd(ll a,ll b)
{
    while(1)
    {
        if(b%a==0)
            return a;
        if(a==1)
            return 1;
        ll x=a;
        a=b%a;
        b=x;
    }
    return 1;
}

ll poww(ll x,ll n)
{
    ll sum=1,i;
    for(i=1;i<=n;i++)
        sum*=x;
    return sum;
}

ll upr_bnd(ll x,ll siz,ll *arr)
{
    return upper_bound(arr,arr+siz,x)-arr;
}

ll lr_bnd(ll x,ll siz,ll *arr)
{
    return lower_bound(arr,arr+siz,x)-arr;
}

ll int_point_distance(ll x1,ll y1,ll x2,ll y2)
{
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

float float_point_distance(float x1,float y1,float x2,float y2)
{
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

void arrin(ll *arr,ll lo,ll hi)
{
    ll i;
    for(i=lo;i<=hi;i++)
        in(arr[i]);
}

ll vis[3000];
vector<ll>v[3000];
ll day[3000],data[3000];

ll bfs(ll u)
{
    queue<ll>q;
    q.push(u);
    vis[u]=0;
    ll d=0;
    while(q.size()>0)
    {
        ll x=q.front();
        q.pop();
        ll sz=v[x].size();
        for(ll i=0;i<sz;i++)
        {
            ll y=v[x][i];
            if(vis[y]==-1)
            {
                q.push(y);
                vis[y]=vis[x]+1;
                data[vis[y]]++;
                d=max(d,vis[y]);
            }
        }
    }
    return d;
}

int main()
{
    ll i,j,k,n,m,x,cnt=0,count=0,t,y,p,q,maxx=0,minn=1<<30,a,b,test=0,len,sum=0;
    //fout;
    while(in(n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            in(a);
            for(j=0;j<a;j++){
                in(x);
                v[i].pb(x);
            }
        }
        in(q);
        for(i=0;i<q;i++)
        {
            in(x);
            mm(vis,-1);
            mm(data,0);
            ll y =bfs(x);
            if(y==0)
                pf("0\n");
            else
            {
                ll r=0,p=0;
                for(j=0;j<=y;j++)
                {
                    if(data[j]>r)
                    {
                        r=data[j];
                        p=j;
                    }
                }
                pf("%lld %lld\n",r,p);
            }
        }
        for(i=0;i<n+5;i++)
            v[i].clear();
    }
    return 0;
}

