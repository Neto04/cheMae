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

ll n, m;

vector<vector<bool>> adj;
vector<pair<int,int>> grados;
vector<int> cuentaGrado;
vector<pair<int,int>> aristas;

bool check(ll x) {
    // BETO TODO COSTA RICA CON USTED
    aristas.clear();
    aristas.resize(0);
    vector<vector<bool>> copia = adj;
    for (int i = 0; i < n; i++) {
        ii siguiente = grados[i];
        int grado = siguiente.first, nodo = siguiente.second;
        if (grado < x) break;
        vector<ii> meRegalan;
        for (int j = 1; j <= n; j++) {
            if (copia[j][i]) meRegalan.push_back({cuentaGrado[j], j}); 
        }
        sort(meRegalan.begin(), meRegalan.end());
        for (int k = 0; k < grado-x; k++) {
            if (k >= meRegalan.size()) {
                return false;
            }
            aristas.push_back({meRegalan[k].second, k});
            copia[meRegalan[k].second][i] = 0;
        }
    }
    return true;
}

// busca min max cantidad de regalos que puede dar c/u
ll search() {
    // l es el max mae que de fijo no sirve, r el min que de fijo sí 
    ll l=0, r=n;
    while (r-l>1) {
        ll c=(r-l)/2+l;
        if (check(c)) r=c;
        else l=c;
    }
    return r;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    adj.assign(n+1, vector<bool>(n+1));
    cuentaGrado.resize(n+1);
    for (ll i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        adj[a][b] = 1;
        adj[b][a] = 1;
        cuentaGrado[a]++;
        cuentaGrado[b]++;
    }

    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (adj[i][j]) count++;
        }
        grados.push_back({count,i});
    }

    sort(grados.begin(), grados.end());
    reverse(grados.begin(), grados.end());

    ll ans = search();
    cout<<ans<<"\n";

    for (auto x : aristas) cout<<x.first<<" "<<x.second<<" "<<"\n";

    return 0;
}
