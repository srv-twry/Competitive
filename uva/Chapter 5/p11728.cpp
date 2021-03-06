#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 10000+10
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

vll primes;
bitset<SIEVELIM+10> bs;
vll sumfac(SIEVELIM);

void sieve(){
	bs.set();
	bs[0]=0;
	bs[1]=0;

	for (ll i = 2; i < SIEVELIM; i++){
		if (bs[i])
		{
			for (ll j = i*i; j < SIEVELIM; j+=i)
			{
				bs[j]=0;
			}
			primes.push_back((int)i);
		}
	}
}

void findFactors(ll n){
	ll pf_index=0;
	ll temp=n;
	ll pf = primes[pf_index];
	sumfac[n]=1;
	while(pf*pf<=n){
		
		int counter=0;
		while(n%pf == 0){n/=pf;counter++;}
		if (counter)
		{
			sumfac[temp]*= ((ll)pow((double)pf, counter + 1.0) - 1) / (pf - 1);
		}
		
		pf = primes[++pf_index];
	}
	if (n!=1)
	{
		sumfac[temp]*= ((ll)pow((double)n, 2.0) - 1) / (n - 1);
	}
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	sieve();
	F(i, 1, SIEVELIM){
		findFactors(i);
	}
	int s,tn=1;

	while(cin>>s && s){
		ll ans=-1;
		F(i, 0, SIEVELIM){
			if (sumfac[i]==s)
			{
				ans = i;
			}
		}
		cout<<"Case "<<tn++<<": ";
		cout<<ans;
		cout<<"\n";
	}
	return 0;
}