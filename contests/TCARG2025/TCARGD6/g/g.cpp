// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 0
#define ifd if (debug)




ll mulmod(ll b, ll a, ll m) {return __int128(a) * b % m;}




ll expmod(ll b, ll e, ll m) {
	ll ret = 1;
	while (e) {
		if (e%2) ret = mulmod(ret, b, m);
		b = mulmod(b, b, m);
		e /= 2;
	}
	return ret;
}
bool miller(ll n) { // Determina si n es primo
	if (n < 2) return false;
	for (ll p : {2, 3, 5, 7, 11, 13, 17, 19}) if (n % p == 0) return n == p;
	if (n < 529) return true;
	int s = 0;
	ll d = n - 1;
	while (d % 2 == 0) d /= 2, s ++;
	auto witness = [&](ll a) {
		ll x = expmod(a%n, d, n);
		if (x == 0) return true;
		if (x == 1 or x == n - 1) return false;
		forr(_, 1, s) {
			x = mulmod(x, x, n);
			if (x == n - 1) return false;
			if (x < 2) return true;
		}
		return true;
	};
	for (ll b : {2, 325, 9'375, 28'178, 450'775, 9'780'504, 1'795'265'022})
		if (witness(b)) return false;
	return true;
}
ll rho(ll n) {
	if(n % 2 == 0) return 2;
	ll x = 2, y = 2, d = 1;
	ll c = rand() % n + 1;
	while(d == 1) {
		x = (mulmod(x, x, n) + c) % n;
		y = (mulmod(y, y, n) + c) % n;
		y = (mulmod(y, y, n) + c) % n;
		d = gcd(x - y, n);
	}
	return d == n ? rho(n) : d;
}
void fact(ll n, map<ll, int>& F) { // Agrega los factores de n en F
	if (n == 1) return;
	if (miller(n)) {F[n]++; return;}
	ll q = rho(n); fact(q, F); fact(n / q, F);
}





int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tN=1;
    int tC; cin>>tC;
    while (tC--) {
        ifd cout<<"CASO "<<tN++<<endl;
        ll n; cin>>n;
        if (n==1) {
            cout<<1<<"\n";
            continue;

        }
        map<ll,int> v;
        fact(n, v);
        vector<ll> primos, exp;
        for (auto u:v) {
            primos.pb(u.first);
            exp.pb(u.second);
        }
        
        ifd {
            cout<<"para "<<n<<" su factorizacion prima es:"<<endl;
            for(auto u:primos) cout<<u<<" ";
            cout<<endl;
            for (auto u:exp) cout<<"^"<<u<<" ";
            cout<<endl;
        }
        // nD = num divisores de n
        ll nD=1;
        for(int i=0; i<exp.size(); i++) nD*=(exp[i]+1);
        ifd cout<<"vea que n tiene "<<nD<<" divisores"<<endl;
        // nP = número de primos que dividen n
        int nP=primos.size();
        // pase por todas las combinaciones
        const int numComb=(1<<nP)-1;
        ll ans =0;
        for(int i=0; i<=numComb; i++) {
            ifd {
                cout<<"estoy agarrando "<<i<<endl;
                ifd cout<<"eso equivale a agarrar "<<endl;
                forn(j, nP) if (i&(1<<j)) cout<<primos[j]<<" ";
                cout<<endl;
            }
            ll cD=1;
            ll alpha =1;
            for(int j=0; j<nP; j++) {
                // si tiene agarrado a ese mae
                if (i&(1<<j))  {
                    ifd cout<<"vea que tengo agarrado a "<<(1<<j)<<endl;
                    cD*=(exp[j]+1);
                    ifd cout<<"de donde el denominador ahora es "<<cD<<endl;
                    alpha*=exp[j];
                }
            }
            ifd cout<<"de donde al final me queda ("<<nD<<" / "<<cD<<") * "<<alpha <<" = "<<(nD/cD)*alpha<<endl;
            ans+=(nD/cD)*alpha;
            ifd cout<<"por lo que ahora ans = "<<ans<<endl;
        }
        ans++;
        ifd cout<<"por lo que la respuesta final (sin dividir ) es "<<ans<<endl;
        cout<<ans/2<<endl;

    }


}
