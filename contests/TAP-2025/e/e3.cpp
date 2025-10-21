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

const int N = 2e5+5;
vector<int> adj[N];
ll maes[N];
// turnos, cant
unordered_map<int, ll> d[N];
// cant, turno
pair<ll,int> ans;

vector<ll> shift(N);


void dfs(int v, int p = 0) {
    // turnos, cant
    // para todos los maes adj a v
    for (int u : adj[v]) {
        // si son su papá, siga
        if (u == p) continue;
        // tire dfs de ese mae
        dfs(u, v);
        
        if (d[v].size() < d[u].size()) {
            // sigo sin entender esto
            swap(d[v], d[u]); 
            // pero just in case, swap shifts
            swap(shift[v], shift[u]);
        }
        // 
        for (const pair<int,ll>& x : d[u]) {
            int key = x.first+shift[u]-shift[v];
            d[v][key] += x.second;
        }
    }

    // El nodo 1 no actualiza la respuesta
    if (v == 1) return;

    // Actualizo la respuesta
    d[v][1-shift[v]] += maes[v];
    for (const pair<int,ll>& x : d[v]) {
        int turno = x.first+shift[v]; ll count = x.second;
        if (count > ans.first) {
            ans = {count, turno};
        } else if (count == ans.first) {
            ans = {count, min(turno, ans.second)};
        }
    }
    shift[v]++;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    for (int i = 2; i <= n; i++) {
        cin>>maes[i];
    }
    forn(i, n-1) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = {0, 1e9};

    dfs(1);
    cout<<ans.first<<" "<<ans.second<<"\n";

    return 0;
}
