#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 1000000+10
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

ll x,y,d;

void exteuclid(ll a, ll b){
	if (b==0)
	{
		x = 1;
		y = 0;
		d = a;
		return;
	}

	exteuclid(b, a%b);
	ll x1 = y;
	ll y1 = x - (a/b)*y;
	x = x1;
	y = y1;
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	ll n,c1,c2,n1,n2;

	while(cin>>n && n){
		cin>>c1>>n1>>c2>>n2;
		bool changed= false;

		if ((1.0)*c1/n1>(1.0)*c2/n2)
		{
			ll temp = c2;
			c2 = c1;
			c1 = temp;
			temp = n1;
			n1 = n2;
			n2 = temp;
			changed= true;
		}

		exteuclid(n1,n2);
		if (n%d)
		{
			cout<<"failed\n";
			continue;
		}
		x*=(n/d);
		y*=(n/d);
		

		//The below code produces right answer but gets TLE. 

		// while(y>0){
		// 	x+=(n2/d);
		// 	y-=(n1/d);
		// 	if (y-(n1/d)<0)
		// 	{
		// 		break;
		// 	}
		// }

		long long lower = ceil(1.0 * -x * d / n2), 
                  upper = floor(1.0 * y * d / n1);

      	if (lower > upper) {
            cout<<"failed\n";
			continue;
        }

      	x += n2 / d * upper;
        y -= n1 / d * upper;


		if (changed)
		{
			ll temp = x;
			x = y;
			y = temp;
		}
		cout<<x<<" "<<y<<"\n";
	}
	
	
	
	return 0;
}
