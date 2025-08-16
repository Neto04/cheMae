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

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n; cin>>n;
    ll w, l;
    ll t1, t2; 
    cin>>w>>l>>t1>>t2;
    vector<ll> ganador(n), perdedor(n);
    string equipo = "A";
    for (ll i = 0; i < n; i++) {
        ll a, b; cin>>a>>b;
        ganador[i] = (a-t1)*(a-t1)+(b-t2)*(b-t2);
    }
    for (ll i = 0; i < n; i++) {
        ll a, b; cin>>a>>b;
        perdedor[i] = (a-t1)*(a-t1)+(b-t2)*(b-t2);
    }
    sort(ganador.begin(), ganador.end());
    sort(perdedor.begin(), perdedor.end());

    if (perdedor[0] < ganador[0]) {
        swap(ganador, perdedor);
        equipo = "R";
    }

    ll puntos = 1LL;
    ll extra = lower_bound(ganador.begin(), ganador.end(), perdedor[0])-ganador.begin();
    cout<<equipo<<" "<<puntos+max(0LL,extra-1LL)<<"\n";

    return 0;
}
