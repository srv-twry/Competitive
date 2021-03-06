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
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

/*
    Complexity: O(m logm + n)
    Each vertex can remain in the unvisited set for at max degree number of times.
*/

const int N = 5e5+5;
unordered_set<int> g[N];
unordered_set<int> unvisited;
int n,m;
vector<vi> res;

void bfs(int src) {
    queue<int> q; q.push(src);
    res.back().push_back(src);
    unvisited.erase(src);
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        vi toerase;

        for(int a : unvisited) {
            if(g[curr].find(a) == g[curr].end()) {
                res.back().push_back(a);
                toerase.push_back(a); // erasing while iterating is a bad idea.
                q.push(a);
            }
        }

        for(int a : toerase) {
            unvisited.erase(a);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>m;
    int a, b;
    FOR(i, 0, m) {
        cin>>a>>b; a--; b--;
        g[a].insert(b);
        g[b].insert(a);
    }

    FOR(i, 0, n) unvisited.insert(i);
    FOR(i, 0, n) {
        if(unvisited.find(i) == unvisited.end()) continue;
        res.push_back(vi());
        bfs(i);
    }
    cout<<res.size()<<endl; // no of components.
    for(auto v : res) {
        cout<<v.size()<<" "; // size of this component.
        for(int a : v) {
            cout<<a+1<<" "; // actual elements of this component.
        }
        cout<<endl;
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}