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

const int N = 1e5+5;
vector<int> adj[N], niveles[N];
ll val[N], val2[N];
int papa[N];

int n;
vector<int> orden;

void dfs(int v, int p = 0, int nivel = 1) {
    papa[v] = p;
    niveles[nivel].push_back(v);
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v, nivel+1);
    }
}

void dfs2(int v, int p = 0) {
    // Cuando llego me pusheo
    orden.push_back(v);
    // Le resto uno a mi valor si no soy la raiz
    if (v != 1) val2[v]--;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs2(u, v);
        orden.push_back(v);
        val2[v] -= val[u];
        forn(i, val2[u]) {
            orden.push_back(u);
            orden.push_back(v);
        }
        //if (orden[orden.size()-1] != v) orden.push_back(v);
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>val[i];
        val2[i] = val[i];
    }
    for (int i = 0; i < n-1; i++) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    // Voy por cada nivel de arriba a abajo
    for (int i = N-1; i > 1; i--) {
        for (int v : niveles[i]) {
            // Si me quede sin nada entonces ya no puedo anular a mi papa
            if (val[v] <= 0) {
                cout<<0<<"\n";
                return 0;
            }
            int p = papa[v];
            val[p] -= val[v];
            val[v] = 0;
        }
    }

    if (val[1] != 0) {
        cout<<0<<"\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) val[i] = val2[i];

    dfs2(1);
    for (int x : orden) cout<<x<<" ";
    cout<<"\n";

    return 0;
}
