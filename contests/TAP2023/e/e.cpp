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

ll A, S, L, R;

// n: despues, m: antes, d: diff
bool check(ll n, ll m, ll d) {
    ll x = d*(n*(n+1LL)-m*(m+1LL))+(m+n+1LL)*2LL*A;
    return x >= S*2LL;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>A>>S>>L>>R;

    if (A == S) {
        cout<<1LL<<"\n";
        return 0;
    }

    ll ans = 0;
    ll D = max(A-L, R-A);

    // Para cada diferencia
    for (ll d = 1LL; d <= D; d++) {
        // Para cada posible punto inicial
        for (ll l = A; l >= L; l -= d) {

            ll a = 0, b = (R-A)/d+1LL, r = -1LL;
            ll m = (A-l)/d;
            // Busco el candidato a r
            while (a <= b) {
                ll n = a+(b-a)/2LL;
                if (check(n, m, d)) {
                    b = n-1LL; r = n;
                } else {
                    a = n+1LL;
                }
            }

            // No se encontro respuesta
            if (r == -1LL) continue;
            // Si se encontro respuesta
            r = A+r*d;
            if (r > R) continue;
            if ((r-l) % d == 0) {
                ll n = (r-l)/d+1LL;
                if ((n*l + d*(n*(n-1LL))/2LL) == S) {
                    ans++;
                }
            }
        }
    }
    cout<<ans<<"\n";

    return 0;
}
