#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int N = 2e5+5;
int arr[N];
bool visited[N], onstack[N];

//return x^y mod p
ll power(ll x,ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

int dfs(int curr, vi &st, bool &cycle, int &ccount) {
    onstack[curr] = true;
    visited[curr] = true;
    st.push_back(curr);

    int ret = 1;
    if(!visited[arr[curr]]) {
        ret += dfs(arr[curr], st, cycle, ccount);
    } else if(onstack[arr[curr]]) {
        cycle = true;
        int tmp = curr, idx = (int) st.size() - 1;
        ccount = 1;
        while(tmp != arr[curr]) {
            ccount++;
            idx--;
            tmp = st[idx];
        }
    }

    onstack[curr] = false;
    st.pop_back();
    return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int n; cin>>n;
    FOR(i, 0, n) {
        cin>>arr[i];
        arr[i]--;
    }
    ll res = 1;
    memset(visited, false, sizeof(visited)); memset(onstack, false, sizeof(onstack));
    FOR(i, 0, n) {
        if(!visited[i]) {
            bool cycle = false;
            vi st; int ccount = 0;
            int sz = dfs(i, st, cycle, ccount);
            // deb(i); deb(ccount); deb(sz);
            if(cycle) {
                res *= (power(2LL, ccount, MOD) - 2 + MOD) % MOD;
                res %= MOD;
            }
            res *= power(2LL, max(0, sz - ccount), MOD);
            res %= MOD;
        }
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}