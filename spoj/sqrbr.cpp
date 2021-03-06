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

const int N = 20;
int n,k;
bool starter[2*N];
ll dp[2*N][N]; // ways to get j starters out of first i elements.

ll solve(int idx, int openers) {
	ll &ret = dp[idx][openers];
	if (ret >= 0) return ret;
	if (idx == 2*n) return ret = (openers == n);
	ret = 0;
	if((idx - openers) > openers) return ret;
	if (starter[idx])
	{
		ret = solve(idx+1, openers+1);
	} else {
		ret = solve(idx+1, openers) + solve(idx+1, openers+1);
	}
	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int d,tmp; cin>>d;
    while(d--) {
    	cin>>n>>k;
    	memset(starter, false, sizeof(starter));
    	FOR(i, 0, k) {
    		cin>>tmp; tmp--;
    		starter[tmp] = true;
    	}
    	memset(dp, -1, sizeof(dp));
    	cout<<solve(0, 0)<<endl;
    }

    return 0;
}