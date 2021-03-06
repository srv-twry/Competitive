#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    ll sum(int idx) {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            ret += bit[idx];
            ret %= MOD;
        }
        return ret;
    }

    // l and r should be given as 0 based indexes.
    ll sum(int l, int r) {
        return (sum(r) - sum(l - 1) + MOD) % MOD;
    }

    // idx as zero based.
    void add(int idx, ll delta) {
        for (++idx; idx < n; idx += idx & -idx) {
            bit[idx] += delta;
            bit[idx] %= MOD;
        }
    }
};

const int N = 1e5+2;
int arr[N];
ll dp[N];

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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    FenwickTree ft(N);
    arr[0]=0;
    memset(dp, 0, sizeof(dp));
    ll sum = 0;
    FOR(i, 1, n+1) {
    	cin>>arr[i];
    	ll val1 = ft.sum(max(arr[i]-2, 0)) + 1;
    	ll val2 = ft.sum(arr[i]+2, N);
    	val1 += val2; val1 %= MOD;
    	dp[i] = val1;
    	ft.add(arr[i], dp[i]);
    	sum += dp[i]; sum %= MOD;
    }
    cout<<(power(2, n, MOD) - sum - 1 + MOD) % MOD;

    return 0;
}