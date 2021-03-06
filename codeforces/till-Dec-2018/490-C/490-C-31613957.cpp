#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 10000000+10
#define MOD 1000000000+7
#define EPS 1e-7
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
/*----------------------------------------------------------------------*/

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	ll a,b;
	string s;

	cin>>s;

	cin>>a>>b;

	set<int> apos;
	ll value = 0;
	F(i, 0, s.size()){
		value = (value*10 + (s[i]-'0')) % a;
		if (!value)
		{
			apos.insert(i);
		}
	}

	int index = -1;
	ll mult = 1;
	value = 0;

	RF(i, s.size()-1, 0){
		value = ((s[i]-'0')*mult + value)%b;
		mult *=10;
		mult %= b;

		if (!value && s[i]!='0' && apos.find(i-1) != apos.end())
		{
			index = i;
		}
	}

	if (index==-1)
	{
		cout<<"NO";
	}else{
		cout<<"YES\n";
		cout<<s.substr(0,index)<<"\n";
		cout<<s.substr(index);
	}
	return 0;
}