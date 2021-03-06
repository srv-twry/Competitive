#include <iostream>
using namespace std;

typedef long long ll;

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

int main() {
	
	// your code here
	int t;
    cin>>t;

    int a,b;
    while(t--){
        cin>>a>>b;
        cout<<power(a,b,10)<<"\n";
    }

	return 0;
}