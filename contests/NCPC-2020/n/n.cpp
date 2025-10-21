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

#define debug 1
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

const int N = 1e3+1;
ll valor[N];
// Adj de cada n
vector<pair<int,int>> adj[N];

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int m, n, k; cin>>m>>n>>k;
    for (int i = 1; i <= n; i++) cin>>valor[i];
    forn(i,k) {
        // Arista de u en M a v en N
        int u, v, d; cin>>u>>v>>d;
        adj[v].push_back({u,d});
    }

    set<ll> ans;

    for (int i = 1; i <= n; i++) {
        // Si solo tiene una arista de peso 1 entonces es primo
        if (adj[i].size() == 1 and adj[i][0].second == 1) {
            ans.insert(valor[i]);
            continue;
        }
        map<ll,int> F;
        fact(valor[i], F);
        for (auto x : F) {
            if (x.second > 0) ans.insert(x.first);
        }
    }

    for (ll p : ans) cout<<p<<" ";
    cout<<"\n";

    return 0;
}
